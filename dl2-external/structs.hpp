#pragma once

class cPlayerHealthModule
{
public:
	char pad_0000[44]; //0x0000
	float m_iCurrentHealth1; //0x002C
	float m_iCurrentHealth2; //0x0030
	float m_iCurrentHealth3; //0x0034
	char pad_0038[4]; //0x0038
	float m_iMaximumHealth1; //0x003C
	float m_iMaximumHealth2; //0x0040
	float m_iMaximumHealth3; //0x0044
}; //Size: 0x0048

class cPlayerStaminaModule
{
public:
	char pad_0000[16]; //0x0000
	float m_flCurrentStamina1; //0x0010
	char pad_0014[4]; //0x0014
	float m_flCurrentStamina2; //0x0018
	float m_flCooldown; //0x001C
}; //Size: 0x0020

class cPlayerInventoryModule
{
public:
	char pad_0000[8]; //0x0000
	class IDK_Inventory_Inst* m_pIDKInst; //0x0008
	char pad_0010[3056]; //0x0010
}; //Size: 0x0C00

class IDK_Inventory_Inst
{
public:
	char pad_0000[1136]; //0x0000
	class InventoryContainerDI* m_pInventoryContainerDI; //0x0470
	char pad_0478[16]; //0x0478
}; //Size: 0x0488


class InventoryContainerDI
{
public:
	char pad_0000[56]; //0x0000
	class InventoryMoney* m_pInventoryMoney; //0x0038
	class InventoryItemsAmmo* m_pInventoryItemsAmmo; //0x0040
	class InventoryCollectable* m_pInventoryCollectable; //0x0048
	class InventoryLooseItems* m_pInventoryLooseItems; //0x0050
	class InventoryMain* m_pInventoryMain; //0x0058
	class InventoryItems* m_pInventoryItems; //0x0060
	class InventorySpecial* m_pInventorySpecial; //0x0068
	char pad_0070[8]; //0x0070
	class InventoryToken* m_pInventoryToken; //0x0078
	char pad_0080[16]; //0x0080
}; //Size: 0x0090


class InventoryMoney
{
public:
	char pad_0000[56]; //0x0000
	uint32_t m_iOldWorldMoney; //0x0038
	char pad_003C[1356]; //0x003C
}; //Size: 0x0588


class InventoryItemsAmmo
{
public:
	char pad_0000[72]; //0x0000
	uint32_t m_iAmmo; //0x0048
	char pad_004C[36]; //0x004C
}; //Size: 0x0070


class InventoryCollectable
{
public:
	char pad_0000[52]; //0x0000
	uint32_t N00000EFA; //0x0034
	char pad_0038[8]; //0x0038
	uint32_t N00000EEA; //0x0040
	uint32_t N00000EFE; //0x0044
	char pad_0048[64]; //0x0048
}; //Size: 0x0088

class InventoryLooseItems
{
public:
	char pad_0000[392]; //0x0000
}; //Size: 0x0188

class InventoryMain
{
public:
	char pad_0000[1160]; //0x0000
}; //Size: 0x0488

class InventoryItems
{
public:
	char pad_0000[136]; //0x0000
}; //Size: 0x0088

class InventorySpecial
{
public:
	char pad_0000[392]; //0x0000
}; //Size: 0x0188

class InventoryToken
{
public:
	char pad_0000[104]; //0x0000
	float N0000108F; //0x0068
	char pad_006C[4]; //0x006C
}; //Size: 0x0070
