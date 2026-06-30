#include "score.h"
#include <fstream>

// save / load

Score loadScore()
{
	Score total{};

	std::ifstream load("save.bin", std::ios::binary);
	if (load)
	{
		load.read(reinterpret_cast<char*>(&total), sizeof(Score));
	}

	return total;
}

void saveScore(const Score& total)
{
	std::ofstream save("save.bin", std::ios::binary);
	if (save)
	{
		save.write(reinterpret_cast<const char*>(&total), sizeof(Score));
	}
}