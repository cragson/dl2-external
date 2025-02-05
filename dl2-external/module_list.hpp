#pragma once

#include "offsets.hpp"
#include "globals.hpp"

// fml, I ain't gonna do that manually fuck that shit
// To be continued (in a far far away galaxy)
enum MODULE_LIST_ENTRY : uint32_t
{
	MoveController = 0,
	LookController,
	WeaponThrowController,
	JumpController,
	DefensiveController,
	TackleController,
	ShieldController,
	WrestleKickController,
	LeapTackleController,
	PlayerAppearanceModule = 0x40,
	PlayerInfectionModule,
	PlayerDetectorModule,
	PlayerStaminaModule,
	PlayerChemicalModule,
	PlayerScreamModule,
	PlayerFallHelperModule,
	PlayerSkillCooldownModule,
	PlayerCableModule,
	PlayerCamouflageModule,
	PlayerGroupDamageModule,
	PlayerDuckModule,
	PlayerRunnerExperienceModule,
	PlayerNightExperienceModule /* lol dev made spelling mistake in game calling it the PlayerNightExpierinceModule */,
	PlayerElementalModule,
	PlayerVehicleModule,
	PlayerFlashlightModule,
	PlayerSlowmoModule,
	PlayerCollisionDamagerModule,
	PlayerArrowSelectionModule,
	PlayerBoltSelectionModule,
	PlayerInventoryModule,
	PlayerHealthModule,
	PlayerBinocularLocalizationModule,
	PlayerAutoAimingModule,
	PlayerClimbModule,
	PlayerIKHandsToHookModule,
	PlayerReplicatedDamageModule,
	PlayerBulletPhysicalModule,
	PlayerVolumetricDamageModule,
	PlayerJumpAttackModule,
	PlayerPassengerModule,
	PlayerParkourFlowModule,
	PlayerTarGrabModule,
	PlayerDifficultyModule,
	PlayerRoleModule,
	CombatActorModulePlayer,
	PlayerChaseModule,
	PlayerEvolvingItemModule,
	PlayerFuryModule,
	PlayerBarkModule,
};

namespace module_list
{
	[[nodiscard]] const inline std::uintptr_t get_decrypted_module_list_ptr()
	{
		const auto tbl = Globals::g_pProcess->read< std::uintptr_t >(Offsets::module_list_constant_encrypted);

		if (!tbl)
			return {};

		const auto encrypted_list_ptr = Globals::g_pProcess->read< std::uintptr_t >(tbl + 0x1C8);

		if (!encrypted_list_ptr)
			return {};

		return encrypted_list_ptr & 0x0000FFFFFFFFFFFF;
	}

	[[nodiscard]] const inline std::uintptr_t get_module_by_index(const uint32_t idx)
	{
		const auto module_list_ptr = get_decrypted_module_list_ptr();

		if (!module_list_ptr)
			return {};

		return Globals::g_pProcess->read< std::uintptr_t >(module_list_ptr + idx * sizeof(std::uintptr_t));
	}

	[[nodiscard]] const inline auto get_player_health_module()
	{
		return get_module_by_index(PlayerHealthModule);
	}

	[[nodiscard]] const inline auto get_player_stamina_module()
	{
		return get_module_by_index(PlayerStaminaModule);
	}
}