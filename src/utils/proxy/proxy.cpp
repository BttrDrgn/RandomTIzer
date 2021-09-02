#include <stdafx.hpp>

#include <utils/proxy/proxy.hpp>

namespace utils
{
	::FARPROC proxy::get(const char* lib, const char* func)
	{
		if (!proxy::is_loaded(lib))
		{
			proxy::load(lib);
		}

		return ::GetProcAddress(proxy::libraries_[lib], func);
	}

	void proxy::load(const char* lib)
	{
		char path[MAX_PATH];
		::GetSystemDirectoryA(path, MAX_PATH);

		std::strcat(path, "\\");
		std::strcat(path, lib);

		proxy::libraries_[lib] = ::LoadLibraryA(path);
	}

	bool proxy::is_loaded(const char* lib)
	{
		return proxy::libraries_.find(lib) != proxy::libraries_.end();
	}

	std::unordered_map<const char*, ::HMODULE> proxy::libraries_;
}

EXPORT(DirectSoundCreate)