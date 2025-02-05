#include "ft_chems.hpp"

#include "module_list.hpp"
#include "globals.hpp"
#include "structs.hpp"

#include <print>

void ft_chems::tick()
{
	const auto pcm_ptr = module_list::get_module_by_index(PlayerChemicalModule);

	if (pcm_ptr && Globals::g_pProcess->read< float >(pcm_ptr + 0x44) <= 1.f )
		Globals::g_pProcess->write< float >(pcm_ptr + 0x44, 1337.f);
}
