#pragma once
#include "common.hpp"
#include "script_global.hpp"
#include "pointers.hpp"

namespace mini::self
{
	inline void never_wanted()
	{
		if (!g_local_player)
			return;

		if (auto plr = g_local_player->m_player_info)
		{
			if (plr->m_is_wanted)
				plr->m_wanted_level = 0;
		}
	}

	inline void infinite_ammo()
	{
		if (!g_local_player)
			return;

		memory::mem_nop(g_pointers->m_infinite_ammo, sizeof(g_pointers->m_infinite_ammo));
	}

	inline void infinite_mag()
	{
		if (!g_local_player)
			return;

		memory::mem_nop(g_pointers->m_infinite_mag, sizeof(g_pointers->m_infinite_mag));
	}

	inline void ammo_pickup()
	{
		if (!g_local_player)
			return;

		if (*g_pointers->m_is_session_started)
		{
			if (GetAsyncKeyState(VK_F9) & 0x8000)
			{
				*script_global(2793046).at(886).as<int*>() = 1;
			}
		}
	}

}