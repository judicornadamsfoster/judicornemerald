LittlerootTown_BrendansHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos

LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
	@ Odd that the MaysHouse equivalent was used below instead
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	setobjectxyperm LOCALID_RIVALS_HOUSE_2F_RIVAL, 0, 2
	setobjectmovementtype LOCALID_RIVALS_HOUSE_2F_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_2F_EventScript_Ret::
	return

LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
	return

LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_BrendansHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
	delay 10
	addobject LOCALID_RIVALS_HOUSE_2F_RIVAL
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
	delay_8
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
	walk_up
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Notebook::
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

PlayersHouse_2F_EventScript_GameCube::
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_YESNO
	end

PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
	.string "MOM: {PLAYER}, how do you like your\n"
	.string "new room?\p"
	.string "Good! Everything's put away neatly!\p"
	.string "They finished moving everything in\n"
	.string "downstairs, too.\p"
	.string "POKéMON movers are so convenient!\p"
	.string "Oh, you should make sure that\n"
	.string "everything's all there on your desk.$"

PlayersHouse_2F_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "HOENN region map.$"

PlayersHouse_2F_Text_ItsAGameCube:
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"



/*
Cheatstart script
copy and paste the entire file to 
	LittlerootTown_BrendansHouse_2F/scripts.ini

in poryscript for 
	LittlerootTown_BrendansHouse_2F
and
	LittlerootTown_MaysHouse_2F
	
replace gamecube script with
(copy and paste it to script field)
	PlayersHouse_2F_EventScript_CheatStart2_Ask:
*/


// cheatstart2
PlayersHouse_2F_EventScript_CheatStart2_Ask::
	lock
	msgbox PlayersHouse_2F_Text_CheatStart2_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, PlayersHouse_2F_EventScript_CheatStart2_Do
	release
	end

PlayersHouse_2F_EventScript_CheatStart2_Do::
	lock

	goto_if_set FLAG_SYS_GAME_CLEAR, PlayersHouse_2F_EventScript_CheatStart2Already

	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4 @ 4: Received Running Shoes
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom and is corresponding gender
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom and is corresponding gender
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	
// fly to points
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_VISITED_OLDALE_TOWN
	setflag FLAG_VISITED_DEWFORD_TOWN
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_VISITED_SLATEPORT_CITY
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_VISITED_RUSTBORO_CITY
	setflag FLAG_VISITED_FORTREE_CITY
	setflag FLAG_VISITED_LILYCOVE_CITY
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_BATTLE_FRONTIER

//badges flags
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET

//HM flags
	setflag FLAG_RECEIVED_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLY
	setflag FLAG_RECEIVED_HM_SURF
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_RECEIVED_HM_WATERFALL
	setflag FLAG_RECEIVED_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLY
	setflag FLAG_RECEIVED_HM_SURF
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_RECEIVED_HM_WATERFALL

	givemon SPECIES_RAYQUAZA, 70, ITEM_NONE
	givemon SPECIES_GROUDON, 45, ITEM_NONE
	givemon SPECIES_KYOGRE, 45, ITEM_NONE

//for tm and hm
	additem ITEM_TM01
	additem ITEM_TM02
	additem ITEM_TM13
	additem ITEM_TM21
	additem ITEM_TM23
	additem ITEM_TM24
	additem ITEM_TM28
	additem ITEM_TM29
	additem ITEM_TM30
	additem ITEM_TM31
	additem ITEM_TM32
	additem ITEM_TM35
	additem ITEM_TM36
	additem ITEM_HM01
	additem ITEM_HM02
	additem ITEM_HM03
	additem ITEM_HM04
	additem ITEM_HM05
	additem ITEM_HM06
	additem ITEM_HM07
	additem ITEM_HM08

//other items
	additem ITEM_COIN_CASE
	additem ITEM_MASTER_BALL, 99
	additem ITEM_RARE_CANDY, 99
	additem ITEM_SUPER_ROD

// for mirage island event
	additem ITEM_RUBY
	additem ITEM_SAPPHIRE

//for devon corp fossill reviver and fossil maniac
	additem ITEM_CLAW_FOSSIL
	additem ITEM_ROOT_FOSSIL
	additem ITEM_DOME_FOSSIL
	additem ITEM_HELIX_FOSSIL

	addmoney 999999
	addcoins 9999
	msgbox PlayersHouse_2F_Text_CheatStart2Activated, MSGBOX_NPC
	release
	end

PlayersHouse_2F_EventScript_CheatStart2Already::
	addmoney 999999
	addcoins 9999
	additem ITEM_MASTER_BALL, 99
	additem ITEM_RARE_CANDY, 99
	msgbox PlayersHouse_2F_Text_CheatStart2Already, MSGBOX_NPC
	call PlayersHouse_2F_EventScript_ForceHatchEgg_Ask
	call PlayersHouse_2F_EventScript_Bike_Ask
	call PlayersHouse_2F_EventScript_ForceMirageIsland_Ask
	call PlayersHouse_2F_EventScript_ForceShiny_Ask
	release
	end

PlayersHouse_2F_Text_CheatStart2_Ask:
	.string "Activate CheatStart 2.0?$"

PlayersHouse_2F_Text_CheatStart2Activated:
	.string "CheatStart 2.0 Activated!$"

PlayersHouse_2F_Text_CheatStart2Already:
	.string "CheatStart 2.0 already active\n"
	.string "or ELITE FOUR been beaten.\p"
	.string "Resetting money and coins instead!$"

PlayersHouse_2F_EventScript_No::
	return


//force egg hatch
PlayersHouse_2F_EventScript_ForceHatchEgg_Ask::
	msgbox PlayersHouse_2F_Text_ForceHatchEggAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PlayersHouse_2F_EventScript_No
	special ChoosePartyMon
	waitstate
	special EggHatch
	waitstate
	return

PlayersHouse_2F_Text_ForceHatchEggAsk:
	.string "Hatch an egg? MUST HAVE AN EGG\n"
	.string "IN PARTY, OTHERWISE SELECT NO!$"


//swap bikes
PlayersHouse_2F_EventScript_Bike_Ask::
	msgbox PlayersHouse_2F_Text_Bike_Ask, MSGBOX_DEFAULT
	goto_if_eq VAR_RESULT, FALSE, PlayersHouse_2F_EventScript_No
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, PlayersHouse_2F_EventScript_Bike_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, PlayersHouse_2F_EventScript_Bike_SwitchMachForAcro


PlayersHouse_2F_EventScript_Bike_SwitchAcroForMach::
	msgbox PlayersHouse_2F_Text_Bike_SwapAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	special SwapRegisteredBike
	return

PlayersHouse_2F_EventScript_Bike_SwitchMachForAcro::
	msgbox PlayersHouse_2F_Text_Bike_SwapMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	special SwapRegisteredBike
	return

PlayersHouse_2F_Text_Bike_Ask:
	.string "Swap bikes?$"
	
PlayersHouse_2F_Text_Bike_SwapMachForAcro:
	.string "Swapped to ACRO BIKE.$"

PlayersHouse_2F_Text_Bike_SwapAcroForMach:
	.string "Swapped to MACH BIKE.$"


//mirage island
PlayersHouse_2F_EventScript_ForceMirageIsland_Ask::
	msgbox PlayersHouse_2F_Text_ForceMirageIsland_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PlayersHouse_2F_EventScript_ForceMirageIsland_ClearFlag
	goto_if_set FLAG_FORCE_MIRAGE_ISLAND, PlayersHouse_2F_EventScript_ForceMirageIsland_ClearFlag
	setflag FLAG_FORCE_MIRAGE_ISLAND
	msgbox PlayersHouse_2F_Text_ForceMirageIsland_FlagActivated, MSGBOX_NPC
	return

PlayersHouse_2F_EventScript_ForceMirageIsland_ClearFlag::
	clearflag FLAG_FORCE_MIRAGE_ISLAND
	msgbox PlayersHouse_2F_Text_ForceMirageIsland_FlagDeactivated, MSGBOX_NPC
	return

PlayersHouse_2F_Text_ForceMirageIsland_Ask:
	.string "Force Mirage Island to show?"
	
PlayersHouse_2F_Text_ForceMirageIsland_FlagActivated: 
	.string "Mirage Island showing.$"
	
PlayersHouse_2F_Text_ForceMirageIsland_FlagDeactivated: 
	.string "Mirage Island not showing.$"


//force shiny
PlayersHouse_2F_EventScript_ForceShiny_Ask:
	msgbox PlayersHouse_2F_Text_ForceShiny_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, 
	goto_if_set FLAG_FORCE_SHINY, PlayersHouse_2F_EventScript_ForceShiny_ClearFlag
	setflag FLAG_FORCE_SHINY
	msgbox PlayersHouse_2F_Text_ForceShiny_FlagActivated, MSGBOX_NPC
	return

PlayersHouse_2F_EventScript_ForceShiny_ClearFlag::
	clearflag FLAG_FORCE_SHINY
	msgbox PlayersHouse_2F_Text_ForceShiny_FlagDeactivated, MSGBOX_NPC
	return

PlayersHouse_2F_Text_ForceShiny_Ask:
	.string "Force shiny pokemon?$"

PlayersHouse_2F_Text_ForceShiny_FlagActivated: 
	.string "Force Shiny activated.\n"
	.string "All Pokemon will be shiny.$"
	
PlayersHouse_2F_Text_ForceShiny_FlagDeactivated: 
	.string "Force Shiny deactivated.\n"
	.string "Back to normal shiny rates.$"

