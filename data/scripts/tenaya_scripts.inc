/*
In this file:
daily battle with red at meteor falls



*/


EventScript_Red_Trigger::
	lock
	setvar VAR_TEMP_0, 1
	goto_if_ne VAR_LEAF_STATE, 23, EventScript_Red_HideRed
//	goto_if_eq VAR_LEAF_STATE, 23, EventScript_Red_ShowRed
//	goto_if_unset FLAG_HIDE_RED, EventScript_Red_ShowRed
	end

EventScript_Red_HideRed:
	removeobject LOCALID_SPBATTLE_RED
	setflag FLAG_HIDE_RED
	release
	end

/*
EventScript_Red_ShowRed:
	addobject LOCALID_SPBATTLE_RED
	release
	end
*/

EventScript_Red_Start::
	lock
	faceplayer
	setflag FLAG_SET_BATTLE_BGM
	setvar VAR_TEMP_F, MUS_RG_VS_CHAMPION
	msgbox Red_Text_PreBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RED, Red_Text_BeatenRed
	goto EventScript_Red_Beaten
	
EventScript_Red_Beaten::
	addvar VAR_BEATEN_RED, 1
	clearflag FLAG_SET_BATTLE_BGM
	message Red_Text_PostBattle
	closemessage
	goto_if_le VAR_BEATEN_RED, 6, EventScript_Red_Give
	goto EventScript_Red_AfterGive

EventScript_Red_Give::
	applymovement LOCALID_PLAYER, Common_Movement_Delay32
	waitmovement
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement
	msgbox Red_Text_FeelSomething, MSGBOX_DEFAULT
	goto_if_eq VAR_BEATEN_RED, 1, RedGive_1
	goto_if_eq VAR_BEATEN_RED, 2, RedGive_2
	goto_if_eq VAR_BEATEN_RED, 3, RedGive_3
	goto_if_eq VAR_BEATEN_RED, 4, RedGive_4
	goto_if_eq VAR_BEATEN_RED, 5, RedGive_5
	goto_if_eq VAR_BEATEN_RED, 6, RedGive_6
	goto_if_ge VAR_BEATEN_RED, 7, RedGive_NoMore

RedGive_1::
	giveegg SPECIES_PICHU
	playmoncry SPECIES_PICHU, 0
	waitmoncry
	goto RedGive_PartyOrPc
	end

RedGive_2::
	giveegg SPECIES_BULBASAUR
	playmoncry SPECIES_BULBASAUR, 0
	waitmoncry
	goto RedGive_PartyOrPc
	end

RedGive_3::
	giveegg SPECIES_CHARMANDER
	playmoncry SPECIES_CHARMANDER, 0
	waitmoncry
	goto RedGive_PartyOrPc
	end

RedGive_4::
	giveegg SPECIES_SQUIRTLE
	playmoncry SPECIES_SQUIRTLE, 0
	waitmoncry
	goto RedGive_PartyOrPc
	end

RedGive_5::
	giveegg SPECIES_EEVEE
	playmoncry SPECIES_EEVEE, 0
	waitmoncry
	goto RedGive_PartyOrPc
	end

RedGive_6::
	giveegg SPECIES_SNORLAX
	playmoncry SPECIES_SNORLAX, 0
	waitmoncry
	goto RedGive_PartyOrPc
	end

RedGive_NoMore::
	goto EventScript_Red_AfterGive
	end

RedGive_PartyOrPc::
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Red_ReceiveParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Red_ReceivePC
	end

Red_ReceiveParty::
	playfanfare MUS_OBTAIN_ITEM
	msgbox Red_Text_PlayerReceivedEgg, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	release
	goto EventScript_Red_AfterGive
	end

Red_ReceivePC::
	playfanfare MUS_OBTAIN_ITEM
	message Red_Text_PlayerReceivedEgg
	waitmessage
	waitfanfare
	release
	message Red_Text_SentToPC
	closemessage
	goto EventScript_Red_AfterGive
	end	

EventScript_Red_AfterGive::
	lock
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_RED
	removeobject LOCALID_SPBATTLE_RED
	fadescreen FADE_FROM_BLACK
	setflag FLAG_DEFEATED_RED
	msgbox Red_Text_RedDisappeared, MSGBOX_DEFAULT
	release
	end


Red_Text_PreBattle:
	.string "{PKMN} TRAINER RED:... ...$"

Red_Text_BeatenRed:
	.string "... ...$"
	
Red_Text_PostBattle:
	.string "{PKMN} TRAINER RED:... ...$"

Red_Text_FeelSomething:
	.string "You feel RED place something into your\n"
	.string "hands.$"

Red_Text_PlayerReceivedEgg:
	.string "{PLAYER} received an EGG!$"

Red_Text_SentToPC:
	.string "The EGG was sent to your PC.$"

Red_Text_RedDisappeared:
	.string "RED disappeared.$"


//npc tells of red coming daily
EventScript_MeteorBoy_Start::
	goto_if_eq VAR_LEAF_STATE, 23, EventScript_MeteorBoy_23
	lock
	faceplayer
	msgbox Text_MeteorBoy_Not23, MSGBOX_DEFAULT
	release
	end

EventScript_MeteorBoy_23:
	lock
	faceplayer
	msgbox Text_MeteorBoy_DailyMan, MSGBOX_DEFAULT
	release
	end

Text_MeteorBoy_Not23:
	.string "I come here daily to swim.$"

Text_MeteorBoy_DailyMan:
	.string "I come here daily to swim.\p"
	.string "There's another guy that started\n"
	.string "coming here every day too.$"

