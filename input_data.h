#ifndef INPUT_DATA_H
#define INPUT_DATA_H

#include <iostream>
#include <string>
#include <random>

// input
int getNum(const int min, const int max);
bool tryParse(const std::string& input, int& output);

// randomizer
int getRandom(int max);

#endif // !INPUT_DATA_H
