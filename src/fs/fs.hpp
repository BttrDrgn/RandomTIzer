#pragma once

namespace rando
{
	namespace fs
	{
		auto init() -> void;
		auto enumerate(const std::string& path)->std::vector<std::string>;
		auto get_random(int min, int max) -> rng_type::result_type;

		class stored final
		{
		public:
			static std::vector<std::string> bgs;
			static std::vector<std::string> effects;
			static std::vector<std::string> frames;
			static std::vector<std::string> blocks;
			static std::vector<std::string> blocks_misc;
			static std::vector<std::string> general;
			static std::vector<std::string> fonts;
		};
	}
}