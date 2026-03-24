AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	goto_if_set FLAG_RECEIVED_RUBY, AlteringCave_EventScript_End
	goto_if_ne VAR_ROUTE130_STATE, 1, AlteringCave_EventScript_HideRuby
	end

AlteringCave_EventScript_End::
	end

AlteringCave_EventScript_HideRuby::
	removeobject LOCALID_ALTERINGCAVE_RUBY
	setflag FLAG_TEMP_1
	end

AlteringCave_EventScript_Trigger1::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_BANG
	waitse
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement
	msgbox AlteringCave_Text_FallingNoise, MSGBOX_DEFAULT
	releaseall
	end

AlteringCave_Text_FallingNoise:
	.string "A loud noise echoed through the cave.\p"
	.string "It sounds like something dropped and\n"
	.string "hit the ground.$"


AlteringCave_EventScript_RubyAsk::
	lock
	msgbox AlteringCave_Text_RubyAsk, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq AlteringCave_EventScript_No
	giveitem ITEM_RUBY
	msgbox AlteringCave_Text_ReceivedRuby, MSGBOX_DEFAULT
	removeobject LOCALID_ALTERINGCAVE_RUBY
	setflag FLAG_RECEIVED_RUBY
	setvar VAR_ROUTE130_STATE, 2
	release
	end

AlteringCave_EventScript_No::
	msgbox AlteringCave_Text_No, MSGBOX_DEFAULT
	release
	end

AlteringCave_Text_RubyAsk:
	.string "It's a RUBY.\p"
	.string "Pick it up?$"

AlteringCave_Text_ReceivedRuby:
	.string "{PLAYER} put the RUBY in the bag.$"

AlteringCave_Text_No:
	.string "{PLAYER} left the RUBY on the ground.$"

