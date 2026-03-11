Route130_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_OnTransition
	.byte 0

Route130_OnTransition:
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route130_EventScript_CheckSetAbnormalWeather
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, Route130_EventScript_SetMirageIslandLayout
@ Mirage Island isn't currently visible, hide any objects on the island. Only the first flag is actually associated with anything.
	setflag FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setmaplayoutindex LAYOUT_ROUTE130
	end

Route130_EventScript_SetMirageIslandLayout::
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
	end

Route130_EventScript_CheckSetAbnormalWeather::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

Route130_EventScript_Rodney::
	trainerbattle_single TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat
	msgbox Route130_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Katie::
	trainerbattle_single TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat
	msgbox Route130_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Santiago::
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat
	msgbox Route130_Text_SantiagoPostBattle, MSGBOX_AUTOCLOSE
	end





/*
VAR_ROUTE130_STATE
0 = default, hasn't spoken yet; talks about mirage island, asks for RUBY item; set 1
1 = "have you found the RUBY yet?", gives hint;
when find RUBY item, set 2
2 = trigger scripts
3 = takes RUBY item, does spell, doesnt work, teleports away, teleports back, asks for SAPPHIRE item; set 4
4 = "have you found SAPPHIRE yet?"
when find SAPPHIRE item, set 5
5 = takes RUBY item, does spell, works, sets flag FORCE_MIRAGE_ISLAND; set 6
6 = applymovement NPC up to Mirage Island, make him disappear, set flag hiding NPC
7 = temporary, at top of island, make NPC walk off and disappear, set flag hiding NPC, set 8
8 = final state, for future use elsewhere possibly bringing back Mirage Man!
9 = when asked to help, saying no sets it as this to avoid retelling the same opening prompt
*/



EventScript_MirageMan_Start::
	goto_if_unset FLAG_HIDE_MIRAGE_MAN, EventScript_MirageMan_Intro
	end
	
EventScript_MirageMan_Intro::
	lockall
	faceplayer
	compare VAR_ROUTE130_STATE, 0
	goto_if_eq EventScript_MirageMan_0a
	compare VAR_ROUTE130_STATE, 1
	goto_if_eq EventScript_MirageMan_1
//state 2 activates with a trigger
//state 3 is only temporary
	compare VAR_ROUTE130_STATE, 4
	goto_if_eq EventScript_MirageMan_4
//state 5 activates with a trigger
//state 6 is only temporary
//state 7 activates with a trigger
	compare VAR_ROUTE130_STATE, 9
	goto_if_eq EventScript_MirageMan_0b
//state 5 activates with a trigger
//state 6 set at the end
	end

EventScript_MirageMan_0a::
	msgbox Text_MirageMan_0a, MSGBOX_DEFAULT
	goto EventScript_MirageMan_0b

EventScript_MirageMan_0b::
	msgbox Text_MirageMan_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, EventScript_MirageMan_No
	msgbox Text_MirageMan_0b, MSGBOX_DEFAULT
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Text_MirageMan_0c, MSGBOX_DEFAULT
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	msgbox Text_MirageMan_0d, MSGBOX_DEFAULT
	setvar VAR_ROUTE130_STATE, 1
	releaseall
	end
	
Text_MirageMan_0a:
	.string "Have you ever heard the theory of\n"
	.string "MIRAGE ISLAND?\p"
	.string "Stories tell that a hidden island lies at\n"
	.string "the bottom of the ocean.\p"
	.string "No-one has ever seen this mysterious\n"
	.string "island before.\p"
	.string "But stories also tell of a magick spell\n"
	.string "that can force it to reveal itself.$"

Text_MirageMan_Ask:
	.string "Would you be willing to help me?$"

EventScript_MirageMan_No::
	setvar VAR_ROUTE130_STATE, 9
	msgbox Text_MirageMan_No, MSGBOX_DEFAULT
	releaseall
	end

Text_MirageMan_No:
	.string "Aw, that's disappointing.$"

Text_MirageMan_0b:
	.string "I've learned the magick spell that\n"
	.string "can make the island show, but a\l"
	.string "special mineral is needed.\p"
	.string "A RUBY.$"

Text_MirageMan_0c:
	.string "I've heard rumours that there's\n"
	.string "hidden passages and chambers in\l"
	.string "ROUTE 103 but I can't find any.$"

Text_MirageMan_0d:
	.string "Could you go investigate and see if\n"
	.string "it leads to finding a RUBY.$"


//when VAR is set to 1
EventScript_MirageMan_1::
	lockall
	msgbox Text_MirageMan_1, MSGBOX_DEFAULT
	releaseall
	end
	
Text_MirageMan_1:
	.string "Have you found the RUBY?\p"
	.string "… {PAUSE 0x0F}{PAUSE 0x0F}… {PAUSE 0x0F}{PAUSE 0x0F}… {PAUSE 0x0F}\p"
	.string "You haven't found it yet?\n"
	.string "Keep looking.$"


//triggers active when VAR is set to 2
EventScript_MirageMan_Trigger0::
	lockall
	setvar VAR_0x8008, 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox Text_MirageMan_2a, MSGBOX_DEFAULT
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_2b, MSGBOX_DEFAULT
	removeitem ITEM_RUBY
	msgbox Text_MirageMan_GiveRuby, MSGBOX_DEFAULT
	playfanfare SE_SUCCESS
	waitfanfare
	msgbox Text_MirageMan_2c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_0
	waitmovement 0
	goto EventScript_MirageMan_DidntWork_1
	end

EventScript_MirageMan_Trigger1::
	lockall
	setvar VAR_0x8008, 1
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Text_MirageMan_2a, MSGBOX_DEFAULT
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_2b, MSGBOX_DEFAULT
	removeitem ITEM_RUBY
	msgbox Text_MirageMan_GiveRuby, MSGBOX_DEFAULT
	playfanfare SE_SUCCESS
	waitfanfare
	msgbox Text_MirageMan_2c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_1
	waitmovement 0
	goto EventScript_MirageMan_DidntWork_1
	end

EventScript_MirageMan_Trigger2::
	lockall
	setvar VAR_0x8008, 2
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceUp
	waitmovement 0
	msgbox Text_MirageMan_2a, MSGBOX_DEFAULT
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_2b, MSGBOX_DEFAULT
	removeitem ITEM_RUBY
	msgbox Text_MirageMan_GiveRuby, MSGBOX_DEFAULT
	msgbox Text_MirageMan_2c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_2
	waitmovement 0
	goto EventScript_MirageMan_DidntWork_1
	end

EventScript_MirageMan_Trigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceRight
	waitmovement 0
	msgbox Text_MirageMan_2a, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_2b, MSGBOX_DEFAULT
	removeitem ITEM_RUBY
	msgbox Text_MirageMan_GiveRuby, MSGBOX_DEFAULT
	msgbox Text_MirageMan_2c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_3
	waitmovement 0
	setvar VAR_ROUTE130_STATE, 3
	goto EventScript_MirageMan_DidntWork_1
	end

Text_MirageMan_2a:
	.string "Hey, how goes the search?$"

Text_MirageMan_2b:
	.string "You found it!\p"
	.string "Wow, well done.$"
	
Text_MirageMan_GiveRuby:
	.string "{PLAYER} handed the RUBY over.$"

Text_MirageMan_2c:
	.string "Now, lets try the magick spell.\p"
	.string "Stand back!$"

Movement_Setup_Player_0:
	walk_down
	face_up
	step_end
Movement_Setup_Player_1:
	walk_down
	walk_down
	walk_right
	face_up
	step_end
Movement_Setup_Player_2:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	face_up
	step_end
Movement_Setup_Player_3:
	walk_down
	walk_down
	walk_left
	face_up
	step_end

Movement_MirageMan_Delay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end

Movement_MirageMan_LookAround:
	face_right
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_down
	delay_16
	step_end


//when VAR is 3
EventScript_MirageMan_DidntWork_1::
	message Text_MirageMan_Spell
	waitmessage
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_Delay
	waitmovement 0
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_LookAround
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_QuestionMark
	waitmovement 0
	msgbox Text_MirageMan_Spell_DidntWork, MSGBOX_DEFAULT
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_FlyUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_MovePlayerToMirageMan
	waitmovement 0
	msgbox Text_MirageMan_3a, MSGBOX_DEFAULT
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceRight
	waitmovement 0
	msgbox Text_MirageMan_3b, MSGBOX_DEFAULT
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	msgbox Text_MirageMan_3c, MSGBOX_DEFAULT
	setvar VAR_ROUTE130_STATE, 4
	releaseall
	end
	
Text_MirageMan_Spell:
	.string "Eleka nahmen nahmen,\n"
	.string "ah tum ah tum,\l"
	.string "eleka nahmen.$"

Text_MirageMan_Spell_DidntWork:
	.string "Hmmm… It didn't work!\p"
	.string "Let me think … {PAUSE 0x0F}{PAUSE 0x0F}… {PAUSE 0x0F}{PAUSE 0x0F}…\p"
	.string "I'll be right back.$"

Movement_MirageMan_FlyUp:
	fly_up
	delay_16
	delay_16
	delay_16
	delay_16
	fly_down
	step_end

Movement_MovePlayerToMirageMan:
	walk_up
	face_up
	step_end

Text_MirageMan_3a:
	.string "So I found out what went wrong.\p"
	.string "There's a second item needed to work\n"
	.string "alongside the RUBY.\p"
	.string "We need a SAPPHIRE too.$"

Text_MirageMan_3b:
	.string "Rumour has it that some have been\n"
	.string "found in VICTORY ROAD.$"

Text_MirageMan_3c:
	.string "You can do it!$"


// when VAR is 4
EventScript_MirageMan_4::
	lockall
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FacePlayer
	msgbox Text_MirageMan_4, MSGBOX_DEFAULT
	releaseall
	end
	
Text_MirageMan_4:
	.string "Have you found a SAPPHIRE?\p"
	.string "… {PAUSE 0x0F}{PAUSE 0x0F}… {PAUSE 0x0F}{PAUSE 0x0F}… {PAUSE 0x0F}\p"
	.string "You haven't found it yet?\n"
	.string "Keep searching, you can do it!$"


//triggers active when VAR is 5
EventScript_MirageMan_Trigger4::
	lockall
	setvar VAR_0x8008, 4
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox Text_MirageMan_5a, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_5b, MSGBOX_DEFAULT
	removeitem ITEM_SAPPHIRE
	msgbox Text_MirageMan_GiveSapphire, MSGBOX_DEFAULT
	msgbox Text_MirageMan_5c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_0
	waitmovement 0
	setvar VAR_ROUTE130_STATE, 6
	goto EventScript_MirageMan_IslandRefresh
	end

EventScript_MirageMan_Trigger5::
	lockall
	setvar VAR_0x8008, 5
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Text_MirageMan_5a, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_5b, MSGBOX_DEFAULT
	removeitem ITEM_SAPPHIRE
	msgbox Text_MirageMan_GiveSapphire, MSGBOX_DEFAULT
	msgbox Text_MirageMan_5c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_1
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_ROUTE130_STATE, 6
	goto EventScript_MirageMan_IslandRefresh
	end

EventScript_MirageMan_Trigger6::
	lockall
	setvar VAR_0x8008, 6
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceUp
	waitmovement 0
	msgbox Text_MirageMan_5a, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_5b, MSGBOX_DEFAULT
	removeitem ITEM_SAPPHIRE
	msgbox Text_MirageMan_GiveSapphire, MSGBOX_DEFAULT
	msgbox Text_MirageMan_5c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_2
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_ROUTE130_STATE, 6
	goto EventScript_MirageMan_IslandRefresh
	end

EventScript_MirageMan_Trigger7::
	lockall
	setvar VAR_0x8008, 7
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceRight
	waitmovement 0
	msgbox Text_MirageMan_5a, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_5b, MSGBOX_DEFAULT
	removeitem ITEM_SAPPHIRE
	msgbox Text_MirageMan_GiveSapphire, MSGBOX_DEFAULT
	msgbox Text_MirageMan_5c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_3
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_ROUTE130_STATE, 6
	goto EventScript_MirageMan_IslandRefresh
	end

Text_MirageMan_5a:
	.string "Hey, how goes the search for a\n"
	.string "SAPPHIRE?$"

Text_MirageMan_5b:
	.string "Wow, you found one!\p"
	.string "Congratulations.$"

Text_MirageMan_GiveSapphire:
	.string "{PLAYER} handed the SAPPHIRE over.$"

Text_MirageMan_5c:
	.string "Now, lets try the magick spell again.\p"
	.string "Stand back!$"

EventScript_MirageMan_IslandRefresh::
	message Text_MirageMan_Spell
	waitmessage
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_Delay
	waitmovement 0
//fade & warp to reload map
	fadescreen FADE_TO_WHITE
	fadescreen FADE_FROM_WHITE
	fadescreen FADE_TO_WHITE
	setflag FLAG_FORCE_MIRAGE_ISLAND
	warpsilent MAP_ROUTE130, 45, 29
	fadescreen FADE_FROM_WHITE
	setvar VAR_ROUTE130_STATE, 7
	end



//triggers active when VAR is 7
EventScript_MirageMan_Trigger8::
	lockall
	setvar VAR_0x8008, 8
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceDown
	waitmovement 0
	call EventScript_MirageMan_IslandAppears
	goto EventScript_MirageMan_Follow8
	end

EventScript_MirageMan_Trigger9::
	lockall
	setvar VAR_0x8008, 9
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceLeft
	waitmovement 0
	call EventScript_MirageMan_IslandAppears
	goto EventScript_MirageMan_Follow9
	end

EventScript_MirageMan_Trigger10::
	lockall
	setvar VAR_0x8008, 10
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceUp
	waitmovement 0
	call EventScript_MirageMan_IslandAppears
	goto EventScript_MirageMan_Follow10
	end

EventScript_MirageMan_Trigger11::
	lockall
	setvar VAR_0x8008, 11
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_FaceRight
	waitmovement 0
	call EventScript_MirageMan_IslandAppears
	goto EventScript_MirageMan_Follow11
	end
	
EventScript_MirageMan_IslandAppears::
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_Appears1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MIRAGE_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Text_MirageMan_ItWorked, MSGBOX_DEFAULT
	playse SE_CONTEST_HEART
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_Appears2
	waitmovement 0
	msgbox Text_MirageMan_ComeOn, MSGBOX_DEFAULT
	waitmessage
	closemessage
	return

Movement_MirageMan_Appears1:
	delay_16
	walk_in_place_left
	delay_4
	walk_in_place_up
	delay_4
	walk_in_place_right
	delay_4
	face_player
	step_end

Text_MirageMan_ItWorked:
	.string "IT WORKED!$"

Movement_MirageMan_Appears2:
	emote_heart
	step_end

Text_MirageMan_ComeOn:
	.string "Come on, I wanna see what it's like.$"


// when VAR is 7
EventScript_MirageMan_Follow8::
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_MoveToSteps8_10_11
	applymovement LOCALID_PLAYER, Movement_MirageMan_MovePlayerToSteps8
	waitmovement 0
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_LookAroundSteps
	waitmovement 0
	goto EventScript_MirageMan_FollowUpSteps
	end

EventScript_MirageMan_Follow9::
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_MoveToSteps9
	applymovement LOCALID_PLAYER, Movement_MirageMan_MovePlayerToSteps9
	waitmovement 0
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_LookAroundSteps
	waitmovement 0
	goto EventScript_MirageMan_FollowUpSteps
	end

EventScript_MirageMan_Follow10::
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_MoveToSteps8_10_11
	applymovement LOCALID_PLAYER, Movement_MirageMan_MovePlayerToSteps10
	waitmovement 0
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_LookAroundSteps
	waitmovement 0
	goto EventScript_MirageMan_FollowUpSteps
	end

EventScript_MirageMan_Follow11::
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_MoveToSteps8_10_11
	applymovement LOCALID_PLAYER, Movement_MirageMan_MovePlayerToSteps11
	waitmovement 0
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_LookAroundSteps
	waitmovement 0
	goto EventScript_MirageMan_FollowUpSteps
	end

EventScript_MirageMan_FollowUpSteps::
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_MoveManToTop
	applymovement LOCALID_PLAYER, Movement_MirageMan_MovePlayerToTop
	waitmovement 0
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_LookAroundTop
	waitmovement 0
	goto EventScript_MirageMan_End
	end


Movement_MirageMan_MoveToSteps8_10_11:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

Movement_MirageMan_MoveToSteps9:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

Movement_MirageMan_MovePlayerToSteps8:
	delay_16
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_MirageMan_MovePlayerToSteps9:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_MirageMan_MovePlayerToSteps10:
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_MirageMan_MovePlayerToSteps11:
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_MirageMan_LookAroundSteps:
	delay_16
	delay_16
	delay_16
	walk_in_place_left
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_right
	delay_16
	walk_in_place_up
	delay_16
	delay_4
	step_end

Movement_MirageMan_MoveManToTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_right
	step_end

Movement_MirageMan_MovePlayerToTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

Movement_MirageMan_LookAroundTop:
	delay_16
	delay_16
	delay_16
	walk_in_place_left
	delay_16
	walk_in_place_up
	delay_16
	walk_in_place_right
	delay_16
	walk_in_place_left
	delay_16
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	delay_16
	walk_in_place_left
	delay_16
	walk_in_place_up
	delay_16
	walk_in_place_right
	delay_16
	walk_in_place_left
	delay_16
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	face_right
	step_end

EventScript_MirageMan_End::
	msgbox Text_MirageMan_End, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_MIRAGE_MAN, Movement_MirageMan_Leaves
	waitmovement 0
	removeobject LOCALID_MIRAGE_MAN
	setflag FLAG_HIDE_MIRAGE_MAN	
	setvar VAR_ROUTE130_STATE, 8
	releaseall
	end

Text_MirageMan_End:
	.string "Wow, this place looks amazing.\p"
	.string "I'm gonna go home and empty my bag in\n"
	.string "case I find any treasures!\p"
	.string "...{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}\p"
	.string "{PLAYER}, I owe you a lot for all that\n"
	.string "you've done!\p"
	.string "I really hope we get to meet again\n"
	.string "somewhere.$"

Movement_MirageMan_Leaves:
	delay_16
	delay_16
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end



//debug NPCs giving item and set state
EventScript_Debug_Ruby::
	lock
	additem ITEM_RUBY
	setvar VAR_ROUTE130_STATE, 2
	msgbox Text_Debug_Ruby, MSGBOX_NPC
	end

Text_Debug_Ruby: 
	.string "GIVEN RUBY, SET STATE 2$"


EventScript_Debug_Sapphire::
	lock
	additem ITEM_SAPPHIRE
	setvar VAR_ROUTE130_STATE, 5
	msgbox Text_Debug_Sapphire, MSGBOX_NPC
	end

Text_Debug_Sapphire: 
	.string "GIVEN SAPPHIRE, SET STATE 5$"

