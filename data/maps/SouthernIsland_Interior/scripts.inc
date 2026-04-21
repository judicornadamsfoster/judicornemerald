SouthernIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SouthernIsland_Interior_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
	.byte 0

SouthernIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
	end

SouthernIsland_Interior_EventScript_TryRemoveLati::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SOUTHERN_ISLAND_LATI
	return

SouthernIsland_Interior_OnTransition:
	call_if_set FLAG_BOTH_LATI_UNLOCK, SouthernIsland_Interior_EventScript_SetUpMapChange
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatios
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatias
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
	end

SouthernIsland_Interior_OnLoad:
	call_if_set FLAG_BOTH_LATI_UNLOCK, SouthernIsland_Interior_EventScript_SetUpMapChange
	end

SouthernIsland_Interior_EventScript_SetUpMapChange::
	setmetatile 10, 0, 0x070, TRUE
	setmetatile 11, 0, 0x071, TRUE
	setmetatile 12, 0, 0x070, TRUE
	setmetatile 13, 0, 0x071, TRUE
	setmetatile 14, 0, 0x072, TRUE
	setmetatile 15, 0, 0x072, TRUE

	setmetatile 10, 1, 0x070, TRUE
	setmetatile 11, 1, 0x071, TRUE
	setmetatile 12, 1, 0x070, TRUE
	setmetatile 13, 1, 0x071, TRUE
	setmetatile 14, 1, 0x072, TRUE
	setmetatile 15, 1, 0x072, TRUE

	setmetatile 10, 2, 0x070, TRUE
	setmetatile 11, 2, 0x071, TRUE
	setmetatile 12, 2, 0x070, TRUE
	setmetatile 13, 2, 0x071, TRUE
	setmetatile 14, 2, 0x072, TRUE
	setmetatile 15, 2, 0x072, TRUE

	setmetatile 10, 3, 0x070, TRUE
	setmetatile 11, 3, 0x071, TRUE
	setmetatile 12, 3, 0x070, TRUE
	setmetatile 13, 3, 0x071, TRUE
	setmetatile 14, 3, 0x072, TRUE
	setmetatile 15, 3, 0x072, TRUE

	setmetatile 10, 4, 0x070, TRUE
	setmetatile 11, 4, 0x071, TRUE
	setmetatile 12, 4, 0x070, TRUE
	setmetatile 13, 4, 0x071, TRUE
	setmetatile 14, 4, 0x072, TRUE
	setmetatile 15, 4, 0x072, TRUE

	setmetatile 10, 5, 0x070, TRUE
	setmetatile 11, 5, 0x071, TRUE
	setmetatile 12, 5, 0x070, TRUE
	setmetatile 13, 5, 0x071, TRUE
	setmetatile 14, 5, 0x072, TRUE
	setmetatile 15, 5, 0x072, TRUE

	setmetatile 10, 6, 0x070, TRUE
	setmetatile 11, 6, 0x071, TRUE
	setmetatile 12, 6, 0x078, TRUE
	setmetatile 13, 6, 0x064, TRUE
	setmetatile 14, 6, 0x07A, TRUE
	setmetatile 15, 6, 0x072, TRUE

	setmetatile 10, 7, 0x078, TRUE
	setmetatile 11, 7, 0x079, TRUE
	setmetatile 12, 7, 0x079, TRUE
	setmetatile 13, 7, 0x0A7, FALSE
	setmetatile 14, 7, 0x079, TRUE
	setmetatile 15, 7, 0x07A, TRUE
	return



//Lati Party Check
SouthernIsland_Interior_EventScript_TryLatiEncounter::
	lockall
	goto_if_eq VAR_BILL_STATE, 10, SouthernIsland_Interior_EventScript_BothLatiCheck
	goto_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_PartyCheckLatias
	goto_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_PartyCheckLatios
	end
	
SouthernIsland_Interior_EventScript_PartyCheckLatias:
	setvar 0x8005, SPECIES_LATIAS
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, SouthernIsland_Interior_EventScript_Lati
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_PartyCheckLatios:
	setvar 0x8005, SPECIES_LATIOS
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, SouthernIsland_Interior_EventScript_Lati
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

//if VAR_BILL_STATE>=10
SouthernIsland_Interior_EventScript_BothLatiCheck:
	setvar 0x8005, SPECIES_LATIAS
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, SouthernIsland_Interior_EventScript_BothLatiCheck2
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_BothLatiCheck2:
	setvar 0x8005, SPECIES_LATIOS
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, SouthernIsland_Interior_EventScript_BothLatiInParty
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_BothLatiInParty:
	goto_if_ge VAR_BILL_STATE, 11, SouthernIsland_Interior_EventScript_Sign
	delay 20
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	msgbox SouthernIsland_Interior_Text_StoneReacting, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_PLAYER, SouthernIsland_Interior_Movement_PushBack
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 16 @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	call SouthernIsland_Interior_EventScript_SetUpMapChange
	special DrawWholeMapView
	playse SE_BANG
	waitse
	delay 8
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	waitmovement
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp2
	waitmovement 0
	delay 50
	waitse
	delay 30
	applymovement LOCALID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown2
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setflag FLAG_BOTH_LATI_UNLOCK
	setvar VAR_BILL_STATE, 11
	releaseall
	end

SouthernIsland_Interior_Movement_PushBack:
	emote_exclamation_mark
	lock_facing_direction
	walk_down
	walk_down
	unlock_facing_direction
	step_end

SouthernIsland_Interior_Text_StoneReacting:
	.string "A rumbling noise is coming from under\n"
	.string "the stone.$"

SouthernIsland_Interior_Movement_CameraPanUp2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown2:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end


//original scripts below
SouthernIsland_Interior_EventScript_SetUpLatios::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	return

SouthernIsland_Interior_EventScript_SetUpLatias::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	return

SouthernIsland_Interior_EventScript_SetUpPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SouthernIsland_Interior_EventScript_SetBrendanGfx
	goto_if_eq VAR_RESULT, FEMALE, SouthernIsland_Interior_EventScript_SetMayGfx
	end

SouthernIsland_Interior_EventScript_SetBrendanGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

SouthernIsland_Interior_EventScript_SetMayGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

SouthernIsland_Interior_EventScript_Lati::
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
	setflag FLAG_TEMP_2
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	addobject LOCALID_SOUTHERN_ISLAND_LATI
	delay 30
	applymovement LOCALID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_SOUTHERN_ISLAND_LATI, SouthernIsland_Interior_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_SOUTHERN_ISLAND_LATI
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiosBattleVars
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiasBattleVars
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLatiBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SouthernIsland_Interior_EventScript_LatiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_EventScript_RanFromLati
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SouthernIsland_Interior_EventScript_RanFromLati
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
	setvar VAR_BILL_STATE, 9
	releaseall
	end

SouthernIsland_Interior_EventScript_LatiDefeated::
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_RanFromLati::
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_Sign::
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_SetLatiosBattleVars::
	seteventmon SPECIES_LATIOS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_EventScript_SetLatiasBattleVars::
	seteventmon SPECIES_LATIAS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

SouthernIsland_Interior_Movement_LatiApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
