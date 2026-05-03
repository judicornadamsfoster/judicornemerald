RustboroCity_Flat2_Basement_MapScripts::
	.byte 0


//swablu
EventScript_BoxRSGiftEgg_Cousin1::
	lock
	faceplayer
	goto_if_set FLAG_FALSE_SWIPE_SWABLU, EventScript_BoxRSGiftEgg_DontHaveAny
	msgbox Text_BoxRSGiftEgg_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_BoxRSGiftEgg_No
	goto EventScript_BoxRSGiftEgg_GiveIfPossible_Swablu
	release
	end

//zigzagoon
EventScript_BoxRSGiftEgg_Cousin2::
	lock
	faceplayer
	goto_if_set FLAG_EXTREME_SPEED_ZIGZAGOON, EventScript_BoxRSGiftEgg_DontHaveAny
	msgbox Text_BoxRSGiftEgg_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_BoxRSGiftEgg_No
	goto EventScript_BoxRSGiftEgg_GiveIfPossible_Zigzagoon
	release
	end

//skitty
EventScript_BoxRSGiftEgg_Cousin3::
	lock
	faceplayer
	goto_if_set FLAG_PAY_DAY_SKITTY, EventScript_BoxRSGiftEgg_DontHaveAny
	msgbox Text_BoxRSGiftEgg_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_BoxRSGiftEgg_No
	goto EventScript_BoxRSGiftEgg_GiveIfPossible_Skitty
	release
	end

EventScript_BoxRSGiftEgg_No::
	msgbox Text_BoxRSGiftEgg_No MSGBOX_DEFAULT
	release
	end


EventScript_BoxRSGiftEgg_GiveIfPossible_Swablu:
	specialvar VAR_GIFT_UNUSED_1, CalculatePlayerPartyCount
	goto_if_eq VAR_GIFT_UNUSED_1, PARTY_SIZE, EventScript_BoxRSGiftEgg_FullParty
	call EventScript_BoxRSGiftEgg_GiveSwabluEgg
	goto EventScript_BoxRSGiftEgg_ReceivedEgg

EventScript_BoxRSGiftEgg_GiveIfPossible_Zigzagoon:
	specialvar VAR_GIFT_UNUSED_2, CalculatePlayerPartyCount
	goto_if_eq VAR_GIFT_UNUSED_2, PARTY_SIZE, EventScript_BoxRSGiftEgg_FullParty
	call EventScript_BoxRSGiftEgg_GiveZigzagoonEgg
	goto EventScript_BoxRSGiftEgg_ReceivedEgg

EventScript_BoxRSGiftEgg_GiveIfPossible_Skitty:
	specialvar VAR_GIFT_UNUSED_3, CalculatePlayerPartyCount
	goto_if_eq VAR_GIFT_UNUSED_3, PARTY_SIZE, EventScript_BoxRSGiftEgg_FullParty
	call EventScript_BoxRSGiftEgg_GiveSkittyEgg
	goto EventScript_BoxRSGiftEgg_ReceivedEgg

EventScript_BoxRSGiftEgg_FullParty:
	msgbox Text_BoxRSGiftEgg_FullParty, MSGBOX_DEFAULT
	release
	end

EventScript_BoxRSGiftEgg_DontHaveAny:
	msgbox Text_BoxRSGiftEgg_DontHaveAny, MSGBOX_DEFAULT
	release
	end

EventScript_BoxRSGiftEgg_ReceivedEgg:
	lock
	faceplayer
	msgbox Text_BoxRSGiftEgg_ReceiveEgg, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Text_BoxRSGiftEgg_LookAfterEgg, MSGBOX_DEFAULT
	release
	end

EventScript_BoxRSGiftEgg_GiveSwabluEgg:
	giveegg SPECIES_SWABLU
	call_if_eq VAR_GIFT_UNUSED_1, 1, FalseSwipeSwablu_Slot1
	call_if_eq VAR_GIFT_UNUSED_1, 2, FalseSwipeSwablu_Slot2
	call_if_eq VAR_GIFT_UNUSED_1, 3, FalseSwipeSwablu_Slot3
	call_if_eq VAR_GIFT_UNUSED_1, 4, FalseSwipeSwablu_Slot4
	call_if_eq VAR_GIFT_UNUSED_1, 5, FalseSwipeSwablu_Slot5
	setflag FLAG_FALSE_SWIPE_SWABLU
	return

EventScript_BoxRSGiftEgg_GiveZigzagoonEgg:
	giveegg SPECIES_ZIGZAGOON
	call_if_eq VAR_GIFT_UNUSED_2, 1, ExtremeSpeedZigzagoon_Slot1
	call_if_eq VAR_GIFT_UNUSED_2, 2, ExtremeSpeedZigzagoon_Slot2
	call_if_eq VAR_GIFT_UNUSED_2, 3, ExtremeSpeedZigzagoon_Slot3
	call_if_eq VAR_GIFT_UNUSED_2, 4, ExtremeSpeedZigzagoon_Slot4
	call_if_eq VAR_GIFT_UNUSED_2, 5, ExtremeSpeedZigzagoon_Slot5
	setflag FLAG_EXTREME_SPEED_ZIGZAGOON
	return

EventScript_BoxRSGiftEgg_GiveSkittyEgg:
	giveegg SPECIES_SKITTY
	call_if_eq VAR_GIFT_UNUSED_3, 1, PayDaySkitty_Slot1
	call_if_eq VAR_GIFT_UNUSED_3, 2, PayDaySkitty_Slot2
	call_if_eq VAR_GIFT_UNUSED_3, 3, PayDaySkitty_Slot3
	call_if_eq VAR_GIFT_UNUSED_3, 4, PayDaySkitty_Slot4
	call_if_eq VAR_GIFT_UNUSED_3, 5, PayDaySkitty_Slot5
	setflag FLAG_PAY_DAY_SKITTY
	return

FalseSwipeSwablu_Slot1:
	setmonmove 1, 2, MOVE_FALSE_SWIPE
	return

FalseSwipeSwablu_Slot2::
	setmonmove 2, 2, MOVE_FALSE_SWIPE
	return

FalseSwipeSwablu_Slot3:
	setmonmove 3, 2, MOVE_FALSE_SWIPE
	return

FalseSwipeSwablu_Slot4:
	setmonmove 4, 2, MOVE_FALSE_SWIPE
	return

FalseSwipeSwablu_Slot5:
	setmonmove 5, 2, MOVE_FALSE_SWIPE
	return

ExtremeSpeedZigzagoon_Slot1:
	setmonmove 1, 2, MOVE_EXTREME_SPEED
	return

ExtremeSpeedZigzagoon_Slot2::
	setmonmove 2, 2, MOVE_EXTREME_SPEED
	return

ExtremeSpeedZigzagoon_Slot3:
	setmonmove 3, 2, MOVE_EXTREME_SPEED
	return

ExtremeSpeedZigzagoon_Slot4:
	setmonmove 4, 2, MOVE_EXTREME_SPEED
	return

ExtremeSpeedZigzagoon_Slot5:
	setmonmove 5, 2, MOVE_EXTREME_SPEED
	return

PayDaySkitty_Slot1:
	setmonmove 1, 2, MOVE_PAY_DAY
	return

PayDaySkitty_Slot2::
	setmonmove 2, 2, MOVE_PAY_DAY
	return

PayDaySkitty_Slot3:
	setmonmove 3, 2, MOVE_PAY_DAY
	return

PayDaySkitty_Slot4:
	setmonmove 4, 2, MOVE_PAY_DAY
	return

PayDaySkitty_Slot5:
	setmonmove 5, 2, MOVE_PAY_DAY
	return


Text_BoxRSGiftEgg_Ask:
	.string "I'm one of three cousins.\p"
	.string "Our uncle was breeding POKéMON to\n"
	.string "make the best competitive fighter.\p"
	.string "He gave us any extra EGGS that he\n"
	.string "doesn't need.\p"
	.string "Would you take one?$"

Text_BoxRSGiftEgg_No:
	.string "Aww, OK then…\p"
	.string "If you change your mind, let me know.$"

Text_BoxRSGiftEgg_ReceiveEgg:
	.string "{PLAYER} received the EGG.$"

Text_BoxRSGiftEgg_FullParty:
	.string "Oh, your party appears to be full.\p"
	.string "Maybe you could store one of your\n"
	.string "POKéMON in your PC.$"

Text_BoxRSGiftEgg_LookAfterEgg:
	.string "Please raise it with love.\p"
	.string "You should speak to my other cousins\n"
	.string "to see if they still have their EGGS.$"

Text_BoxRSGiftEgg_DontHaveAny:
	.string "I don't have any more EGGS.\p"
	.string "You should speak to my other cousins\n"
	.string "to see if they still have their EGGS.$"

//uncle
EventScript_BoxRSGiftEgg_Uncle::
	lock
	faceplayer
	msgbox Text_BoxRSGiftEgg_Uncle1, MSGBOX_DEFAULT
	waitmessage
	showmonpic SPECIES_FARFETCHD, 10, 3
	waitbuttonpress
	hidemonpic
	msgbox Text_BoxRSGiftEgg_Uncle2, MSGBOX_DEFAULT
	release
	end

Text_BoxRSGiftEgg_Uncle1:
	.string "I've been breeding POKéMON to make\n"
	.string "the strongest and best competitive\l"
	.string "fighter for taking on the ELITE FOUR.\p"
	.string "Want to see it?$"

Text_BoxRSGiftEgg_Uncle2:
	.string "...\p"
	.string "You mean FARFETCH'D ISN'T that stong?\p"
	.string "Guess I better start again...$"

