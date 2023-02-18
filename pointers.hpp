#pragma once
#include "common.hpp"
#include "memory/all.hpp"

namespace mini
{
	/* 
	sauce: sub1to internal
	*/

	struct three_bytes
	{
		BYTE byte[3];
		bool empty();
	};

	class pointers
	{
	public:
		explicit pointers();
		~pointers();
	public:
		HWND m_hwnd{};
		CPedFactory **m_ped_factory{};
		bool* m_is_session_started{};
		std::int64_t **m_script_globals{};
		three_bytes* m_infinite_ammo;
		three_bytes* m_infinite_mag;
	};

	inline pointers *g_pointers{};
}
