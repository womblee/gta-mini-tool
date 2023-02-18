#pragma once
#include "common.hpp"

namespace mini
{
	class routine
	{
	public:
		explicit routine();
		~routine();
	public:
		void run_tick();
	};

	inline routine* g_routine{};
}
