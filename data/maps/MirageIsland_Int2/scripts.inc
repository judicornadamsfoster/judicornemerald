MirageIsland_Int2_MapScripts::
	.byte 0



//#define FLAG_UNUSED_0x048    0x48 // Unused Flag
//#define FLAG_MIRAGE_ISLAND_DOME_FOSSIL    0x48 // Unused Flag -tenaya

//#define FLAG_UNUSED_0x047    0x47 // Unused Flag
//#define FLAG_MIRAGE_ISLAND_INT2_ITEM     0x47 // Unused Flag

//#define FLAG_UNUSED_0x046    0x46 // Unused Flag
//#define FLAG_MIRAGE_ISLAND_ENTEI_1		0x46 // Unused Flag -tenaya


//sets FLAG_MIRAGE_ISLAND_DOME_FOSSIL
MirageIsland_Int2_EventScript_Dome_Fossil::
	lock
	faceplayer
	giveitem ITEM_DOME_FOSSIL
	removeobject LOCALID_DOME_FOSSIL
	release
	end

//temporary item choice
//sets FLAG_MIRAGE_ISLAND_INT2_ITEM
MirageIsland_Int2_EventScript_Item::
	finditem ITEM_HARD_STONE
	end

MirageIsland_Int2_EventScript_Pikachu::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, 0
	msgbox MirageIsland_Int2_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	msgbox MirageIsland_Int2_Text_WontMove, MSGBOX_DEFAULT
	waitmovement 0
	release
	end

MirageIsland_Int2_Text_Pikachu:
	.string "PIKACHU: Chuuuu!$"

MirageIsland_Int2_Text_WontMove:
	.string "The PIKACHU won't move!$"




//sets FLAG_MIRAGE_ISLAND_ENTEI_1
MirageIsland_Int2_Trigger_EnteiCryCheck::
	goto_if_unset FLAG_MIRAGE_ISLAND_ENTEI_1, MirageIsland_Int2_EventScript_EnteiCry
	end

MirageIsland_Int2_EventScript_EnteiCry::
	lockall
	playmoncry SPECIES_ENTEI, 0
	waitse
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate

	msgbox MirageIsland_Int2_Text_EnteiCry, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	releaseall
	end

MirageIsland_Int2_Trigger_EnteiAppearCheck::
	goto_if_unset FLAG_MIRAGE_ISLAND_ENTEI_1, MirageIsland_Int2_EventScript_EnteiAppear
	end

MirageIsland_Int2_EventScript_EnteiAppear::
	lock
	fadeoutbgm 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_MIRAGE_ENTEI, MirageIsland_Int2_Movement_EnteiAppear
	waitmovement 0
	applymovement LOCALID_MIRAGE_ENTEI, MirageIsland_Int2_Movement_EnteiApproach
	waitmovement 0
	playmoncry SPECIES_ENTEI, 0
	waitse
	msgbox MirageIsland_Int2_Text_Entei, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRAGE_ENTEI, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MIRAGE_ENTEI, MirageIsland_Int2_Movement_EnteiLeave
	applymovement LOCALID_PLAYER, MirageIsland_Int2_Movement_PlayerWatchEnteiLeave
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	removeobject LOCALID_MIRAGE_ENTEI
	msgbox MirageIsland_Int2_Text_EnteiRan, MSGBOX_DEFAULT

	fadeinbgm 0
	setflag FLAG_MIRAGE_ISLAND_ENTEI_1
	release
	end

MirageIsland_Int2_Movement_EnteiAppear:
	walk_left
	walk_left
	walk_left
	step_end
	
MirageIsland_Int2_Movement_EnteiApproach:
	emote_question_mark
	delay_16
	delay_16
	delay_16
	delay_16
	jump_2_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

MirageIsland_Int2_Movement_EnteiLeave:
	lock_facing_direction
	walk_slow_right
	walk_slow_right
	walk_slow_right
	unlock_facing_direction
	jump_2_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MirageIsland_Int2_Movement_PlayerWatchEnteiLeave:
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_up
	delay_16
	delay_16
	delay_16
	delay_16
	step_end


MirageIsland_Int2_Text_EnteiCry:
	.string "A loud roar shook the cave.$"


MirageIsland_Int2_Text_Entei:
	.string "ENTEI: Wraaaoroor!$"


MirageIsland_Int2_Text_EnteiRan:
	.string "The wild ENTEI ran.$"

