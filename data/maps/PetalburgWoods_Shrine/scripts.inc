PetalburgWoods_Shrine_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_Shrine_MapScripts_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PetalburgWoods_Shrine_MapScripts_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PetalburgWoods_Shrine_MapScripts_OnTransition
	.byte 0


PetalburgWoods_Shrine_MapScripts_OnTransition:
	call_if_eq VAR_LEAF_STATE, 3, PetalburgWoods_Shrine_Show1Hide2
	call_if_ge VAR_LEAF_STATE, 4, PetalburgWoods_Shrine_Hide1Show2
	call_if_ge VAR_LEAF_STATE, 7, PetalburgWoods_Shrine_Hide1Hide2
	end

PetalburgWoods_Shrine_Show1Hide2:
	clearflag FLAG_HIDE_SHRINE_LEAF1
	removeobject LOCALID_SHRINE_LEAF2
	setflag FLAG_HIDE_SHRINE_LEAF2
	return

PetalburgWoods_Shrine_Hide1Show2:
	removeobject LOCALID_SHRINE_LEAF1
	setflag FLAG_HIDE_SHRINE_LEAF1
	clearflag FLAG_HIDE_SHRINE_LEAF2
	return

PetalburgWoods_Shrine_Hide1Hide2:
	removeobject LOCALID_SHRINE_LEAF1
	setflag FLAG_HIDE_SHRINE_LEAF1
	removeobject LOCALID_SHRINE_LEAF2
	setflag FLAG_HIDE_SHRINE_LEAF2
	return


PetalburgWoods_Shrine_EventScript_Trigger_Leaf_Var3::
	lock
	applymovement LOCALID_SHRINE_LEAF1, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto PetalburgWoods_Shrine_EventScript_Leaf1_Start

PetalburgWoods_Shrine_EventScript_Leaf1_Start::
	lock
	faceplayer
	msgbox PetalburgWoods_Shrine_Text_Leaf_CutDown, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_SHRINE_LEAF1, PetalburgWoods_Shrine_Movement_LeafToShrine
	waitmovement 0
	setvar VAR_LEAF_STATE, 4
	removeobject LOCALID_SHRINE_LEAF1
	setflag FLAG_HIDE_SHRINE_LEAF1
	clearflag FLAG_HIDE_SHRINE_LEAF2
	release
	end

PetalburgWoods_Shrine_Text_Leaf_CutDown:
	.string "LEAF: Oh, {PLAYER}.\p"
	.string "They've cut down a lot of the forest\n"
	.string "already, I hope they haven't ruined\l"
	.string "any POKéMON habitats.\p"
	.string "Let's go see if there's any damage.$"

PetalburgWoods_Shrine_Movement_LeafToShrine:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PetalburgWoods_Shrine_EventScript_Leaf2_AtShrine::
	lock
	faceplayer
	goto_if_eq VAR_LEAF_STATE, 5, PetalburgWoods_Shrine_EventScript_Leaf_AtShrine2
	goto_if_eq VAR_LEAF_STATE, 6, PetalburgWoods_Shrine_EventScript_Leaf_GoingHome
	msgbox PetalburgWoods_Shrine_Text_Leaf_AtShrine, MSGBOX_DEFAULT 
	setvar VAR_LEAF_STATE, 5
	applymovement LOCALID_SHRINE_LEAF2, Common_Movement_FaceUp
	release
	end

PetalburgWoods_Shrine_Text_Leaf_AtShrine:
	.string "LEAF: It's a shrine!\p"
	.string "It looks just like the shrine in ILEX\n"
	.string "FOREST in JOHTO.\p"
	.string "That one was put there in honor of\n"
	.string "the forest's protector.\p"
	.string "...\p"
	.string "I wonder why there is an identical\n"
	.string "shrine here in HOENN?$"

PetalburgWoods_Shrine_EventScript_Leaf_AtShrine2:
	msgbox PetalburgWoods_Shrine_Text_Leaf_AtShrine2, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_Shrine_Text_Leaf_AtShrine2:
	.string "I wonder why there is an identical\n"
	.string "shrine here in HOENN?$"

PetalburgWoods_Shrine_EventScript_Shrine_Sign::
	lock
	goto_if_set FLAG_CELEBI_SHRINE_WON, PetalburgWoods_Shrine_EventScript_ShrineCelebiWon
	applymovement LOCALID_SHRINE_LEAF2, Common_Movement_FaceUp
	setflag FLAG_SYS_NO_CATCHING
	msgbox PetalburgWoods_Shrine_Text_Leaf_ShrineText, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_CELEBI, 0
	waitmoncry
	setwildbattle SPECIES_CELEBI, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods_Shrine_EventScript_CelebiWon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods_Shrine_EventScript_CelebiWon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_Shrine_EventScript_CelebiWon
	release
	end

PetalburgWoods_Shrine_EventScript_ShrineCelebiWon:
	goto_if_ge VAR_LEAF_STATE, 20, PetalburgWoods_Shrine_EventScript_ShrineCelebiFinal
	msgbox PetalburgWoods_Shrine_Text_Leaf_ShrineCelebiWon, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_Shrine_Text_Leaf_ShrineCelebiWon:
	.string "It's an identical replica of the ILEX\n"
	.string "FOREST shrine in JOHTO.$"

//if VAR_LEAF_STATE=20
PetalburgWoods_Shrine_EventScript_ShrineCelebiFinal:
	release
	end

PetalburgWoods_Shrine_EventScript_CelebiWon:
	lock
	delay 15
	applymovement LOCALID_SHRINE_LEAF2, PetalburgWoods_Shrine_Movement_Saw_Celebi
	waitmovement 0
	msgbox PetalburgWoods_Shrine_Text_Leaf_WeSawCelebi, MSGBOX_DEFAULT
	setflag FLAG_CELEBI_SHRINE_WON
	clearflag FLAG_SYS_NO_CATCHING
	setvar VAR_LEAF_STATE, 6
	release
	end

PetalburgWoods_Shrine_Movement_Saw_Celebi:
	face_up
	emote_heart
	step_end

PetalburgWoods_Shrine_Text_Leaf_WeSawCelebi:
	.string "That was a CELEBI!\p"
	.string "...\p"
	.string "I'm glad I was recording this on my\n"
	.string "POKéGEAR.\p"
	.string "PROF.OAK will love to see this.$"

PetalburgWoods_Shrine_Text_Leaf_ShrineText:
	.string "It's an identical replica of the ILEX\n"
	.string "FOREST shrine in JOHTO.\p"
	.string "...\p"
	.string "There is a faint cry from inside.$"

PetalburgWoods_Shrine_EventScript_Leaf_GoingHome:
	lock
	faceplayer
	msgbox PetalburgWoods_Shrine_Text_Leaf_GoingHome, MSGBOX_DEFAULT
	waitmessage
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, PetalburgWoods_Shrine_EventScript_Leaf_GoingHomeN
	call_if_eq VAR_FACING, DIR_SOUTH, PetalburgWoods_Shrine_EventScript_Leaf_GoingHomeSWE
	call_if_eq VAR_FACING, DIR_WEST, PetalburgWoods_Shrine_EventScript_Leaf_GoingHomeSWE
	call_if_eq VAR_FACING, DIR_EAST, PetalburgWoods_Shrine_EventScript_Leaf_GoingHomeSWE
	setvar VAR_LEAF_STATE, 7
	removeobject LOCALID_SHRINE_LEAF2
	setflag FLAG_HIDE_SHRINE_LEAF2
	release
	end

PetalburgWoods_Shrine_Text_Leaf_GoingHome:
	.string "LEAF: {PLAYER}, I'm so confused\n"
	.string "about how to feel.\p"
	.string "I came here worried about the forest\n"
	.string "being cut down, and I leave with\l"
	.string "having seen the Legendary POKéMON\l"
	.string "CELEBI in one of it's habitats.\p"
	.string "I think I understand why it didn't\n"
	.string "want to be captured.\p"
	.string "It wants to stay and protect this\n"
	.string "part of the forest now that it's\l"
	.string "been partly cut down.\p"
	.string "...\p"
	.string "I'm going to go home to PALLET TOWN\n"
	.string "for a while.\p"
	.string "{PLAYER}, I hope our paths cross\n"
	.string "again somewhere.$"

PetalburgWoods_Shrine_EventScript_Leaf_GoingHomeN:
	applymovement LOCALID_SHRINE_LEAF2, PetalburgWoods_Shrine_Movement_Leaf_GoingHomeN
	waitmovement 0
	return
PetalburgWoods_Shrine_EventScript_Leaf_GoingHomeSWE:
	applymovement LOCALID_SHRINE_LEAF2, PetalburgWoods_Shrine_Movement_Leaf_GoingHomeSWE
	waitmovement 0
	return

PetalburgWoods_Shrine_Movement_Leaf_GoingHomeSWE:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
PetalburgWoods_Shrine_Movement_Leaf_GoingHomeN:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
