#include <utils/fs/fs.hpp>

namespace rando::utils
{
	std::vector<std::string> fs::stored::bgs;

	auto fs::get_random(int min, int max) -> rng_type::result_type
	{
		std::uniform_int_distribution<rng_type::result_type> udist(min, max);
		rng_type rng;
		rng.seed(uint32_t(time(nullptr)));
		rng_type::result_type retn = udist(rng);
		return retn;
	}

	auto fs::init() -> void
	{
		fs::stored::bgs = fs::enumerate("RandomTIzer\\bg\\");

		for (auto i = 0; i < 11; i++)
		{
			set((0x00482214 + (i * 0x4)), &fs::stored::bgs[fs::get_random(0, fs::stored::bgs.size())][0]);
		}
	}

	auto fs::enumerate(const std::string& path) -> std::vector<std::string>
	{
		std::vector<std::string> retn;

		for (auto const& entry : std::filesystem::directory_iterator{ path })
		{
			retn.emplace_back("..\\" + entry.path().string());
		}

		return retn;
	}
}