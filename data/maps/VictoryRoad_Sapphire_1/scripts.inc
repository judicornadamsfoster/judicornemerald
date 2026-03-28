VictoryRoad_Sapphire_1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_Sapphire_1_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_Sapphire_1_OnTransition
	.byte 0

VictoryRoad_Sapphire_1_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_Sapphire_1_EventScript_TryRemoveMon
	end

VictoryRoad_Sapphire_1_EventScript_TryRemoveMon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

VictoryRoad_Sapphire_1_OnTransition:
	call_if_unset FLAG_DEFEATED_VICTORYROADMON_1, VictoryRoad_Sapphire_1_EventScript_ShowMon1
	call_if_unset FLAG_DEFEATED_VICTORYROADMON_2, VictoryRoad_Sapphire_1_EventScript_ShowMon2
	call_if_unset FLAG_DEFEATED_VICTORYROADMON_3, VictoryRoad_Sapphire_1_EventScript_ShowMon3	
	call_if_unset FLAG_DEFEATED_VICTORYROADMON_4, VictoryRoad_Sapphire_1_EventScript_ShowMon4
	call_if_set FLAG_VR_THIEF_3, VictoryRoad_Sapphire_1_EventScript_HideThiefEntrance
	end

VictoryRoad_Sapphire_1_EventScript_HideThiefEntrance::
	removeobject LOCALID_VR_THIEF3
	setflag FLAG_TEMP_4
	return

VictoryRoad_Sapphire_1_EventScript_ThiefEntrance::
	msgbox VictoryRoad_Sapphire_1_Text_ThiefEntrance, MSGBOX_NPC
	end

VictoryRoad_Sapphire_1_Text_ThiefEntrance:
	.string "I've explored VICTORY ROAD many times,\n"
	.string "but then this hidden cave opened!\p"
	.string "I wonder what will be found here...$"

VictoryRoad_Sapphire_1_EventScript_ShowMon1::
	clearflag FLAG_HIDE_VICTORYROADMON_1
	return

VictoryRoad_Sapphire_1_EventScript_ShowMon2::
	clearflag FLAG_HIDE_VICTORYROADMON_2
	return

VictoryRoad_Sapphire_1_EventScript_ShowMon3::
	clearflag FLAG_HIDE_VICTORYROADMON_3
	return
	
VictoryRoad_Sapphire_1_EventScript_ShowMon4::
	clearflag FLAG_HIDE_VICTORYROADMON_4
	return

VictoryRoad_Sapphire_1_EventScript_ThiefTrigger2::
	lock
	applymovement LOCALID_VR_THIEF2, VictoryRoad_Sapphire_1_EventScript_Movement_ThiefLookAtPlayer
	waitmovement 0
	message VictoryRoad_Sapphire_1_Text_StopFollowing
	waitmessage
	waitbuttonpress
	closemessage
	applymovement LOCALID_VR_THIEF2, VictoryRoad_Sapphire_1_EventScript_Movement_Thief2
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_VR_THIEF2
	setflag FLAG_VR_THIEF_2
	setvar VAR_VICTORY_ROAD_THIEF, 4
	release
	end

VictoryRoad_Sapphire_1_EventScript_Movement_ThiefLookAtPlayer:
	emote_exclamation_mark
	delay_16
	delay_16
	walk_in_place_up
	delay_16
	delay_16
	step_end

VictoryRoad_Sapphire_1_Text_StopFollowing:
	.string "STOP FOLLOWING ME!!$"

VictoryRoad_Sapphire_1_EventScript_Movement_Thief2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon1a::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON1, VictoryRoad_Sapphire_1_EventScript_Movement_Mon1a
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon1

VictoryRoad_Sapphire_1_EventScript_Movement_Mon1a:
	face_right
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_right
	jump_right
	jump_right
	face_up
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon1b::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON1, VictoryRoad_Sapphire_1_EventScript_Movement_Mon1b
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon1

VictoryRoad_Sapphire_1_EventScript_Movement_Mon1b:
	face_right
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_right
	jump_right
	jump_right
	walk_fast_right
	face_up
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon1c::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON1, VictoryRoad_Sapphire_1_EventScript_Movement_Mon1c
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon1

VictoryRoad_Sapphire_1_EventScript_Movement_Mon1c:
	face_right
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_right
	jump_right
	jump_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon2a::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON2, VictoryRoad_Sapphire_1_EventScript_Movement_Mon2a
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon2

VictoryRoad_Sapphire_1_EventScript_Movement_Mon2a:
	emote_exclamation_mark
	delay_16
	delay_16
	face_left
	jump_2_left
	Jump_2_left
	jump_left
	jump_in_place_up
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon2b::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON2, VictoryRoad_Sapphire_1_EventScript_Movement_Mon2b
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon2

VictoryRoad_Sapphire_1_EventScript_Movement_Mon2b:
	emote_exclamation_mark
	delay_16
	delay_16
	face_left
	jump_2_left
	Jump_2_left
	jump_in_place_up
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon2c::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON2, VictoryRoad_Sapphire_1_EventScript_Movement_Mon2c
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon2

VictoryRoad_Sapphire_1_EventScript_Movement_Mon2c:
	emote_exclamation_mark
	delay_16
	delay_16
	face_left
	jump_2_left
	Jump_left
	jump_in_place_up
	step_end
	
VictoryRoad_Sapphire_1_EventScript_TriggerMon3::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON3, VictoryRoad_Sapphire_1_EventScript_Movement_Mon3
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon3

VictoryRoad_Sapphire_1_EventScript_Movement_Mon3:
	emote_exclamation_mark
	delay_16
	delay_16
	jump_2_right
	jump_2_right
	jump_in_place_up
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon4a::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON4, VictoryRoad_Sapphire_1_EventScript_Movement_Mon4a
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon4

VictoryRoad_Sapphire_1_EventScript_Movement_Mon4a:
	emote_exclamation_mark
	delay_16
	delay_16
	jump_2_right
	jump_right
	jump_in_place_up
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon4b::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON4, VictoryRoad_Sapphire_1_EventScript_Movement_Mon4b
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon4

VictoryRoad_Sapphire_1_EventScript_Movement_Mon4b:
	emote_exclamation_mark
	delay_16
	delay_16
	jump_2_right
	jump_2_right
	jump_in_place_up
	step_end

VictoryRoad_Sapphire_1_EventScript_TriggerMon4c::
	lock
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_VRMON4, VictoryRoad_Sapphire_1_EventScript_Movement_Mon4c
	waitmovement 0
	goto VictoryRoad_Sapphire_1_EventScript_Mon4

VictoryRoad_Sapphire_1_EventScript_Movement_Mon4c:
	emote_exclamation_mark
	delay_16
	delay_16
	jump_2_right
	jump_2_right
	jump_right
	jump_in_place_up
	step_end


VictoryRoad_Sapphire_1_EventScript_Mon1::
	setwildbattle SPECIES_DUSCLOPS, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_Sapphire_1_EventScript_DefeatedMon1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_Sapphire_1_EventScript_DefeatedMon1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_Sapphire_1_EventScript_DefeatedMon1
	removeobject LOCALID_VRMON1
	setflag FLAG_DEFEATED_VICTORYROADMON_1
	setvar VAR_VICTORY_ROAD_THIEF, 5
	release
	end

VictoryRoad_Sapphire_1_EventScript_DefeatedMon1::
	removeobject LOCALID_VRMON1
	setflag FLAG_DEFEATED_VICTORYROADMON_1
	setvar VAR_VICTORY_ROAD_THIEF, 5
	goto Common_EventScript_RemoveStaticPokemon
	end

VictoryRoad_Sapphire_1_EventScript_Mon2::
	setwildbattle SPECIES_DUSCLOPS, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_Sapphire_1_EventScript_DefeatedMon2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_Sapphire_1_EventScript_DefeatedMon2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_Sapphire_1_EventScript_DefeatedMon2
	removeobject LOCALID_VRMON2
	setflag FLAG_DEFEATED_VICTORYROADMON_2
	setvar VAR_VICTORY_ROAD_THIEF, 6
	release
	end

VictoryRoad_Sapphire_1_EventScript_DefeatedMon2::
	removeobject LOCALID_VRMON2
	setflag FLAG_DEFEATED_VICTORYROADMON_2
	setvar VAR_VICTORY_ROAD_THIEF, 6
	goto Common_EventScript_RemoveStaticPokemon
	end

VictoryRoad_Sapphire_1_EventScript_Mon3::
	setwildbattle SPECIES_DUSCLOPS, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_Sapphire_1_EventScript_DefeatedMon3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_Sapphire_1_EventScript_DefeatedMon3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_Sapphire_1_EventScript_DefeatedMon3
	removeobject LOCALID_VRMON3
	setflag FLAG_DEFEATED_VICTORYROADMON_3
	setvar VAR_VICTORY_ROAD_THIEF, 7
	release
	end

VictoryRoad_Sapphire_1_EventScript_DefeatedMon3::
	removeobject LOCALID_VRMON3
	setflag FLAG_DEFEATED_VICTORYROADMON_3
	setvar VAR_VICTORY_ROAD_THIEF, 7
	goto Common_EventScript_RemoveStaticPokemon
	end

VictoryRoad_Sapphire_1_EventScript_Mon4::
	setwildbattle SPECIES_DUSCLOPS, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_Sapphire_1_EventScript_DefeatedMon4
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_Sapphire_1_EventScript_DefeatedMon4
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_Sapphire_1_EventScript_DefeatedMon4
	removeobject LOCALID_VRMON4
	setflag FLAG_DEFEATED_VICTORYROADMON_4
	setvar VAR_VICTORY_ROAD_THIEF, 8
	release
	end

VictoryRoad_Sapphire_1_EventScript_DefeatedMon4::
	removeobject LOCALID_VRMON4
	setflag FLAG_DEFEATED_VICTORYROADMON_4
	setvar VAR_VICTORY_ROAD_THIEF, 8
	goto Common_EventScript_RemoveStaticPokemon
	end


VictoryRoad_Sapphire_1_Text_MoveBack:
	.string "The MIRAGE MAN's voice echoes:\p"
	.string "Find a SAPPHIRE.$"


VictoryRoad_Sapphire_1_EventScript_TriggerMoveBack1::
	lock
	message VictoryRoad_Sapphire_1_Text_MoveBack
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_TriggerMoveBack1
	waitmovement 0
	release
	end

VictoryRoad_Sapphire_1_EventScript_TriggerMoveBack2::
	lock
	message VictoryRoad_Sapphire_1_Text_MoveBack
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_TriggerMoveBack2
	waitmovement 0
	release
	end

VictoryRoad_Sapphire_1_EventScript_TriggerMoveBack3::
	lock
	message VictoryRoad_Sapphire_1_Text_MoveBack
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_TriggerMoveBack3
	waitmovement 0
	release
	end

VictoryRoad_Sapphire_1_Movement_TriggerMoveBack1:
	walk_right
	walk_right
	walk_right
	step_end

VictoryRoad_Sapphire_1_Movement_TriggerMoveBack2:
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

VictoryRoad_Sapphire_1_Movement_TriggerMoveBack3:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end


VictoryRoad_Sapphire_1_EventScript_TriggerItsASapphire::
	lock
	applymovement LOCALID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	message VictoryRoad_Sapphire_1_Text_ItsASapphire
	waitmessage
	waitbuttonpress
	setvar VAR_VICTORY_ROAD_THIEF, 1
	release
	end

VictoryRoad_Sapphire_1_Text_ItsASapphire:
	.string "That looks like a SAPPHIRE!$"
	

VictoryRoad_Sapphire_1_EventScript_Sapphire::
	lock
	faceplayer
	setflag FLAG_VR_THIEF_3
	message VictoryRoad_Sapphire_1_Text_FoundSapphire
	waitmessage
	waitbuttonpress
	closemessage
	setobjectxyperm LOCALID_VR_THIEF1, 35, 3
	addobject LOCALID_VR_THIEF1
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefFallIn
	waitmovement 0
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerHeardStop
	message VictoryRoad_Sapphire_1_Text_Stop
	waitmessage
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call_if_eq VAR_FACING, DIR_NORTH, VictoryRoad_Sapphire_1_EventScript_ThiefLookAtSapphirePlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, VictoryRoad_Sapphire_1_EventScript_ThiefLookAtSapphirePlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, VictoryRoad_Sapphire_1_EventScript_ThiefLookAtSapphirePlayerEast
	call_if_eq VAR_FACING, DIR_WEST, VictoryRoad_Sapphire_1_EventScript_ThiefLookAtSapphirePlayerWest
	msgbox VictoryRoad_Sapphire_1_Text_FollowYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, VictoryRoad_Sapphire_1_EventScript_ThiefGetSapphirePlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, VictoryRoad_Sapphire_1_EventScript_ThiefGetSapphirePlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, VictoryRoad_Sapphire_1_EventScript_ThiefGetSapphirePlayerEast
	call_if_eq VAR_FACING, DIR_WEST, VictoryRoad_Sapphire_1_EventScript_ThiefGetSapphirePlayerWest
	removeobject LOCALID_SAPPHIRE
	setflag FLAG_HIDE_SAPPHIRE
	msgbox VictoryRoad_Sapphire_1_Text_HeardSapphire, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, VictoryRoad_Sapphire_1_EventScript_ThiefExitPlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, VictoryRoad_Sapphire_1_EventScript_ThiefExitPlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, VictoryRoad_Sapphire_1_EventScript_ThiefExitPlayerEast
	call_if_eq VAR_FACING, DIR_WEST, VictoryRoad_Sapphire_1_EventScript_ThiefExitPlayerWest
	playse SE_EXIT
	waitse
	delay 35
	removeobject LOCALID_VR_THIEF1
	setflag FLAG_VR_THIEF_1
	setflag FLAG_VR_THIEF_PL
	setvar VAR_VICTORY_ROAD_THIEF, 3
	release
	end

VictoryRoad_Sapphire_1_Text_Stop:
	.string "STOP!{PAUSE 60}{PAUSE 60}$"

VictoryRoad_Sapphire_1_Movement_PlayerHeardStop:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	emote_question_mark
	step_end

VictoryRoad_Sapphire_1_Movement_ThiefFallIn:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end


VictoryRoad_Sapphire_1_EventScript_ThiefLookAtSapphirePlayerNorth::
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefLookAtSapphirePlayerNorth
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerNorthLookAtThief
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefLookAtSapphirePlayerSouth::
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefLookAtSapphirePlayerSouth
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerSouthLookAtThief
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefLookAtSapphirePlayerWest::
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefLookAtSapphirePlayerWest
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerWestLookAtThief
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefLookAtSapphirePlayerEast::
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefLookAtSapphirePlayerEast
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerEastLookAtThief
	waitmovement 0
	return

VictoryRoad_Sapphire_1_Movement_ThiefLookAtSapphirePlayerNorth::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left	
	walk_in_place_faster_down
	step_end


VictoryRoad_Sapphire_1_Movement_ThiefLookAtSapphirePlayerSouth::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_faster_up
	step_end


VictoryRoad_Sapphire_1_Movement_ThiefLookAtSapphirePlayerWest::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_faster_right
	step_end

VictoryRoad_Sapphire_1_Movement_ThiefLookAtSapphirePlayerEast::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_faster_left
	step_end

VictoryRoad_Sapphire_1_Movement_PlayerNorthLookAtThief::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_up
	step_end
	
VictoryRoad_Sapphire_1_Movement_PlayerSouthLookAtThief::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_down
	step_end

VictoryRoad_Sapphire_1_Movement_PlayerWestLookAtThief::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_4
	walk_in_place_fast_left
	step_end

VictoryRoad_Sapphire_1_Movement_PlayerEastLookAtThief::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_right
	step_end


VictoryRoad_Sapphire_1_EventScript_ThiefGetSapphirePlayerNorth::
	applymovement LOCALID_VR_THIEF1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefGetSapphirePlayerSouth::
	applymovement LOCALID_VR_THIEF1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return
	
VictoryRoad_Sapphire_1_EventScript_ThiefGetSapphirePlayerWest::
	applymovement LOCALID_VR_THIEF1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefGetSapphirePlayerEast::
	applymovement LOCALID_VR_THIEF1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefExitPlayerNorth::
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerWestWatchThiefExit
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefExitPlayerNorth
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefExitPlayerSouth::
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerWestWatchThiefExit
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefExitPlayerSouth
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefExitPlayerWest::
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerWestWatchThiefExit
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefExitPlayerWest
	waitmovement 0
	return

VictoryRoad_Sapphire_1_EventScript_ThiefExitPlayerEast::
	applymovement LOCALID_PLAYER, VictoryRoad_Sapphire_1_Movement_PlayerWestWatchThiefExit
	applymovement LOCALID_VR_THIEF1, VictoryRoad_Sapphire_1_Movement_ThiefExitPlayerEast
	waitmovement 0
	return

VictoryRoad_Sapphire_1_Movement_PlayerWestWatchThiefExit::
	delay_8
	walk_in_place_faster_left
	step_end

VictoryRoad_Sapphire_1_Movement_ThiefExitPlayerNorth::
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

VictoryRoad_Sapphire_1_Movement_ThiefExitPlayerSouth::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

VictoryRoad_Sapphire_1_Movement_ThiefExitPlayerWest::
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

VictoryRoad_Sapphire_1_Movement_ThiefExitPlayerEast::
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

VictoryRoad_Sapphire_1_Text_FoundSapphire::
    .string "{PLAYER} found a SAPPHIRE!$"

VictoryRoad_Sapphire_1_Text_FollowYou::
    .string "Fufu… Fufufufu…\n"
    .string "I guessed right.\p"
    .string "I was right to follow you!\p"
	.string "I'm taking this!$"

VictoryRoad_Sapphire_1_Text_HeardSapphire::
    .string "I heard there might be a SAPPHIRE here,\n"
	.string "now it belongs to me!\p"
    .string "I'm gonna sell it for some serious\n"
	.string "money!\p"
    .string "…{PAUSE 60} D-don't glare at me like that!\p"
    .string "If you want it back, why don't you go\n"
    .string "get it after I sell it?$"

