#pragma once

#define EXPORT(X) extern "C" __declspec(naked) __declspec(dllexport) void X() { ::utils::proxy::get("dsound.dll", __FUNCTION__); __asm { jmp eax } }

namespace utils
{
	class proxy final
	{
		public:
			static ::FARPROC get(const char* lib, const char* func);

		private:
			static void load(const char* lib);
			static bool is_loaded(const char* lib);

			static std::unordered_map<const char*, ::HMODULE> libraries_;
	};
}