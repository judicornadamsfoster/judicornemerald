//altering cave now opens when FLAG_OPEN_ALTERING_CAVE is set,
//change ROUTE103 flag to open it
//add to flannery setflag FLAG_OPEN_ALTERING_CAVE
//add in later text changes that the cave has opened

AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, AlteringCave_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, AlteringCave_OnLoad
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, AlteringCave_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnLoad:
	call_if_ge VAR_ROUTE130_STATE, 1, AlteringCave_OpenCave
	end

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	call_if_ge VAR_ROUTE130_STATE, 1, AlteringCave_OpenCave
	end

AlteringCave_OpenCave::
	setmetatile 13, 4, 0x20B, TRUE
	setmetatile 14, 4, 0x20C, TRUE
	setmetatile 15, 4, 0x20D, TRUE
	setmetatile 13, 5, 0x213, TRUE
	setmetatile 14, 5, 0x214, FALSE
	setmetatile 15, 5, 0x215, TRUE
	special DrawWholeMapView
	return

//20B 20C 20D 213 214 215
AlteringCave_EventScript_Trigger1::
	lockall
	setmetatile 13, 4, 0x20B, TRUE
	setmetatile 14, 4, 0x20C, TRUE
	setmetatile 15, 4, 0x20D, TRUE
	setmetatile 13, 5, 0x213, TRUE
	setmetatile 14, 5, 0x214, FALSE
	setmetatile 15, 5, 0x215, TRUE
	special DrawWholeMapView
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_BANG
	waitse
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement
	msgbox AlteringCave_Text_FallingNoise, MSGBOX_DEFAULT
	setvar VAR_ROUTE130_STATE, 9
	releaseall
	end


AlteringCave_Text_FallingNoise:
	.string "A loud noise echoed through the cave.\p"
	.string "It sounds like rocks falling.$"
