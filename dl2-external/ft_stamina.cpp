#include "ft_stamina.hpp"

#include "module_list.hpp"
#include "globals.hpp"
#include "structs.hpp"

void ft_stamina::tick()
{
	const auto psm_ptr = module_list::get_player_stamina_module();

	if (psm_ptr && Globals::g_pProcess->read< float >( psm_ptr + offsetof(cPlayerStaminaModule, m_flCurrentStamina1) ) < 1.f ) 
	{
		Globals::g_pProcess->write< float >(psm_ptr + offsetof(cPlayerStaminaModule, m_flCurrentStamina1), 1.4f);
		Globals::g_pProcess->write< float >(psm_ptr + offsetof(cPlayerStaminaModule, m_flCooldown), 0.f);
	}	
}
