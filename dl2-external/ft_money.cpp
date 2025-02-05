#include "ft_money.hpp"

#include "globals.hpp"
#include "offsets.hpp"
#include "module_list.hpp"
#include "structs.hpp"

#include <print>

void ft_money::on_enable()
{
	const auto pim_ptr = module_list::get_module_by_index(PlayerInventoryModule);

	if (pim_ptr)
	{
		const auto idk_ptr = Globals::g_pProcess->read< std::uintptr_t >(pim_ptr + offsetof(cPlayerInventoryModule, m_pIDKInst));

		if (!idk_ptr)
		{
			std::println("[!] Failed to retrieve idk ptr");

			this->disable();

			return;
		}

		const auto inv_di_ptr = Globals::g_pProcess->read< std::uintptr_t >(idk_ptr + offsetof(IDK_Inventory_Inst, m_pInventoryContainerDI));

		if (!inv_di_ptr)
		{
			std::println("[!] Failed to retrieve ptr to InventoryContainerDI");

			this->disable();

			return;
		}

		const auto inv_money_ptr = Globals::g_pProcess->read< std::uintptr_t >(inv_di_ptr + offsetof(InventoryContainerDI, m_pInventoryMoney));

		if (!inv_money_ptr)
		{
			std::println("[!] Failed to retrieve ptr to InventoryMoney");

			this->disable();

			return;
		}

		const auto current_money = Globals::g_pProcess->read< uint32_t >(inv_money_ptr + offsetof(InventoryMoney, m_iOldWorldMoney));

		Globals::g_pProcess->write< uint32_t >(inv_money_ptr + offsetof(InventoryMoney, m_iOldWorldMoney), current_money + 10000);

		std::println("[-] Added 10.000 money. Current balance: {}", current_money + 10000);
	}

	Sleep(420);

	this->disable();
}