RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "For my own POKéMON, I give them\n"
	.string "perfectly suited nicknames!\p"
	.string "It's my expression of, uh…\n"
	.string "originality, yes, that's it!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "But giving the name PEKACHU to\n"
	.string "a PIKACHU? It seems pointless.\p"
	.string "I suppose it is good to use a name\n"
	.string "that's easy to understand, but…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"



RustboroCity_House3_EventScript_SurfPichu_Start::
	goto_if_set FLAG_SURF_PICHU_EGG, RustboroCity_House3_EventScript_SurfPichu_AlreadyGiven
	goto_if_unset FLAG_SURF_PICHU_EGG, RustboroCity_House3_EventScript_SurfPichu_Ask

RustboroCity_House3_EventScript_SurfPichu_AlreadyGiven::
	msgbox RustboroCity_House3_Text_SurfPichu_AlreadyGiven, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_House3_EventScript_SurfPichu_Ask::
	lock
	faceplayer
	msgbox RustboroCity_House3_Text_SurfPichu_Start, MSGBOX_DEFAULT
	msgbox RustboroCity_House3_Text_SurfPichu_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House3_EventScript_SurfPichu_No
	goto RustboroCity_House3_EventScript_SurfPichu_Call
	release
	end

RustboroCity_House3_EventScript_SurfPichu_No::
	msgbox RustboroCity_House3_Text_SurfPichu_No MSGBOX_DEFAULT
	release
	end
	
RustboroCity_House3_EventScript_SurfPichu_Call::
	setflag FLAG_SURF_PICHU_EGG
	call MysteryGiftScript_SurfPichu
	end	

RustboroCity_House3_Text_SurfPichu_AlreadyGiven:
	.string "How's the POKéMON EGG I gave you?$"

RustboroCity_House3_Text_SurfPichu_Start:
	.string "My parents got this EGG after leaving\n"
	.string "their PIKACHU at the DAYCARE CENTER,\l"
	.string "but they aren't able to raise any\l"
	.string "more POKéMON.$"

RustboroCity_House3_Text_SurfPichu_Ask:
	.string "Would you like it?$"

RustboroCity_House3_Text_SurfPichu_No:
	.string "Aww, OK then…$"

RustboroCity_House3_EventScript_Kid::
	msgbox RustboroCity_House3_Text_Kid, MSGBOX_NPC
	end

RustboroCity_House3_Text_Kid:
	.string "I'm helping Mommy clean Meemaw and\n"
	.string "Peepaw's house!$"

