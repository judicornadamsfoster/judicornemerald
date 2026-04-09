Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end

/*
Debug_CheatStart::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
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
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	closemessage
	releaseall
	end
*/

Debug_CheatStart::
	goto CheatStart_EventStart_CheatStart2_Ask

// cheatstart2
CheatStart_EventStart_CheatStart2_Ask::
	lockall
	goto_if_set FLAG_LANDMARK_POKEMON_LEAGUE, CheatStart_EventStart_CheatStart2Already
	msgbox CheatStart_Text_CheatStart2_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, CheatStart_EventStart_CheatStart2_Yes
	goto_if_eq VAR_RESULT, FALSE, CheatStart_EventStart_CheatStart2_No


CheatStart_EventStart_CheatStart2_No:
	releaseall
	end

CheatStart_EventStart_CheatStart2_Yes::

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

/*
//other items
	additem ITEM_COIN_CASE
*/

/*
// for mirage island event
	additem ITEM_RUBY
	additem ITEM_SAPPHIRE
*/

/*
//for devon corp fossill reviver and fossil maniac
	additem ITEM_CLAW_FOSSIL
	additem ITEM_ROOT_FOSSIL
	additem ITEM_DOME_FOSSIL
	additem ITEM_HELIX_FOSSIL
*/

	additem ITEM_MASTER_BALL, 99
	additem ITEM_RARE_CANDY, 99
	additem ITEM_SUPER_ROD
	addmoney 999999
	addcoins 9999

	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	msgbox CheatStart_Text_CheatStart2Activated, MSGBOX_DEFAULT
	releaseall
	end

CheatStart_EventStart_CheatStart2Already::
	addmoney 999999
	addcoins 9999
	additem ITEM_MASTER_BALL, 99
	additem ITEM_RARE_CANDY, 99
	msgbox CheatStart_Text_CheatStart2Already, MSGBOX_DEFAULT
	end

CheatStart_Text_CheatStart2_Ask:
	.string "Activate CheatStart 2.0?$"

CheatStart_Text_CheatStart2Activated:
	.string "CheatStart 2.0 Activated!$"

CheatStart_Text_CheatStart2Already:
	.string "CheatStart 2.0 active or game clear.\n"
	.string "Resetting money and coins instead!$"



//sets and clears FLAG_SYS_GAME_CLEAR
Debug_Script_1::
	lock
	goto_if_set FLAG_SYS_GAME_CLEAR, Debug_Script_1_Clear
	setflag FLAG_SYS_GAME_CLEAR
	msgbox Debug_Script_1_Text_Set, MSGBOX_DEFAULT
	release
	end

Debug_Script_1_Clear:
	clearflag FLAG_SYS_GAME_CLEAR
	msgbox Debug_Script_1_Text_Clear, MSGBOX_DEFAULT
	release
	end

Debug_Script_1_Text_Set:
	.string "FLAG SYS GAME CLEAR set.$"

Debug_Script_1_Text_Clear:
	.string "FLAG SYS GAME CLEAR cleared.$"


//sets and clears FLAG_OPEN_ALTERING_CAVE
Debug_Script_2::
	lock
	goto_if_set FLAG_OPEN_ALTERING_CAVE, Debug_Script_2_Clear
	setflag FLAG_OPEN_ALTERING_CAVE
	msgbox Debug_Script_2_Text_Set, MSGBOX_DEFAULT
	release
	end

Debug_Script_2_Clear:
	clearflag FLAG_OPEN_ALTERING_CAVE
	msgbox Debug_Script_2_Text_Clear, MSGBOX_DEFAULT
	release
	end

Debug_Script_2_Text_Set:
	.string "FLAG OPEN ALTERING CAVE set.$"

Debug_Script_2_Text_Clear:
	.string "FLAG OPEN ALTERING CAVE cleared.$"


//egg hatch
Debug_Script_3::
	lock
	msgbox Debug_Script_3_Text_ForceHatchEgg_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Debug_Script_3_EventScript_No
	special ChoosePartyMon
	waitstate
	special EggHatch
	waitstate
	release
	end

Debug_Script_3_EventScript_No:
	release
	end

Debug_Script_3_Text_ForceHatchEgg_Ask:
	.string "Hatch an egg? MUST HAVE AN EGG\n"
	.string "IN PARTY, OTHERWISE SELECT NO!$"


//mirage island
Debug_Script_4::
	msgbox Debug_Script_4_Text_ForceMirageIsland_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Debug_Script_4_EventScript_ForceMirageIsland_ClearFlag
	goto_if_set FLAG_FORCE_MIRAGE_ISLAND, Debug_Script_4_EventScript_ForceMirageIsland_ClearFlag
	setflag FLAG_FORCE_MIRAGE_ISLAND
	msgbox Debug_Script_4_Text_ForceMirageIsland_FlagActivated, MSGBOX_NPC
	return

Debug_Script_4_EventScript_ForceMirageIsland_ClearFlag::
	clearflag FLAG_FORCE_MIRAGE_ISLAND
	msgbox Debug_Script_4_Text_ForceMirageIsland_FlagDeactivated, MSGBOX_NPC
	return

Debug_Script_4_Text_ForceMirageIsland_Ask:
	.string "Force Mirage Island to show?$"
	
Debug_Script_4_Text_ForceMirageIsland_FlagActivated: 
	.string "Mirage Island showing.$"
	
Debug_Script_4_Text_ForceMirageIsland_FlagDeactivated: 
	.string "Mirage Island not showing.$"


//force shiny encounter
Debug_Script_5::
	msgbox Debug_Script_5_Text_ForceShiny_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Debug_Script_5_EventScript_ForceShiny_ClearFlag
	goto_if_set FLAG_FORCE_SHINY, Debug_Script_5_EventScript_ForceShiny_ClearFlag
	setflag FLAG_FORCE_SHINY
	msgbox Debug_Script_5_Text_ForceShiny_FlagActivated, MSGBOX_NPC
	return

Debug_Script_5_EventScript_ForceShiny_ClearFlag::
	clearflag FLAG_FORCE_SHINY
	msgbox Debug_Script_5_Text_ForceShiny_FlagDeactivated, MSGBOX_NPC
	release
	end

Debug_Script_5_Text_ForceShiny_Ask:
	.string "Force shiny pokemon?$"

Debug_Script_5_Text_ForceShiny_FlagActivated: 
	.string "Force Shiny activated.\n"
	.string "All Pokemon will be shiny.$"
	
Debug_Script_5_Text_ForceShiny_FlagDeactivated: 
	.string "Force Shiny deactivated.\n"
	.string "Back to normal shiny rates.$"


Debug_Script_6::
	end

Debug_Script_7::
	end

Debug_Script_8::
	end
