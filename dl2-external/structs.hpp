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

