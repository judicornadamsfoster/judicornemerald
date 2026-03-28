VictoryRoad_Sapphire_2_MapScripts::
	.byte 0

//Pikachu battle is a placeholder for a different mon
//search and replace SPECIES_PIKACHU to change the "eating mon"


//sets FLAG_HIDE_TEA
VictoryRoad_Sapphire_2_EventScript_ItemTea::
	finditem ITEM_TEA
	end

VictoryRoad_Sapphire_2_EventScript_EatingMonCheck::
	goto_if_eq VAR_VICTORY_ROAD_THIEF, 8, VictoryRoad_Sapphire_2_EventScript_MonEating
	goto_if_eq VAR_VICTORY_ROAD_THIEF, 9, VictoryRoad_Sapphire_2_EventScript_MonBattle
	
VictoryRoad_Sapphire_2_EventScript_MonEating::
	lock
	bufferspeciesname 1, SPECIES_PIKACHU
	message VictoryRoad_Sapphire_2_Text_MonEating
	waitmessage
	waitbuttonpress
	release
	end

VictoryRoad_Sapphire_2_Text_MonEating:
	.string "The wild {STR_VAR_2} is eating.\n"
	.string "Better not distrub it.$"

VictoryRoad_Sapphire_2_EventScript_MonBattle::
	lock
	faceplayer
	setwildbattle SPECIES_PIKACHU, 30
	bufferspeciesname 1, SPECIES_PIKACHU
	msgbox VictoryRoad_Sapphire_2_Text_MonBattle, MSGBOX_DEFAULT
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_Sapphire_2_EventScript_DefeatedMon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_Sapphire_2_EventScript_DefeatedMon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_Sapphire_2_EventScript_DefeatedMon
	removeobject LOCALID_VR_EATINGMON
	setflag FLAG_VR_EATINGMON
	setvar VAR_VICTORY_ROAD_THIEF, 10
	release
	end

VictoryRoad_Sapphire_2_Text_MonBattle:
	.string "The wild {STR_VAR_2} is no longer eating.\p"
	.string "The wild {STR_VAR_2} attacked.$"

VictoryRoad_Sapphire_2_EventScript_DefeatedMon::
	removeobject LOCALID_VR_EATINGMON
	setflag FLAG_VR_EATINGMON
	setvar VAR_VICTORY_ROAD_THIEF, 10
	goto Common_EventScript_RemoveStaticPokemon
	end


VictoryRoad_Sapphire_2_EventScript_FinalThiefCheck::
	goto_if_eq VAR_VICTORY_ROAD_THIEF, 8, VictoryRoad_Sapphire_2_EventScript_FinalThiefFreezing
	goto_if_eq VAR_VICTORY_ROAD_THIEF, 9, VictoryRoad_Sapphire_2_EventScript_FinalThiefFoundAnything
	goto_if_eq VAR_VICTORY_ROAD_THIEF, 10, VictoryRoad_Sapphire_2_EventScript_FinalThiefEnd
	end
	


VictoryRoad_Sapphire_2_EventScript_FinalThiefFreezing::
	lock
	faceplayer
	bufferspeciesname 1, SPECIES_PIKACHU
	msgbox VictoryRoad_Sapphire_2_Text_ThiefFreezing, MSGBOX_DEFAULT
	setvar VAR_VICTORY_ROAD_THIEF, 9
	release
	end

VictoryRoad_Sapphire_2_Text_ThiefFreezing:
	.string "Pppppp-please help me.\p"
	.string "I'm ffff-freezing cold and can't move.\p"
	.string "If you hhhhhh-help me get warm again,\n"
	.string "I'll give you back the SAPPHIRE.\p"
	.string "I'm sure I saw something bbbbbb-behind\n"
	.string "the {STR_VAR_2} when I passed it.\p"
	.string "Can you see what it is and if it can\n"
	.string "hhhhh-help me?$"

VictoryRoad_Sapphire_2_EventScript_FinalThiefFoundAnything::
	lock
	faceplayer
	bufferspeciesname 1, SPECIES_PIKACHU
	msgbox VictoryRoad_Sapphire_2_Text_FoundAnything, MSGBOX_DEFAULT
	release
	end

VictoryRoad_Sapphire_2_Text_FoundAnything:
	.string "Have you ffff-found anything yet?\p"
	.string "There was something bbbbb-behind the\n"
	.string "{STR_VAR_2}.$"


VictoryRoad_Sapphire_2_EventScript_FinalThiefEnd::
	lock
	faceplayer
	message VictoryRoad_Sapphire_2_Text_TeaGivenToThief
	waitmessage
	waitbuttonpress
	call_if_eq VAR_FACING, DIR_NORTH, VictoryRoad_Sapphire_2_EventScript_ThiefDrinksTeaPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, VictoryRoad_Sapphire_2_EventScript_ThiefDrinksTeaPlayerEast
	message VictoryRoad_Sapphire_2_Text_ThiefFeelingBetter
	waitmessage
	waitbuttonpress
	closemessage
	giveitem ITEM_SAPPHIRE
	goto_if_eq VAR_RESULT, FALSE, VictoryRoad_Sapphire_2_EventScript_GiveYouLater
	setflag FLAG_RECEIVED_SAPPHIRE
	setvar VAR_VICTORY_ROAD_THIEF, 12
	setvar VAR_ROUTE130_STATE, 5
	goto VictoryRoad_Sapphire_2_EventScript_FinalThiefExits
	end

VictoryRoad_Sapphire_2_EventScript_GiveYouLater::
	setvar VAR_VICTORY_ROAD_THIEF, 11
	msgbox VictoryRoad_Sapphire_2_Text_GiveYouLater, MSGBOX_DEFAULT
	goto VictoryRoad_Sapphire_2_EventScript_FinalThiefExits
	end

VictoryRoad_Sapphire_2_EventScript_FinalThiefExits::
	msgbox VictoryRoad_Sapphire_2_Text_RestAtPokeCenter, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VR_THIEF4
	setflag FLAG_VR_THIEF_4
	setflag FLAG_REMOVE_WARP_FADE
	clearflag FLAG_VR_THIEF_PL
	warp MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F, 2, 3
	release
	end

VictoryRoad_Sapphire_2_Text_TeaGivenToThief:
	.string "You found some TEA?\p"
	.string "{PLAYER} handed over the TEA.$"

VictoryRoad_Sapphire_2_EventScript_ThiefDrinksTeaPlayerNorth:
	applymovement LOCALID_VR_THIEF4, VictoryRoad_Sapphire_2_EventScript_Movement_ThiefDrinksTeaPlayerNorth
	waitmovement 0
	return
	
VictoryRoad_Sapphire_2_EventScript_Movement_ThiefDrinksTeaPlayerNorth:
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	delay_16
	delay_16
	delay_16
	emote_heart
	delay_16
	delay_16
	face_down
	step_end


VictoryRoad_Sapphire_2_EventScript_ThiefDrinksTeaPlayerEast::
	applymovement LOCALID_VR_THIEF4, VictoryRoad_Sapphire_2_EventScript_Movement_ThiefDrinksTeaPlayerEast
	waitmovement 0
	return

VictoryRoad_Sapphire_2_EventScript_Movement_ThiefDrinksTeaPlayerEast:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	emote_heart
	delay_16
	delay_16
	face_left
	step_end

VictoryRoad_Sapphire_2_Text_ThiefFeelingBetter:
	.string "Oh that feels so much better.\p"
	.string "I can feel my toes again!\p"
	.string "Well, I did promise to give this back,\n"
	.string "I'm sorry for stealing it from you.$"

VictoryRoad_Sapphire_2_Text_RestAtPokeCenter:
	.string "Come on, let's get out of here.\p"
	.string "We'll go rest up at the EVERGRANDE\n"
	.string "CITY POKéMON CENTER.$"

VictoryRoad_Sapphire_2_Text_GiveYouLater:
	.string "I'll give it to you later when you have\n"
	.string "some space in your bag.$"



