#include <fs/fs.hpp>

namespace rando
{
	std::vector<std::string> fs::stored::bgs;
	std::vector<std::string> fs::stored::effects;
	std::vector<std::string> fs::stored::frames;
	std::vector<std::string> fs::stored::blocks;
	std::vector<std::string> fs::stored::blocks_misc;
	std::vector<std::string> fs::stored::general;
	std::vector<std::string> fs::stored::fonts;

	auto fs::get_random(int min, int max) -> rng_type::result_type
	{
		std::uniform_int_distribution<rng_type::result_type> uni(min, max);
		rng_type rng;
		rng.seed(uint32_t(time(nullptr)));
		rng_type::result_type retn = uni(rng);
		return retn;
	}

	auto fs::init() -> void
	{
		fs::stored::bgs = fs::enumerate("RandomTIzer\\bg\\");
		PRINT_DEBUG("Bgs: %i", fs::stored::bgs.size());
		for (auto i = 0; i < 11; i++)
		{
			set((0x00482214 + (i * 0x4)), &fs::stored::bgs[fs::get_random(0, fs::stored::bgs.size() - 1)][0]);
		}

		fs::stored::effects = fs::enumerate("RandomTIzer\\effects\\");
		PRINT_DEBUG("Effects: %i", fs::stored::effects.size());
		for (auto i = 0; i < 19; i++)
		{
			set((0x00482324 + (i * 0x8)), &fs::stored::effects[fs::get_random(0, fs::stored::effects.size() - 1)][0]);
		}

		fs::stored::frames = fs::enumerate("RandomTIzer\\frames\\");
		PRINT_DEBUG("Frames: %i", fs::stored::frames.size());
		for (auto i = 0; i < 7; i++)
		{
			set((0x004821F8 + (i * 0x4)), &fs::stored::frames[fs::get_random(0, fs::stored::frames.size() - 1)][0]);
		}

		/*
		fs::stored::blocks = fs::enumerate("RandomTIzer\\blocks\\");
		PRINT_DEBUG("Blocks: %i", fs::stored::blocks.size());
		set(0x0042F9A0 + 0x1, &fs::stored::blocks[fs::get_random(0, fs::stored::blocks.size() - 1)][0]);	//block
		set(0x0042FA14 + 0x1, &fs::stored::blocks[fs::get_random(0, fs::stored::blocks.size() - 1)][0]);	//blockw

		fs::stored::blocks_misc = fs::enumerate("RandomTIzer\\blocks_misc\\");
		PRINT_DEBUG("Blocks Misc: %i", fs::stored::blocks_misc.size());
		set(0x0042F9D8 + 0x1, &fs::stored::blocks_misc[fs::get_random(0, fs::stored::blocks_misc.size() - 1)][0]);	//b_item
		set(0x004031F6 + 0x1, &fs::stored::blocks_misc[fs::get_random(0, fs::stored::blocks_misc.size() - 1)][0]);	//blk_part
		set(0x004031F6 + 0x1, &fs::stored::blocks_misc[fs::get_random(0, fs::stored::blocks_misc.size() - 1)][0]);	//block1
		set(0x0042FA4D + 0x1, &fs::stored::blocks_misc[fs::get_random(0, fs::stored::blocks_misc.size() - 1)][0]);	//ibmblock
		set(0x0042FA88 + 0x1, &fs::stored::blocks_misc[fs::get_random(0, fs::stored::blocks_misc.size() - 1)][0]);	//ibmblockw

		fs::stored::general = fs::enumerate("RandomTIzer\\general\\");
		PRINT_DEBUG("General: %i", fs::stored::general.size());
		for (auto i = 0; i < 10; i++)
		{
			set((0x004822D4 + (i * 0x8)), &fs::stored::general[fs::get_random(0, fs::stored::general.size() - 1)][0]);
		}

		fs::stored::fonts = fs::enumerate("RandomTIzer\\fonts\\");
		PRINT_DEBUG("Fonts: %i", fs::stored::fonts.size());
		for (auto i = 0; i < 13; i++)
		{
			set((0x0048226C + (i * 0x8)), &fs::stored::fonts[fs::get_random(0, fs::stored::fonts.size() - 1)][0]);
		}
		*/
	}

	auto fs::enumerate(const std::string& path) -> std::vector<std::string>
	{
		std::vector<std::string> retn;

		if (path.find("frames") != std::string::npos)
		{
			for (auto const& entry : std::filesystem::directory_iterator{ path })
			{
				if (entry.path().string().find(".m3d") != std::string::npos)
				{
					retn.emplace_back("..\\" + entry.path().string());
				}
			}
		}
		else
		{
			for (auto const& entry : std::filesystem::directory_iterator{ path })
			{
				retn.emplace_back("..\\" + entry.path().string());
			}
		}

		return retn;
	}
}