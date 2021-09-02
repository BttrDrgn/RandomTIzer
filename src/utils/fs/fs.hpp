#pragma once

namespace rando::utils
{
	namespace fs
	{
		auto init() -> void;
		auto enumerate(const std::string& path)->std::vector<std::string>;
		auto get_random(int min, int max) -> rng_type::result_type;

		class stored
		{
		public:
			static std::vector<std::string> bgs;
		};
	}
}