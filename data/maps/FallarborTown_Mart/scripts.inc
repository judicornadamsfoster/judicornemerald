FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	pokemartlistend

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "I'm having a hard time deciding if I\n"
	.string "should make my SKITTY evolve or not.\p"
	.string "I only have to use this MOON STONE,\n"
	.string "but it's so hard to decide…\p"
	.string "If I make it evolve, it will become\n"
	.string "much stronger.\p"
	.string "But it will look so different, too.$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY: Miyao?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "This NUGGET I found here…\n"
	.string "I suppose I'll have to sell it, seeing\l"
	.string "as how it has no other use.$"


// odd egg script


EventScript_TicketOddEgg_Start::
	lock
	faceplayer
	clearflag FLAG_FORCE_SHINY
	msgbox Text_TicketOddEgg_Start, MSGBOX_DEFAULT
	goto_if_set FLAG_GOT_ODD_EGG, EventScript_TicketOddEgg_AlreadyGot
	checkitem ITEM_EGG_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_ne EventScript_TicketOddEgg_YouHaveEggTicket
	msgbox Text_TicketOddEgg_PleaseTryLater, MSGBOX_DEFAULT
	release
	end

EventScript_TicketOddEgg_YouHaveEggTicket::
	msgbox Text_TicketOddEgg_YouHaveEggTicket, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_TicketOddEgg_Yes
	msgbox Text_TicketOddEgg_HopeToSeeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_TicketOddEgg_Yes::
	getpartysize
	compare VAR_RESULT, 6
	goto_if_ne EventScript_TicketOddEgg_GiveEgg
	msgbox Text_TicketOddEgg_NoSpace, MSGBOX_DEFAULT
	release
	end

EventScript_TicketOddEgg_GiveEgg::
	msgbox Text_TicketOddEgg_LetsGetStarted, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox Text_TicketOddEgg_HandedTicket, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	removeitem ITEM_EGG_TICKET
	msgbox Text_TicketOddEgg_HereItIs, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare	
	msgbox Text_TicketOddEgg_ReceivedOddEgg, MSGBOX_DEFAULT

    random 2
    switch VAR_RESULT
    case 0, EventScript_TicketOddEgg_IsShiny
    case 1, EventScript_TicketOddEgg_IsNotShiny
	
EventScript_TicketOddEgg_IsShiny:
	setflag FLAG_FORCE_SHINY
	special GiveOddEgg
	msgbox Text_TicketOddEgg_RaiseWithLovingCare, MSGBOX_DEFAULT
	setflag FLAG_GOT_ODD_EGG
	clearflag FLAG_FORCE_SHINY
	release
	end

EventScript_TicketOddEgg_IsNotShiny:
	special GiveOddEgg
	msgbox Text_TicketOddEgg_RaiseWithLovingCare, MSGBOX_DEFAULT
	setflag FLAG_GOT_ODD_EGG
	release
	end

EventScript_TicketOddEgg_AlreadyGot::
	msgbox Text_TicketOddEgg_AlreadyGot, MSGBOX_DEFAULT
	release
	end
	
Text_TicketOddEgg_Start:
	.string "Hello!\p"
	.string "Welcome to the FALLARBOR MART\n"
	.string "'ODD EGG GIVEAWAY'.$"

Text_TicketOddEgg_YouHaveEggTicket:
	.string "Oh!\n"
	.string "I see you have an EGG TICKET!\p"
	.string "It's a coupon that special people\n"
	.string "can redeem for a special POKéMON!\p"
	.string "We have a few left, so an ODD EGG\n"
	.string "is available just for you.\p"
	.string "Would you like to redeem your\n"
	.string "EGG TICKET?$"

Text_TicketOddEgg_LetsGetStarted:
	.string "Great!\n"
	.string "Let's get started.$"

Text_TicketOddEgg_HandedTicket:
	.string "{PLAYER} handed the EGG TICKET to\n"
	.string "the staff member.$"

Text_TicketOddEgg_HereItIs:
	.string "Thanks.\n"
	.string "Here's your ODD EGG!$"

Text_TicketOddEgg_ReceivedOddEgg:
	.string "{PLAYER} received the ODD EGG\n"
	.string "from the staff member.$"

Text_TicketOddEgg_RaiseWithLovingCare:
	.string "Please raise it with loving care.$"

Text_TicketOddEgg_HopeToSeeAgain:
	.string "No problem.\n"
	.string "We hope to see you again.$"

Text_TicketOddEgg_NoSpace:
	.string "Oh, you can't carry any more\n"
	.string "POKéMON with you, it seems.\p"
	.string "Please make room in your party,\n"
	.string "then come see me.$"

Text_TicketOddEgg_PleaseTryLater:
	.string "We're still getting things set\n"
	.string "up for the promotion…\p"
	.string "Please try again later.$"

Text_TicketOddEgg_AlreadyGot:
	.string "Oh… I remember you.\p"
	.string "How is the EGG that you received?\n"
	.string "Have you hatched it yet?$"



EventScript_JealousGirl_Start::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EGG_TICKET, EventScript_JealousGirl_YouHaveTicket
	goto_if_unset FLAG_RECEIVED_EGG_TICKET, EventScript_JealousGirl_StoppedGiving

EventScript_JealousGirl_YouHaveTicket::
	msgbox Text_JealousGirl_StoppedGiving, MSGBOX_DEFAULT
	msgbox Text_JealousGirl_YouHaveTicket, MSGBOX_DEFAULT
	release
	end

EventScript_JealousGirl_StoppedGiving::
	msgbox Text_JealousGirl_StoppedGiving, MSGBOX_DEFAULT
	release
	end

Text_JealousGirl_YouHaveTicket:
	.string "Oh, you have an EGG TICKET?\n"
	.string "Maybe they still have some EGGS!$"

Text_JealousGirl_StoppedGiving:
	.string "I'm jealous! They stopped giving\n"
	.string "those EGG TICKETS away earlier\l"
	.string "because their supply ran out.$"

