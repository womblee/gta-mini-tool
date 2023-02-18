#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <thread>
#include <atomic>
#include <chrono>
#include <ctime>
#include <exception>
#include <mmsystem.h>
#include <stdexcept>

// Basic memory entries
#include "ped/CPed.hpp"
#include "ped/CPedFactory.hpp"

namespace mini
{
	using namespace std::chrono_literals;

	inline HMODULE g_hmodule{};
	inline HANDLE g_main_thread{};
	inline DWORD g_main_thread_id{};
	inline std::atomic_bool g_running{ true };

	inline CPed* g_local_player;
}