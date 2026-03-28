EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


//
EverGrandeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	call_if_set FLAG_VR_THIEF_PL, EverGrandeCity_PokemonCenter_1F_EventScript_HideVRThiefPL
	end


EverGrandeCity_PokemonCenter_1F_EventScript_HideVRThiefPL::
	removeobject LOCALID_VR_THIEF_PL
	setflag FLAG_TEMP_4
	return

EverGrandeCity_PokemonCenter_1F_EventScript_VRThiefPL_Start::
	lock
	faceplayer
	goto_if_eq VAR_VICTORY_ROAD_THIEF, 11, EverGrandeCity_PokemonCenter_1F_EventScript_VRThiefPL_TryGiveSapphire
	goto_if_eq VAR_VICTORY_ROAD_THIEF, 12, EverGrandeCity_PokemonCenter_1F_EventScript_VRThiefPL_StayHereAndRecover
	message EverGrandeCity_PokemonCenter_1F_Text_VRThiefPL_GoingInvestigating
	waitmessage
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ThiefLeavePlayerNorthEast
	call_if_eq VAR_FACING, DIR_SOUTH, EverGrandeCity_PokemonCenter_1F_EventScript_ThiefLeavePlayerSouthWest
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ThiefLeavePlayerNorthEast
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ThiefLeavePlayerSouthWest
	playse SE_EXIT
	waitse
	removeobject LOCALID_VR_THIEF_PL
	setflag FLAG_VR_THIEF_PL
	release
	end

EverGrandeCity_PokemonCenter_1F_Text_VRThiefPL_GoingInvestigating:
	.string "Sorry, I'm just leaving to back to\n"
	.string "investigating VICTORY ROAD.\p"
	.string "There's rumours that there are gems\n"
	.string "everywhere.$"

EverGrandeCity_PokemonCenter_1F_EventScript_ThiefLeavePlayerNorthEast::
	applymovement LOCALID_VR_THIEF1, EverGrandeCity_PokemonCenter_1F_Movement_ThiefLeavePlayerNorthEast
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ThiefLeavePlayerSouthWest::
	applymovement LOCALID_VR_THIEF1, EverGrandeCity_PokemonCenter_1F_Movement_ThiefLeavePlayerSouthWest
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_ThiefLeavePlayerNorthEast::
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ThiefLeavePlayerSouthWest::
	walk_fast_down
	walk_fast_right
	walk_fast_right	
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	step_end


EverGrandeCity_PokemonCenter_1F_EventScript_VRThiefPL_TryGiveSapphire::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_VRThiefPL_TryGiveSapphire, MSGBOX_DEFAULT
	giveitem ITEM_SAPPHIRE
	goto_if_eq VAR_RESULT, FALSE, EverGrandeCity_PokemonCenter_1F_EventScript_VRThiefPL_YouStillNeedSpace
	setflag FLAG_RECEIVED_SAPPHIRE
	setvar VAR_VICTORY_ROAD_THIEF, 12
	goto EverGrandeCity_PokemonCenter_1F_EventScript_VRThiefPL_StayHereAndRecover
	end

EverGrandeCity_PokemonCenter_1F_Text_VRThiefPL_TryGiveSapphire:
	.string "Have you got space for the SAPPHIRE yet?$"

EverGrandeCity_PokemonCenter_1F_EventScript_VRThiefPL_YouStillNeedSpace::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_VRThiefPL_YouStillNeedSpace, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_Text_VRThiefPL_YouStillNeedSpace:
	.string "You still don't have space yet.$"
	
EverGrandeCity_PokemonCenter_1F_EventScript_VRThiefPL_StayHereAndRecover::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_VRThiefPL_StayHereAndRecover, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_Text_VRThiefPL_StayHereAndRecover:
	.string "I'm gonna stay here and recover for a\n"
	.string "while before I go back to exploring.\p"
	.string "Stay safe out there.$"
//






EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_EVER_GRANDE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_EVER_GRANDE_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth::
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit::
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad:
	.string "The POKéMON LEAGUE is only a short\n"
	.string "distance after the VICTORY ROAD.\p"
	.string "If you've come this far, what choice\n"
	.string "do you have but to keep going?$"

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon:
	.string "The long and harrowing VICTORY ROAD…\p"
	.string "It's like reliving the path one has\n"
	.string "traveled in life…\p"
	.string "Believe in your POKéMON and give it\n"
	.string "your very best!$"

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou:
	.string "SCOTT: {PLAYER}{KUN}, you've clawed your\n"
	.string "way up to face the POKéMON LEAGUE!\p"
	.string "I'm happy for you!\n"
	.string "You made my cheering worthwhile!\p"
	.string "{PLAYER}{KUN}, if you were to become\n"
	.string "the POKéMON LEAGUE CHAMPION…\p"
	.string "I'll get in touch with you then.\p"
	.string "Okay, {PLAYER}{KUN}.\n"
	.string "Go for greatness!$"

