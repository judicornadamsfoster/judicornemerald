Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	goto_if_eq VAR_UNUSED_NUMBER_FOSSILS_REVIVED, 4, Route114_FossilManiacsTunnel_EventScript_Found4Fossils
	goto_if_eq VAR_UNUSED_NUMBER_FOSSILS_REVIVED, 6, Route114_FossilManiacsTunnel_EventScript_AnyMoreFossils
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "I'm the FOSSIL MANIAC…\n"
	.string "I'm a nice guy who loves FOSSILS…\p"
	.string "Do you want a FOSSIL?\p"
	.string "But the FOSSILS around these parts all\n"
	.string "belong to me… None for you…\p"
	.string "If you can't bear to go without\n"
	.string "a FOSSIL, look in a desert where there\l"
	.string "are boulders and sand that may hide\l"
	.string "FOSSILS…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "You found a FOSSIL, didn't you?\n"
	.string "That's so nice… It's so dreamy…\p"
	.string "What are you going to do with that\n"
	.string "FOSSIL?\p"
	.string "From what I've heard, DEVON is doing\n"
	.string "research on reviving POKéMON from\l"
	.string "FOSSILS…\p"
	.string "I love my FOSSILS, so I would never\n"
	.string "do anything like that…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "FOSSILS are so… Wonderful…\n"
	.string "It's so dreamy…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh…\n"
	.string "It's not safe that way…\p"
	.string "I was digging away, you see…\n"
	.string "When the whole wall collapsed…\p"
	.string "I think there's a giant cavern\n"
	.string "underneath now…\p"
	.string "But I've left it alone because I don't\n"
	.string "think there are any FOSSILS there…$"



Route114_FossilManiacsTunnel_EventScript_Found4Fossils::
	playse SE_PIN
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_ExclamationMark
	msgbox Route114_FossilManiacsTunnel_Text_Found4Fossils, MSGBOX_DEFAULT
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FOSSIL_MANIAC, Route114_FossilManiacsTunnel_Movement_Heart
	msgbox Route114_FossilManiacsTunnel_Text_YouWillBeManiac, MSGBOX_DEFAULT
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_Reward, MSGBOX_DEFAULT
	giveitem ITEM_OLD_AMBER
//	setvar VAR_UNUSED_NUMBER_FOSSILS_REVIVED, 5
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route114_FossilManiacsTunnel_EventScript_FossilManiacMale
	goto_if_eq VAR_RESULT, FEMALE, Route114_FossilManiacsTunnel_EventScript_FossilManiacFemale
	end
	
Route114_FossilManiacsTunnel_EventScript_FossilManiacMale::
	msgbox Route114_FossilManiacsTunnel_Text_FossilManiacMale, MSGBOX_DEFAULT
	msgbox Route114_FossilManiacsTunnel_Text_End, MSGBOX_DEFAULT
	release
	end
	
Route114_FossilManiacsTunnel_EventScript_FossilManiacFemale::
	msgbox Route114_FossilManiacsTunnel_Text_FossilManiacFemale, MSGBOX_DEFAULT
	msgbox Route114_FossilManiacsTunnel_Text_End, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_AnyMoreFossils::
	msgbox Route114_FossilManiacsTunnel_Text_AnyMoreFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Movement_Heart:
	emote_heart
	step_end

Route114_FossilManiacsTunnel_Text_Found4Fossils:
	.string "YOU'VE FOUND FOUR FOSSILS?$"

Route114_FossilManiacsTunnel_Text_YouWillBeManiac::
	.string "Pretty soon you will be as much of a\n"
	.string "fossil maniac as I am!$"

Route114_FossilManiacsTunnel_Text_Reward::
	.string "I want you to have this.$"

Route114_FossilManiacsTunnel_Text_FossilManiacMale:
	.string "That's an OLD AMBER.\p"
	.string "It's said to contain the dna of an\n"
	.string "ancient POKéMON called AERODACTYL.\p"
	.string "I love fossils, but I think you should\n"
	.string "have it instead, MR FOSSIL MANIAC!\p$"
	
Route114_FossilManiacsTunnel_Text_FossilManiacFemale:
	.string "That's an OLD AMBER.\p"
	.string "It's said to contain the dna of an\n"
	.string "ancient POKéMON called AERODACTYL.\p"
	.string "I love fossils, but I think you should\n"
	.string "have it instead, MISS FOSSIL MANIAC!\p$"

Route114_FossilManiacsTunnel_Text_End:
	.string "Revive it, or keep it as OLD AMBER,\n"
	.string "it's up to you.\p"
	.string "If you ever hear of any more fossils,\n"
	.string "make you sure you come tell me!$"

Route114_FossilManiacsTunnel_Text_AnyMoreFossils:
	.string "Hi, it's good to see you again.\p"
	.string "Have you heard or seen if there are any\n"
	.string "more fossils out there?\p"
	.string "...{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F} ...{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F} ...\p"
	.string "Some have been found in other regions?\p"
	.string "I might have to go travelling soon then.$"
