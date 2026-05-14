NavelRock_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Exterior_OnTransition
	.byte 0

NavelRock_Exterior_OnTransition:
	setflag FLAG_ARRIVED_AT_NAVEL_ROCK
	end


// define flag
// FLAG_DEFEATED_BLUE_NAVAL

//define var
// VAR_BLUE_STATE

//blue
NavalRock_Exterior_EventScript_Blue_Start::
	goto_if_eq VAR_BLUE_STATE, 1, NavalRock_Exterior_EventScript_Blue_Ask
	lock
	msgbox NavalRock_Exterior_Text_Blue1, MSGBOX_DEFAULT
	emote LOCALID_BLUE_NAVALEXT, EXCLAM
	faceplayer
	msgbox NavalRock_Exterior_Text_Blue2, MSGBOX_DEFAULT
	goto NavalRock_Exterior_EventScript_Blue_Ask

NavalRock_Exterior_EventScript_Blue_Ask:
	faceplayer
	msgbox NavalRock_Exterior_Text_Blue_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NavalRock_Exterior_EventScript_Blue_Refuse
	goto NavalRock_Exterior_EventScript_StartBlueBattle

NavalRock_Exterior_EventScript_Blue_Refuse:
	setvar VAR_BLUE_STATE, 1
	msgbox NavalRock_Exterior_Text_Blue_Refuse, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE_NAVALEXT, Common_Movement_FaceUp
	release
	end

NavalRock_Exterior_EventScript_StartBlueBattle:
	trainerbattle_double TRAINER_856, NavalRock_Exterior_Text_Blue_Intro, NavalRock_Exterior_Text_Blue_Defeat, NavalRock_Exterior_Text_Blue_NeedTwoMons, NavalRock_Exterior_EventScript_Blue_Defeated, NO_MUSIC
	release
	end

NavalRock_Exterior_EventScript_Blue_Defeated:
	msgbox NavalRock_Exterior_Text_Blue_Post, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE_NAVALEXT, Common_Movement_WalkUp
	playse SE_EXIT
	waitse
	removeobject LOCALID_BLUE_NAVALEXT
	setflag FLAG_DEFEATED_BLUE_NAVAL
	setvar VAR_BLUE_STATE, 2
	release
	end

NavalRock_Exterior_Text_Blue1:
	.string "... it looks like a normal cave...$"

NavalRock_Exterior_Text_Blue2:
	.string "BLUE: Oh, sorry dude.\n"
	.string "I was too focused on this cave.\p"
	.string "The name's BLUE.\p"
	.string "See, I used to be Champion in KANTO,\n"
	.string "but I lost to this punk called RED.\p"
	.string "So now I'm training to take over the\n"
	.string "VIRIDIAN GYM and I came here to see\l"
	.string "if there was any strong POKéMON I\l"
	.string "could train against.\p"
	.string "...\p"
	.string "You're {PLAYER}?\n"
	.string "You're the new Champion of the HOENN\l"
	.string "League, aren't you?$" 

NavalRock_Exterior_Text_Blue_Ask:
	.string "Wanna do a double battle with me?$"

NavalRock_Exterior_Text_Blue_Refuse:
	.string "Aw damn!\p"
	.string "I'll be here if you change your mind.$"

NavalRock_Exterior_Text_Blue_Intro:
	.string "Let's fight!$"
	
NavalRock_Exterior_Text_Blue_Defeat:
	.string "Damn, lost again!$"

NavalRock_Exterior_Text_Blue_NeedTwoMons:
	.string "... dude, you need two POKéMON for a\n"
	.string "double battle!$"

NavalRock_Exterior_Text_Blue_Post:
	.string "It's OK that I lost.\n"
	.string "As a Gym Leader, I know there are\p"
	.string "some Trainers who will beat me.\n"
	.string "I've come to accept that.\p"
	.string "...\p"
	.string "And on that note, I'm gonna go train.\p"
	.string "Smell ya later!$"



