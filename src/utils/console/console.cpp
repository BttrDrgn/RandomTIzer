#include <utils/console/console.hpp>

namespace rando::utils
{
	void console::init()
	{
		console::file_ = std::fopen("console.log", "ab");

		::AllocConsole();
		::SetConsoleTitleA("RandomTIzer Console");

		std::freopen("CONOUT$", "w", stdout);
		std::freopen("CONIN$", "r", stdin);
	}

	::_iobuf* console::file()
	{
		return console::file_;
	}

	::_iobuf* console::file_;
}
