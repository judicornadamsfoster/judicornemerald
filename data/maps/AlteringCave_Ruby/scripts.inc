AlteringCave_Ruby_MapScripts::
	.byte 0

AlteringCave_Ruby_EventScript_RubyAsk::
	lock
	msgbox AlteringCave_Ruby_Text_RubyAsk, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq AlteringCave_Ruby_EventScript_No
	giveitem ITEM_RUBY
	removeobject LOCALID_ALTERINGCAVE_RUBY
	setflag FLAG_RECEIVED_RUBY
	setvar VAR_ROUTE130_STATE, 2
	release
	end

AlteringCave_Ruby_EventScript_No::
	msgbox AlteringCave_Ruby_Text_No, MSGBOX_DEFAULT
	release
	end

AlteringCave_Ruby_Text_RubyAsk:
	.string "It's a RUBY.\p"
	.string "Pick it up?$"

AlteringCave_Ruby_Text_No:
	.string "{PLAYER} left the RUBY on the ground.$"

