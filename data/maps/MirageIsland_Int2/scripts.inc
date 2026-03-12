MirageIsland_Int2_MapScripts::
	.byte 0



//#define FLAG_UNUSED_0x048    0x48 // Unused Flag
//#define FLAG_MIRAGE_ISLAND_DOME_FOSSIL    0x48 // Unused Flag -tenaya


//sets FLAG_MIRAGE_ISLAND_DOME_FOSSIL
MirageIsland_Int2_EventScript_Dome_Fossil::
	lock
	faceplayer
	giveitem ITEM_DOME_FOSSIL
	removeobject LOCALID_DOME_FOSSIL
	release
	end


