#include "common.hpp"
#include "pointers.hpp"
#include "routine.hpp"

BOOL APIENTRY DllMain(HMODULE hmod, DWORD reason, PVOID)
{
	using namespace mini;

	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hmod);

		g_hmodule = hmod;
		g_main_thread = CreateThread(nullptr, 0, [](PVOID) -> DWORD
			{
				try
				{
					// Enable
					auto pointers_instance = std::make_unique<pointers>();
					auto routine_instance = std::make_unique<routine>();

					// Sound
					PlaySound(TEXT("Windows Ding.wav"), NULL, SND_FILENAME | SND_ASYNC); // Injected

					while (g_running)
					{
						// Unload
						if (GetAsyncKeyState(VK_END) & 0x8000)
						{
							MessageBoxA(nullptr, "Unloaded", "Info", MB_OK | MB_SYSTEMMODAL); 
							g_running = false;
						}

						g_routine->run_tick();

						std::this_thread::sleep_for(10ms);
					}

					// Disable
					pointers_instance.reset();
					routine_instance.reset();
				}
				catch (std::exception const& ex)
				{
					MessageBoxA(nullptr, ex.what(), nullptr, MB_OK | MB_ICONEXCLAMATION);
				}

			CloseHandle(g_main_thread);
			FreeLibraryAndExitThread(g_hmodule, 0);
		}, nullptr, 0, &g_main_thread_id);
	}

	return true;
}