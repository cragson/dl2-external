#include "ft_godmode.hpp"

#include "module_list.hpp"
#include "globals.hpp"
#include "structs.hpp"

void ft_godmode::tick()
{
	const auto phm_ptr = module_list::get_player_health_module();

	if (phm_ptr)
	{
		const auto max_health = Globals::g_pProcess->read< float >(phm_ptr + offsetof(cPlayerHealthModule, m_iMaximumHealth1));

		Globals::g_pProcess->write< float >(phm_ptr + offsetof(cPlayerHealthModule, m_iCurrentHealth1), max_health);
	}
}
