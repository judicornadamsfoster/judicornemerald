Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route114_LanettesHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	call_if_ge VAR_BILL_STATE, 8, Route114_LanettesHouse_ShowBill
	call_if_lt VAR_BILL_STATE, 8, Route114_LanettesHouse_HideBill
	end
	
Route114_LanettesHouse_OnLoad:
	call_if_ge VAR_BILL_STATE, 8, Route114_LanettesHouse_ShowBill
	call_if_lt VAR_BILL_STATE, 8, Route114_LanettesHouse_HideBill
	return

Route114_LanettesHouse_HideBill::
	setflag FLAG_HIDE_BILL_LANETTES
	end

Route114_LanettesHouse_ShowBill::
	clearflag FLAG_HIDE_BILL_LANETTES
	end


//original script
Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end


//Bill event
Route114_LanettesHouse_EventScript_OfferAdvice::
	goto_if_eq VAR_BILL_STATE, 8, Route114_LanettesHouse_EventScript_Lanette8910
	goto_if_eq VAR_BILL_STATE, 9, Route114_LanettesHouse_EventScript_Lanette8910
	goto_if_eq VAR_BILL_STATE, 10, Route114_LanettesHouse_EventScript_Lanette8910
	goto_if_eq VAR_BILL_STATE, 11, Route114_LanettesHouse_EventScript_Lanette11
	goto_if_eq VAR_BILL_STATE, 12, Route114_LanettesHouse_EventScript_Lanette12
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Lanette8910:
	msgbox Route114_LanettesHouse_Text_Lanette8910, MSGBOX_NPC
	end

Route114_LanettesHouse_EventScript_Lanette11:
	msgbox Route114_LanettesHouse_Text_Lanette11, MSGBOX_NPC
	end

Route114_LanettesHouse_EventScript_Lanette12:
	msgbox Route114_LanettesHouse_Text_Lanette12, MSGBOX_NPC
	end

Route114_LanettesHouse_Text_Lanette8910:
	.string "LANETTE: {PLAYER}, hi.\p"
	.string "BILL'S helping me correct my code to\n"
	.string "connect to the KANTO servers.$"

Route114_LanettesHouse_Text_Lanette11:
	.string "LANETTE: I think BILL is getting used\n"
	.string "to living in my messy house.$"

Route114_LanettesHouse_Text_Lanette12:
	.string "LANETTE: I think BILL is getting used\n"
	.string "to living in my messy house.\p"
	.string "Especially if we have a new project\n"
	.string "to connect to SINNOH.$"


Route114_LanettesHouse_EventScript_Bill_Start::
	goto_if_eq VAR_BILL_STATE, 8, Route114_LanettesHouse_EventScript_Bill8
	goto_if_eq VAR_BILL_STATE, 9, Route114_LanettesHouse_EventScript_Bill9
	goto_if_eq VAR_BILL_STATE, 10, Route114_LanettesHouse_EventScript_Bill10
	goto_if_eq VAR_BILL_STATE, 11, Route114_LanettesHouse_EventScript_Bill11
	goto_if_eq VAR_BILL_STATE, 12, Route114_LanettesHouse_EventScript_Bill12
	msgbox Route114_LanettesHouse_Text_BillPre8, MSGBOX_NPC
	end
	
Route114_LanettesHouse_EventScript_Bill8:
	msgbox Route114_LanettesHouse_Text_Bill8, MSGBOX_NPC
	end

Route114_LanettesHouse_EventScript_Bill9:
	goto_if_eq VAR_ROAMER_POKEMON, 0, Route114_LanettesHouse_EventScript_Bill9_Latios
	goto_if_ne VAR_ROAMER_POKEMON, 0, Route114_LanettesHouse_EventScript_Bill9_Latias

Route114_LanettesHouse_EventScript_Bill9_Latios:
	msgbox Route114_LanettesHouse_Text_Bill9_Latios, MSGBOX_NPC
	setvar VAR_BILL_STATE, 10
	end
	
Route114_LanettesHouse_EventScript_Bill9_Latias:
	msgbox Route114_LanettesHouse_Text_Bill9_Latias, MSGBOX_NPC
	setvar VAR_BILL_STATE, 10
	end

Route114_LanettesHouse_EventScript_Bill10:
	msgbox Route114_LanettesHouse_Text_Bill10, MSGBOX_NPC
	end

Route114_LanettesHouse_EventScript_Bill11:
	msgbox Route114_LanettesHouse_Text_Bill11, MSGBOX_NPC
	setvar VAR_BILL_STATE, 12
	end

Route114_LanettesHouse_EventScript_Bill12:
	msgbox Route114_LanettesHouse_Text_Bill12, MSGBOX_NPC
	end

Route114_LanettesHouse_Text_BillPre8:
	.string "You shouldn't be able to talk to me!$"

Route114_LanettesHouse_Text_Bill8:
	.string "BILL: Hi {PLAYER}.\p"
	.string "How have you been since I saw you at\n"
	.string "the BATTLE FRONTIER?\p"
	.string "...\p"
	.string "Have you been to SOUTHERN ISLAND yet?$"

Route114_LanettesHouse_Text_Bill9_Latios:
	.string "BILL: Hi {PLAYER}, it's good to see\n"
	.string "you, how have you been?\p"
	.string "...\p"
	.string "You caught LATIOS on SOUTHERN ISLAND?\n"
	.string "Congratulations.\p"
	.string "I've been thinking about the island.\n"
	.string "Do you think something might happen\p"
	.string "if both LATIAS and LATIOS were both\n"
	.string "to be there at the same time?$"
	
Route114_LanettesHouse_Text_Bill9_Latias:
	.string "BILL: Hi {PLAYER}, it's good to see\n"
	.string "you, how have you been?\p"
	.string "...\p"
	.string "You caught LATIAS on SOUTHERN ISLAND?\n"
	.string "Congratulations.\p"
	.string "I've been thinking about the island.\n"
	.string "Do you think something might happen\l"
	.string "if both LATIAS and LATIOS were both\l"
	.string "to be there at the same time?$"	
	
Route114_LanettesHouse_Text_Bill10:
	.string "BILL: Have you taken both LATIAS and\n"
	.string "LATIOS back to SOUTHERN ISLAND?\p"
	.string "I'd love to know if my hunch is\n"
	.string "right.$"

Route114_LanettesHouse_Text_Bill11:
	.string "BILL: Hi {PLAYER}, it's good to see\n"
	.string "you again, have you travelled far?\p"
	.string "...\p"
	.string "A cave opened up on SOUTHERN ISLAND?\p"
	.string "That's amazing, I guess my hunch was\n"
	.string "right after all.\p"
	.string "It's a shame I won't be able to go\n"
	.string "investigate, but LANETTE and me have\p"
	.string "been asked to try and link up our\n"
	.string "STORAGE SYSTEMS to our friend BEBE'S\l"
	.string "in the SINNOH region.\p"
	.string "I could be staying here for a while.$"

Route114_LanettesHouse_Text_Bill12:
	.string "BILL: Hi {PLAYER}.\p"
	.string "I'm still working on linking the\n"
	.string "POKéMON STORAGE SYSTEMS with our\l"
	.string "friend BEBE in SINNOH.\p"
	.string "It's going to take months I think.\p"
	.string "But I'm having a good time staying\n"
	.string "in HOENN.\p"
	.string "I don't miss JOHTO much anymore.$"


//original script
Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry everything is so cluttered…\n"
	.string "When I get engrossed in research,\l"
	.string "things end up this way…\p"
	.string "This is embarrassing… Please keep\n"
	.string "this a secret in exchange for this.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "May I offer advice about my POKéMON\n"
	.string "Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's LANETTE's research notes.\n"
	.string "There's information about BOXES.\p"
	.string "Design BOXES to hold 30 POKéMON each.\p"
	.string "Each TRAINER should be able to store\n"
	.string "420 POKéMON on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make POKéMON easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "BOX will be made changeable to please\l"
	.string "the stored POKéMON.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a POKéMON, it should be\n"
	.string "sent to the BOX inspected last.\p"
	.string "If that BOX is full, the received\n"
	.string "POKéMON is stored in the next BOX.\p"
	.string "In other words, when a BOX is examined,\n"
	.string "it is automatically selected as the BOX\l"
	.string "to which POKéMON are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL\n"
	.string "… … … … … … … …”$"

