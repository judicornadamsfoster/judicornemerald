PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "That PC-based POKéMON Storage\n"
	.string "System…\p"
	.string "Whoever made it must be some kind\n"
	.string "of a scientific wizard!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "When my POKéMON ate an\n"
	.string "ORAN BERRY, it regained HP!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "There are many types of POKéMON.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of POKéMON,\n"
	.string "a battle could be easy or hard.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "For example, your TREECKO\n"
	.string "is a GRASS type.\p"
	.string "It's strong against the WATER and\n"
	.string "GROUND types.\p"
	.string "But, it's weak against FIRE-type\n"
	.string "POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "For example, your TORCHIC\n"
	.string "is a FIRE type.\p"
	.string "It's strong against the GRASS and\n"
	.string "BUG types.\p"
	.string "But, it's weak against WATER-type\n"
	.string "POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "For example, your MUDKIP\n"
	.string "is a WATER type.\p"
	.string "It's strong against the FIRE type.\p"
	.string "But, it's weak against GRASS-type\n"
	.string "and ELECTRIC-type POKéMON.$"



//secretmon salesman
PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_Salesman_Start::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_SECRETMON, PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_AlreadyBought
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_BuyForJustPrice
	showmoneybox 1, 1
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_SoYoullBuyIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_Decline
	goto PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_TryBuy
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_TryBuy::
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_NotEnoughMoney
    getpartysize
    compare VAR_RESULT, 6
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_NoRoom
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_BuyParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_BuyPC
	goto PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_NoRoom
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_BuyParty::
	call PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_PayFor
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_End
	call Common_EventScript_GetGiftMonPartySlot
	goto PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_End
	end
	
PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_BuyPC::
	call PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_PayFor
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_TransferCloseMoneyBox
	goto PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_End
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_End::
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangeBoxPokemonNickname
	setflag FLAG_BOUGHT_SECRETMON
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_TransferCloseMoneyBox::
	call Common_EventScript_TransferredToPC
	hidemoneybox
	setflag FLAG_BOUGHT_SECRETMON
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_Transfer::
	call Common_EventScript_TransferredToPC
	setflag FLAG_BOUGHT_SECRETMON
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_PayFor::
	removemoney 500
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_PaidOutrageouslyFor
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	return

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_Decline::
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_FavorToYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_NotEnoughMoney::
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_YoullNeedMoreMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_AlreadyBought::
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_IDontGiveRefunds, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_NoRoom::
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_NoRoom, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PetalburgCity_PokemonCenter_1F_Text_SecretMon_BuyForJustPrice:
    .string "MAN: Hey there, kiddo!\p"
	.string "I heard you came from the\n"
	.string "KANTO region?\p"
	.string "Well, I'm from KANTO too!\p"
    .string "Have I got a deal just for you!\p"
    .string "I'll let you have a super secret\n"
    .string "POKéMON for just ¥500!$"

PetalburgCity_PokemonCenter_1F_Text_SecretMon_SoYoullBuyIt:
    .string "So, you'll buy it, am I right?$"

PetalburgCity_PokemonCenter_1F_Text_SecretMon_PaidOutrageouslyFor:
    .string "{PLAYER} paid an outrageous ¥500\n"
    .string "and bought a MAGIKARP…$"

PetalburgCity_PokemonCenter_1F_Text_SecretMon_FavorToYou:
    .string "No? You say no? I'm only doing this\n"
    .string "as a favor to you!$"

PetalburgCity_PokemonCenter_1F_Text_SecretMon_NoRoom:
    .string "It looks like there's no room for\n"
    .string "any more POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_SecretMon_YoullNeedMoreMoney:
    .string "You'll need more money than that!$"

PetalburgCity_PokemonCenter_1F_Text_SecretMon_IDontGiveRefunds:
    .string "MAN: I don't give out refunds.\n"
    .string "You should have checked the small print!$"


PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_DodgyMan::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_DodgyMan, MSGBOX_DEFAULT
	goto_if_set FLAG_BOUGHT_SECRETMON, PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_DodgyMan_BoughtIt
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SecretMon_DodgyMan_BoughtIt::
	applymovement LOCALID_DODGYMAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PetalburgCity_PokemonCenter_1F_Text_SecretMon_DodgyMan_Bought, MSGBOX_DEFAULT
	release
	end

PetalburgCity_PokemonCenter_1F_Text_SecretMon_DodgyMan:
	.string "There's a man who keeps offering to\n"
	.string "sell a secret POKéMON for ¥500.\p"
	.string "If you ask me, that seems a bit dodgy!$"

PetalburgCity_PokemonCenter_1F_Text_SecretMon_DodgyMan_Bought:
	.string "You bought it?\p"
	.string "You sucker!$"


