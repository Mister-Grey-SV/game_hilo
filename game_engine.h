#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "visual.h"
#include "constants.h"
#include "input_data.h"
#include <thread>
#include <chrono>
#include <limits>

// game_engine
void gameSettings(Setting& setting);
void gamePlay(const Setting& setting, Score& total);
bool exitFrom();

#endif // !GAME_ENGINE_H
