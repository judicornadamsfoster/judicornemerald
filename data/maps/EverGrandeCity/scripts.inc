EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"


//triggers when VAR_LEAF_STATE=??
EvergrandeCity_Celebi_Trigger::
	lock
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJ
	moncryscript SPECIES_CELEBI, EvergrandeCity_Text_Celebi
	closemessage
	delay 20
	emote LOCALID_PLAYER, QUESTION
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EvergrandeCity_Movement_CameraPanUp
	waitmovement 0
	delay 50
	applymovement LOCALID_EGC_CELEBI, EvergrandeCity_Movement_Celebi
	waitmovement 0
	delay 30
	applymovement LOCALID_EGC_CELEBI, EvergrandeCity_Movement_Celebi2
	waitmovement 0
	delay 30
	applymovement LOCALID_CAMERA, EvergrandeCity_Movement_CameraPanDown
	waitmovement 0
	delay 20
	special RemoveCameraObject
//	setvar VAR_LEAF_STATE, ??
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJ
	release
	end


EvergrandeCity_Text_Celebi:
	.string "Biiiiii!$"

EvergrandeCity_Movement_Celebi:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right	
	walk_right
	walk_right
	walk_right
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

EvergrandeCity_Movement_Celebi2:
	walk_right
	walk_right
	walk_right
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

EvergrandeCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EvergrandeCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end
