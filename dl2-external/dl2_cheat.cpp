#include "dl2_cheat.hpp"

#include "utils.hpp"
#include "globals.hpp"
#include "offsets.hpp"

#include "ft_durex.hpp"

#include <print>
#include "ft_godmode.hpp"
#include "ft_stamina.hpp"
#include "ft_chems.hpp"

#include "module_list.hpp"
#include "ft_consume.hpp"

bool dl2_cheat::setup_features()
{
	auto durex = std::make_unique< ft_durex >();
	durex->set_name(L"Infinite Weapon Durability / Auto-Repair");
	durex->set_activation_delay(420);
	durex->enable_print_status();
	durex->set_virtual_key_code(VK_NUMPAD1);

	auto god = std::make_unique< ft_godmode >();
	god->set_name(L"Godmode");
	god->enable_print_status();
	god->set_activation_delay(420);
	god->set_virtual_key_code(VK_NUMPAD2);

	auto stm = std::make_unique< ft_stamina >();
	stm->set_name(L"Infinite Stamina");
	stm->enable_print_status();
	stm->set_activation_delay(420);
	stm->set_virtual_key_code(VK_NUMPAD3);

	auto chems = std::make_unique< ft_chems  >();
	chems->set_name(L"No Chemical Cooldown");
	chems->enable_print_status();
	chems->set_activation_delay(420);
	chems->set_virtual_key_code(VK_NUMPAD4);

	auto cons = std::make_unique< ft_consume  >();
	cons->set_name(L"No Item Consumption / Dupe Exploit");
	cons->enable_print_status();
	cons->set_activation_delay(420);
	cons->set_virtual_key_code(VK_NUMPAD5);

	this->m_features.push_back(std::move(durex));
	this->m_features.push_back(std::move(god));
	this->m_features.push_back(std::move(stm));
	this->m_features.push_back(std::move(chems));
	this->m_features.push_back(std::move(cons));

    return true;
}

bool dl2_cheat::setup_offsets()
{
    const auto gamedll = Globals::g_pProcess->get_image_ptr_by_name(L"gamedll_ph_x64_rwdi.dll");

    if (!gamedll)
        return false;

	const auto gamedll_base = gamedll->get_image_base();

	const auto durex = gamedll->find_pattern(L"F3 0F 5D C6 0F 28 F0 0F 28 7C", false);

	if (!durex)
		return false;

	Offsets::weapon_durability = durex;

	const auto ml_cnt_enc = gamedll->find_pattern(L"48 8B 3D E7 DC C3 02", false);

	if (!ml_cnt_enc)
		return false;

	const auto dword_displ = gamedll->deref_address< uint32_t >(ml_cnt_enc + 3);

	Offsets::module_list_constant_encrypted = ( ml_cnt_enc - gamedll_base ) + dword_displ + gamedll_base + 7;

	const auto xp = gamedll->find_pattern(L"48 F7 D5 33 D2 48 89", false);

	if (!xp)
		return false;

	Offsets::gain_xp = xp;

	const auto consume = gamedll->find_pattern(L"EB ? 89 33 48 8B 5C 24 30", false);

	if (!consume)
		return false;

	Offsets::consume_item = consume + 2;

    return true;
}

void dl2_cheat::print_features()
{
	printf("\n");

	printf("Feature-Name -> Feature-Hotkey\n");

	for (const auto& feature : this->m_features)
		printf(
			"[>] %-25ws -> %s\n",
			feature->get_name().c_str(),
			utils::virtual_key_as_string(feature->get_virtual_key_code()).c_str()
		);

	printf("\n");
}

void dl2_cheat::print_offsets()
{
	printf("\n");

	const auto msg = [](const std::string& name, const std::uintptr_t value)
		{
			printf("[>] %-35s -> 0x%llX\n", name.c_str(), value);
		};

	msg("Infinite weapon durability", Offsets::weapon_durability);
	msg("Module List Constant Encrypted", Offsets::module_list_constant_encrypted);
	msg("Module List Ptr decrypted (only valid when already ingame)", module_list::get_decrypted_module_list_ptr());
	msg("XP Patch", Offsets::gain_xp);
	msg("Consume Items Patch", Offsets::consume_item);

	printf("\n");
}

void dl2_cheat::run()
{
	for (const auto& feature : this->m_features)
	{
		// before tick'ing the feature, check first if the state will eventually change
		if (GetAsyncKeyState(feature->get_virtual_key_code()) & 0x8000)
			feature->toggle();

		// let the feature tick() when active
		if (feature->is_active())
			feature->tick();
	}
}

void dl2_cheat::shutdown()
{
	// disable every feature here
	for (const auto& feature : this->m_features)
		if (feature->is_active())
			feature->disable();

	// clear image map here
	if (Globals::g_pProcess)
		Globals::g_pProcess->clear_image_map();
}
