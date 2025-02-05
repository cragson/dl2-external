#include "ft_consume.hpp"

#include "globals.hpp"
#include "offsets.hpp"

void ft_consume::on_enable()
{
	// gamedll_ph_x64_rwdi.dll+6E2356 - FF 03                 - inc [rbx]
	Globals::g_pProcess->write< uint16_t >(Offsets::consume_item, 0x03FF);

	Sleep(420);
}

void ft_consume::on_disable()
{
	// gamedll_ph_x64_rwdi.dll+6E2356 - 89 33                 - mov [rbx],esi
	Globals::g_pProcess->write< uint16_t >(Offsets::consume_item, 0x3389);

	Sleep(420);
}
