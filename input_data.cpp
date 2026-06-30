#include "input_data.h"

// input

int getNum(const int min, const int max)
{
	while (true)
	{
		std::string input;
		std::getline(std::cin, input);

		if (input.empty())
		{
			continue;
		}

		int output{};
		if (tryParse(input, output) && min <= output && output <= max)
		{
			return output;
		}
	}
}

bool tryParse(const std::string& input, int& output)
{
	size_t position{};

	try
	{
		output = std::stoi(input, &position);
	}

	catch (...)
	{
		return false;
	}

	return position == input.size();
}

// randomizer

int getRandom(int max)
{
	static std::mt19937 generator{ std::random_device{}() };
	std::uniform_int_distribution<int> distribution(1, max);

	return distribution(generator);
}