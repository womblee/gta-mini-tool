#include "common.hpp"
#include "routine.hpp"
#include "functions.hpp"
#include "gta/gta_util.hpp"

namespace mini
{
	routine::routine()
	{
		g_routine = this;
	}

	routine::~routine()
	{
		g_routine = nullptr;
	}

	void routine::run_tick()
	{
		g_local_player = gta_util::get_local_ped();

		self::never_wanted();
		self::infinite_mag();
		self::infinite_ammo();
		self::ammo_pickup();
	}
}
