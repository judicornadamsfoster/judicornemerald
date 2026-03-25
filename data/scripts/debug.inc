Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end

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
	release
	end

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






Debug_Script_3::
	end

Debug_Script_4::
	end

Debug_Script_5::
	end

Debug_Script_6::
	end

Debug_Script_7::
	end

Debug_Script_8::
	end
