.set LOCALID_EMBEDDEDRAYQUAZA, 1
.set LOCALID_EMBEDDEDGROUDON, 1
.set LOCALID_EMBEDDEDKYOGRE, 1

EmbeddedTower_MapScripts::
	.byte 0

EmbeddedTower_EventScript_Groudon::
	lock
	faceplayer
	legendaryencounter SPECIES_GROUDON, 70, LOCALID_EMBEDDEDGROUDON, FLAG_HIDE_GROUDON
	release
	end

EmbeddedTower_EventScript_Kyogre::
	lock
	faceplayer
	legendaryencounter SPECIES_KYOGRE, 70, LOCALID_EMBEDDEDKYOGRE, FLAG_HIDE_KYOGRE
	release
	end

EmbeddedTower_EventScript_Rayquaza::
	lock
	faceplayer
	bosslegendaryencounterwithmoves SPECIES_RAYQUAZA, 70, LOCALID_EMBEDDEDRAYQUAZA, FLAG_HIDE_RAYQUAZA, 4, SPECIES_NONE, 110, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_EXTREMESPEED, MOVE_DRAGON_CLAW, BOSS_PHASE_PROFILE_RAYQUAZA
	release
	end
