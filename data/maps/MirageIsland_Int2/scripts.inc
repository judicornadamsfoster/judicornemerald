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


//sets FLAG_MIRAGE_ISLAND_ENTEI_1
MirageIsland_Int2_Entei_Trigger::
	lockall
	setvar VAR_0x8008, 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp

	msgbox Text_MirageMan_2c, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Movement_Setup_Player_0
	waitmovement 0
	goto EventScript_MirageMan_DidntWork_1
	end