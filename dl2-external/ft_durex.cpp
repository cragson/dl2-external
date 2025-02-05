#include "ft_durex.hpp"

#include "globals.hpp"
#include "offsets.hpp"

void ft_durex::on_enable()
{
	Globals::g_pProcess->write< uint8_t >(Offsets::weapon_durability + 2, 0x5F);

	Sleep(420);
}

void ft_durex::on_disable()
{
	Globals::g_pProcess->write< uint8_t >(Offsets::weapon_durability + 2, 0x5D);

	Sleep(420);
}
