#include <utils/fs/fs.hpp>

namespace rando
{
	void init()
	{
		srand(uint32_t(time(nullptr)));

#ifdef DEBUG
		utils::console::init();
#endif

		utils::fs::init();
	}
}

bool __stdcall DllMain(::HMODULE, ::DWORD reason, ::LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		rando::init();
		return true;
	}

	return false;
}