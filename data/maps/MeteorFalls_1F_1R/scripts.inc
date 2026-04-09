MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_METEOR_FALLS_ARCHIE
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_2
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_METEOR_FALLS_ARCHIE
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "Hehehe!\p"
	.string "With this METEORITE, that thing in\n"
	.string "MT. CHIMNEY will…$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "Heh?\p"
	.string "I don't know who you are, but if you get\n"
	.string "in the way of TEAM MAGMA, don't\l"
	.string "expect any mercy!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "Hold it right there, TEAM MAGMA!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "Hehehe!\n"
	.string "Even TEAM AQUA joins us!\p"
	.string "But it's too much trouble to deal with\n"
	.string "you all…\p"
	.string "Heh, it doesn't matter!\p"
	.string "We've got the METEORITE, so off to\n"
	.string "MT. CHIMNEY we go!\p"
	.string "Hehehe! Be seeing you, you TEAM\n"
	.string "AQUA dingbats!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "ARCHIE: Didn't I see you before?\n"
	.string "At SLATEPORT's MUSEUM?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of TEAM MAGMA's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "TEAM MAGMA is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "They are the rivals to us,\n"
	.string "the sea-loving TEAM AQUA!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "BOSS, we should give chase to\n"
	.string "TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "ARCHIE: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what TEAM MAGMA\n"
	.string "will do at MT. CHIMNEY!$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "ARCHIE: {PLAYER}, you should keep\n"
	.string "an eye out for TEAM MAGMA, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TEAM AQUA showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"


//
MeteorFalls_1F_1R_EventScript_GiveDeoxys::
	lock
	givemon SPECIES_DEOXYS, 30, ITEM_NONE
	release
	end

//trigger if have deoxys in party
MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_Trigger::
	lock
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerNormal2
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerNormal2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerNormal3
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerNormal3:
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerNormal4
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerNormal4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerNormal5
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerNormal5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerNormal6
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerNormal6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerAttack1
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerAttack1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerAttack2
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerAttack2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerAttack3
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerAttack3:
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerAttack4
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerAttack4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerAttack5
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerAttack5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerAttack6
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerAttack6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerDefense1
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerDefense1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerDefense2
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerDefense2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerDefense3
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerDefense3:
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerDefense4
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerDefense4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerDefense5
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerDefense5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerDefense6
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerDefense6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerSpeed1
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerSpeed1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerSpeed2
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerSpeed2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerSpeed3
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerSpeed3:
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerSpeed4
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerSpeed4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerSpeed5
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerSpeed5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_TriggerSpeed6
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_TriggerSpeed6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_DeoxysEnd
	goto MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont

MeteorFalls_1F_1R_EventScript_MeteorDeoxysNoise_TriggerCont:
	playmoncry SPECIES_DEOXYS, 0
	waitmoncry
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DeoxysMakingNoises, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_F, 1
	release
	end

MeteorFalls_1F_1R_Text_DeoxysMakingNoises:
	.string "DEOXYS is making noises inside it's\n"
	.string "POKéBALL.\p"
	.string "It's reacting to something nearby.$"

//deoxys form change
MeteorFalls_1F_1R_EventScript_DeoxysMeteor::
	lock
	msgbox MeteorFalls_1F_1R_Text_DeoxysMeteor, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto MeteorFalls_1F_1R_EventScript_CheckSlot1

MeteorFalls_1F_1R_EventScript_CheckSlot1::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlot2
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlot2::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlot3
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlot3::	
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlot4
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm
	
MeteorFalls_1F_1R_EventScript_CheckSlot4::
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlot5
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm
	
MeteorFalls_1F_1R_EventScript_CheckSlot5::
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlot6
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlot6::
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotAttack1
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotAttack1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotAttack2
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotAttack2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotAttack3
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotAttack3:	
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotAttack4
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm
	
MeteorFalls_1F_1R_EventScript_CheckSlotAttack4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotAttack5
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm
	
MeteorFalls_1F_1R_EventScript_CheckSlotAttack5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotAttack6
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotAttack6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotDefense1
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotDefense1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotDefense2
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotDefense2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotDefense3
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotDefense3:	
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotDefense4
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm
	
MeteorFalls_1F_1R_EventScript_CheckSlotDefense4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotDefense5
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm
	
MeteorFalls_1F_1R_EventScript_CheckSlotDefense5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotDefense6
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotDefense6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotSpeed1
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotSpeed1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotSpeed2
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotSpeed2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotSpeed3
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotSpeed3:	
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotSpeed4
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm
	
MeteorFalls_1F_1R_EventScript_CheckSlotSpeed4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotSpeed5
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm
	
MeteorFalls_1F_1R_EventScript_CheckSlotSpeed5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_CheckSlotSpeed6
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_CheckSlotSpeed6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_DeoxysEnd
	call MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting
	goto MeteorFalls_1F_1R_ChangeDeoxysForm

MeteorFalls_1F_1R_EventScript_DeoxysEnd:
	release
	end
	
MeteorFalls_1F_1R_Text_DeoxysMeteor:
	.string "It's a meteor.$"

MeteorFalls_1F_1R_EventScript_DeoxysMeteor_Reacting:
	playmoncry SPECIES_DEOXYS, 0
	waitmoncry
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DeoxysReacting, MSGBOX_DEFAULT
	waitmessage
	return

MeteorFalls_1F_1R_Text_DeoxysReacting:
	.string "DEOXYS is reacting to the meteor.\p"
	.string "It's thrashing about in it's POKéBALL.$"


MeteorFalls_1F_1R_ChangeDeoxysForm::
	lockall
	msgbox MeteorFalls_1F_1R_ChangeDeoxysForm_Text_Beginning, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MeteorFalls_1F_1R_ChangeDeoxysForm_Start

MeteorFalls_1F_1R_ChangeDeoxysForm_Start:
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq MeteorFalls_1F_1R_EventScript_DeoxysEnd
	special TryChangeDeoxysForm
	compare VAR_RESULT, TRUE
	goto_if_eq MeteorFalls_1F_1R_ChangeDeoxysForm_Success
	goto MeteorFalls_1F_1R_EventScript_DeoxysEnd

MeteorFalls_1F_1R_ChangeDeoxysForm_Success:
	playmoncry SPECIES_DEOXYS, 0
	waitmoncry
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	goto MeteorFalls_1F_1R_EventScript_ShowPicSlot1

MeteorFalls_1F_1R_EventScript_ShowPicSlot1::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPic2
	showmonpic SPECIES_DEOXYS, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPic2::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPic3
	showmonpic SPECIES_DEOXYS, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPic3::	
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPic4
	showmonpic SPECIES_DEOXYS, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont
	
MeteorFalls_1F_1R_EventScript_ShowPic4::
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPic5
	showmonpic SPECIES_DEOXYS, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont
	
MeteorFalls_1F_1R_EventScript_ShowPic5::
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPic6
	showmonpic SPECIES_DEOXYS, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPic6::
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicAttack1
	showmonpic SPECIES_DEOXYS, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicAttack1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicAttack2
	showmonpic SPECIES_DEOXYS_ATTACK, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicAttack2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicAttack3
	showmonpic SPECIES_DEOXYS_ATTACK, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicAttack3:	
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicAttack4
	showmonpic SPECIES_DEOXYS_ATTACK, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont
	
MeteorFalls_1F_1R_EventScript_ShowPicAttack4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicAttack5
	showmonpic SPECIES_DEOXYS_ATTACK, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont
	
MeteorFalls_1F_1R_EventScript_ShowPicAttack5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicAttack6
	showmonpic SPECIES_DEOXYS_ATTACK, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicAttack6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicDefense1
	showmonpic SPECIES_DEOXYS_ATTACK, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicDefense1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicDefense2
	showmonpic SPECIES_DEOXYS_DEFENSE, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicDefense2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicDefense3
	showmonpic SPECIES_DEOXYS_DEFENSE, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicDefense3:	
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicDefense4
	showmonpic SPECIES_DEOXYS_DEFENSE, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont
	
MeteorFalls_1F_1R_EventScript_ShowPicDefense4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicDefense5
	showmonpic SPECIES_DEOXYS_DEFENSE, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont
	
MeteorFalls_1F_1R_EventScript_ShowPicDefense5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicDefense6
	showmonpic SPECIES_DEOXYS_DEFENSE, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicDefense6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicSpeed1
	showmonpic SPECIES_DEOXYS_DEFENSE, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicSpeed1:
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicSpeed2
	showmonpic SPECIES_DEOXYS_SPEED, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicSpeed2:
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicSpeed3
	showmonpic SPECIES_DEOXYS_SPEED, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicSpeed3:	
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicSpeed4
	showmonpic SPECIES_DEOXYS_SPEED, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont
	
MeteorFalls_1F_1R_EventScript_ShowPicSpeed4:
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicSpeed5
	showmonpic SPECIES_DEOXYS_SPEED, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont
	
MeteorFalls_1F_1R_EventScript_ShowPicSpeed5:
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_ShowPicSpeed6
	showmonpic SPECIES_DEOXYS_SPEED, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_EventScript_ShowPicSpeed6:
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MeteorFalls_1F_1R_EventScript_DeoxysEnd
	showmonpic SPECIES_DEOXYS_SPEED, 10, 3
	goto MeteorFalls_1F_1R_ShowMonPic_Cont

MeteorFalls_1F_1R_ShowMonPic_Cont:
	msgbox MeteorFalls_1F_1R_ChangeDeoxysForm_Text_Success, MSGBOX_DEFAULT
	waitmoncry
	waitmessage
	hidemonpic
	msgbox MeteorFalls_1F_1R_ChangeDeoxysForm_Text_Return, MSGBOX_DEFAULT
	waitmessage	
	goto MeteorFalls_1F_1R_EventScript_DeoxysEnd


MeteorFalls_1F_1R_ChangeDeoxysForm_Text_Beginning:
	.string "Release DEOXYS from it's POKéBALL?$"

MeteorFalls_1F_1R_ChangeDeoxysForm_Text_Success:
	.string "DEOXYS transformed into a new forme!$"

MeteorFalls_1F_1R_ChangeDeoxysForm_Text_Return:
	.string "DEOXYS went back into it's POKéBALL.$"

