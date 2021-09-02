#pragma once

#include <initializer_list>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <random>

typedef std::mt19937 rng_type;

#include <Windows.h>

#include <utils/console/console.hpp>

template <typename T> void set(std::uint32_t address, T value)
{
	DWORD old_protect;
	VirtualProtect((void*)address, sizeof(T), PAGE_EXECUTE_READWRITE, &old_protect);

	*reinterpret_cast<T*>((void*)address) = value;

	VirtualProtect((void*)address, sizeof(T), old_protect, &old_protect);
	FlushInstructionCache(GetCurrentProcess(), (void*)address, sizeof(T));
}