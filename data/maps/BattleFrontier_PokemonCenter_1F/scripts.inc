BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "There was someone here using a \n"
	.string "POKéMON I've never seen before.\p"
	.string "I never learned about it at\n"
	.string "TRAINER'S SCHOOL at least.\p"
	.string "I wonder where you can catch POKéMON\n"
	.string "like that.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "Okay! Next stop, the BATTLE ARENA!\n"
	.string "I'd better get the right POKéMON from\l"
	.string "the PC Storage System.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Giggle… I'm going to go through every\n"
	.string "challenge with just this baby!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY: Mya myaaah!$"


//bill in the pokecenter
BattleFrontier_PokemonCenter_1F_EventScript_Bill_Start::
	goto_if_eq VAR_BILL_STATE, 7, BattleFrontier_PokemonCenter_1F_EventScript_Bill_HaveYouSeen
	lock
	faceplayer
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_SorryILeftYou, MSGBOX_DEFAULT
	call_if_eq VAR_ROAMER_POKEMON, 0, BattleFrontier_PokemonCenter_1F_EventScript_Bill_SeeNewsRed
	call_if_eq VAR_ROAMER_POKEMON, 1, BattleFrontier_PokemonCenter_1F_EventScript_Bill_SeeNewsBlue
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_FindIt, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_PokemonCenter_1F_EventScript_Bill_PlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_PokemonCenter_1F_EventScript_Bill_PlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_PokemonCenter_1F_EventScript_Bill_PlayerEast
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_TakeItem, MSGBOX_DEFAULT
	giveitem ITEM_LUXURY_BALL, 5
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_GoodLuck, MSGBOX_DEFAULT
	setvar VAR_BILL_STATE, 7
	applymovement LOCALID_BILL_BFPC, Common_Movement_FaceRight
	waitmovement 0
	release
	end

BattleFrontier_PokemonCenter_1F_Text_Bill_SorryILeftYou:
	.string "BILL: {PLAYER}, sorry I left you\n"
	.string "behind, I just got so excited to get\l"
	.string "to the POKéCENTER and back to work.$"

BattleFrontier_PokemonCenter_1F_EventScript_Bill_SeeNewsRed:
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_SeeNewsRed, MSGBOX_DEFAULT
	return
	
BattleFrontier_PokemonCenter_1F_Text_Bill_SeeNewsRed:
	.string "Did you see the news flash about the\n"
	.string "red POKéMON flying over HOENN?\p$"
	
BattleFrontier_PokemonCenter_1F_EventScript_Bill_SeeNewsBlue:
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_SeeNewsBlue, MSGBOX_DEFAULT
	return

BattleFrontier_PokemonCenter_1F_Text_Bill_SeeNewsBlue:
	.string "Did you see the news flash about the\n"
	.string "blue POKéMON flying over HOENN?\p$"

BattleFrontier_PokemonCenter_1F_Text_Bill_FindIt:
	.string "I have a theory about what POKéMON\n"
	.string "it is.\p"
	.string "If you see it, please could you come\n"
	.string "and tell me?\p"
	.string "I'd love my theory to be proven\n"
	.string "correct.$"

BattleFrontier_PokemonCenter_1F_EventScript_Bill_PlayerNorth:
	applymovement LOCALID_BILL_BFPC, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return
BattleFrontier_PokemonCenter_1F_EventScript_Bill_PlayerSouth:
	applymovement LOCALID_BILL_BFPC, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return
BattleFrontier_PokemonCenter_1F_EventScript_Bill_PlayerEast:
	applymovement LOCALID_BILL_BFPC, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_PokemonCenter_1F_Text_Bill_TakeItem:
	.string "Take these with you, they may help.$"

BattleFrontier_PokemonCenter_1F_Text_Bill_GoodLuck:
	.string "Good luck {PLAYER}!$"

//when VAR_BILL_STATE=7
BattleFrontier_PokemonCenter_1F_EventScript_Bill_HaveYouSeen:
	lock
	faceplayer
	goto_if_eq VAR_ROAMER_POKEMON, 0, BattleFrontier_PokemonCenter_1F_EventScript_Bill_HaveYouSeenRed
	goto_if_eq VAR_ROAMER_POKEMON, 1, BattleFrontier_PokemonCenter_1F_EventScript_Bill_HaveYouSeenBlue

BattleFrontier_PokemonCenter_1F_EventScript_Bill_HaveYouSeenRed:
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_HaveYouSeenRed, MSGBOX_DEFAULT
	goto_if_mon_seen SPECIES_LATIAS, BattleFrontier_PokemonCenter_1F_EventScript_Bill_SeenLatias
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_NotSeen, MSGBOX_DEFAULT
	applymovement LOCALID_BILL_BFPC, Common_Movement_FaceRight
	waitmovement 0
	release
	end
	
BattleFrontier_PokemonCenter_1F_EventScript_Bill_HaveYouSeenBlue:
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_HaveYouSeenBlue, MSGBOX_DEFAULT
	goto_if_mon_seen SPECIES_LATIOS, BattleFrontier_PokemonCenter_1F_EventScript_Bill_SeenLatios
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_NotSeen, MSGBOX_DEFAULT
	applymovement LOCALID_BILL_BFPC, Common_Movement_FaceRight
	waitmovement 0
	release
	end

BattleFrontier_PokemonCenter_1F_Text_Bill_HaveYouSeenRed:
	.string "Hi {PLAYER}.\p"
	.string "Have you seen the red POKéMON flying\n"
	.string "while on your travels?\p$"

BattleFrontier_PokemonCenter_1F_Text_Bill_HaveYouSeenBlue:
	.string "Hi {PLAYER}.\p"
	.string "Have you seen the blue POKéMON flying\n"
	.string "while on your travels?\p$"

BattleFrontier_PokemonCenter_1F_Text_Bill_NotSeen:
	.string "...\p"
	.string "You haven't seen it yet?\n"
	.string "Keep searching, I know you can do it.$"

BattleFrontier_PokemonCenter_1F_EventScript_Bill_SeenLatias:
	applymovement LOCALID_BILL_BFPC, Common_Movement_ExclamationMark
	waitmovement 0
	goto_if_mon_caught SPECIES_LATIAS, BattleFrontier_PokemonCenter_1F_EventScript_Bill_CaughtLatias
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_SeenLatias, MSGBOX_DEFAULT
	goto BattleFrontier_PokemonCenter_1F_EventScript_Bill_TellSouthernIsland

BattleFrontier_PokemonCenter_1F_EventScript_Bill_SeenLatios:
	applymovement LOCALID_BILL_BFPC, Common_Movement_ExclamationMark
	waitmovement 0
	goto_if_mon_caught SPECIES_LATIOS, BattleFrontier_PokemonCenter_1F_EventScript_Bill_CaughtLatios
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_SeenLatios, MSGBOX_DEFAULT
	goto BattleFrontier_PokemonCenter_1F_EventScript_Bill_TellSouthernIsland

BattleFrontier_PokemonCenter_1F_Text_Bill_SeenLatias:
	.string "...\p"
	.string "You've seen the red POKéMON?\n"
	.string "It was a LATIAS?\p"
	.string "This proves my theory.\n"
	.string "LATIAS is known as the EON POKéMON\l"
	.string "alongside its brother LATIOS.$"

BattleFrontier_PokemonCenter_1F_Text_Bill_SeenLatios:
	.string "...\p"
	.string "You've seen the blue POKéMON?\n"
	.string "It was a LATIOS?\p"
	.string "This proves my theory.\n"
	.string "LATIOS is known as the EON POKéMON\l"
	.string "alongside its sister LATIAS.$"

BattleFrontier_PokemonCenter_1F_EventScript_Bill_CaughtLatias:
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_CaughtLatias, MSGBOX_DEFAULT
	goto BattleFrontier_PokemonCenter_1F_EventScript_Bill_TellSouthernIsland
	
BattleFrontier_PokemonCenter_1F_EventScript_Bill_CaughtLatios:
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_CaughtLatios, MSGBOX_DEFAULT
	goto BattleFrontier_PokemonCenter_1F_EventScript_Bill_TellSouthernIsland

BattleFrontier_PokemonCenter_1F_Text_Bill_CaughtLatias:
	.string "...\p"
	.string "You've caught the red POKéMON?\n"
	.string "It was a LATIAS?\p"
	.string "This proves my theory.\n"
	.string "LATIAS is known as the EON POKéMON\l"
	.string "alongside its brother LATIOS.$"
	
BattleFrontier_PokemonCenter_1F_Text_Bill_CaughtLatios:
	.string "...\p"
	.string "You've caught the blue POKéMON?\n"
	.string "It was a LATIOS?\p"
	.string "This proves my theory.\n"
	.string "LATIOS is known as the EON POKéMON\l"
	.string "alongside its sister LATIAS.$"
	
BattleFrontier_PokemonCenter_1F_EventScript_Bill_TellSouthernIsland:
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_TellSouthernIsland, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_PokemonCenter_1F_Movement_Bill_EonTicketPlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_PokemonCenter_1F_Movement_Bill_EonTicketPlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_PokemonCenter_1F_Movement_Bill_EonTicketPlayerEast
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_HaveMyTicket, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_UseAtLilycovePort, MSGBOX_DEFAULT
	playse SE_POKENAV_CALL
	waitse
	applymovement LOCALID_BILL_BFPC, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_PokemonCenter_1F_Text_Bill_PokenavCall, MSGBOX_DEFAULT
	waitmessage
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_PokemonCenter_1F_EventScript_Bill_LeavePlayerNS
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_PokemonCenter_1F_EventScript_Bill_LeavePlayerNS
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_PokemonCenter_1F_EventScript_Bill_LeavePlayerEast
	playse SE_EXIT
	waitse
	removeobject LOCALID_BILL_BFPC
	setflag FLAG_BILL_BFPC 
	setvar VAR_BILL_STATE, 8
	release
	end

BattleFrontier_PokemonCenter_1F_Text_Bill_TellSouthernIsland:
	.string "There's an island south of HOENN that\n"
	.string "has a connection to the EON POKéMON.\p"
	.string "I've travelled there before haven't\n"
	.string "been able to find anything related to\l"
	.string "LATIAS or LATIOS.\p"
	.string "But if maybe someone was to go there\n"
	.string "if they had either LATIAS or LATIOS\l"
	.string "with them, it may be different.$"

BattleFrontier_PokemonCenter_1F_Movement_Bill_EonTicketPlayerNorth:
	applymovement LOCALID_BILL_BFPC, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return
BattleFrontier_PokemonCenter_1F_Movement_Bill_EonTicketPlayerSouth:
	applymovement LOCALID_BILL_BFPC, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return
BattleFrontier_PokemonCenter_1F_Movement_Bill_EonTicketPlayerEast:
	applymovement LOCALID_BILL_BFPC, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_PokemonCenter_1F_Text_Bill_HaveMyTicket:
	.string "Here, I want you to have my ticket.$"

BattleFrontier_PokemonCenter_1F_Text_Bill_UseAtLilycovePort:
	.string "One of the sailors at LILYCOVE port\n"
	.string "took me there, I'm sure he'll still\l"
	.string "remember how to get there.$"

BattleFrontier_PokemonCenter_1F_Text_Bill_PokenavCall:
	.string "...\p"
	.string "Oh, I'm sorry {PLAYER}, I have to go.\n"
	.string "LANETTE is having issues with her\l"
	.string "latest updates linking to my system.\p"
	.string "Please can you carry on looking for\n"
	.string "the EON POKéMON, and come find me if\n"
	.string "you find anything on SOUTHERN ISLAND.$"

BattleFrontier_PokemonCenter_1F_EventScript_Bill_LeavePlayerNS:
	applymovement LOCALID_BILL_BFPC, BattleFrontier_PokemonCenter_1F_Movement_Bill_LeavePlayerNS
	waitmovement 0
	return

BattleFrontier_PokemonCenter_1F_EventScript_Bill_LeavePlayerEast:
	applymovement LOCALID_BILL_BFPC, BattleFrontier_PokemonCenter_1F_Movement_Bill_LeavePlayerEast
	waitmovement 0
	return

BattleFrontier_PokemonCenter_1F_Movement_Bill_LeavePlayerNS:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

BattleFrontier_PokemonCenter_1F_Movement_Bill_LeavePlayerEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end
