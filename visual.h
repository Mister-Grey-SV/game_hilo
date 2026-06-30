#ifndef VISUAL_H
#define VISUAL_H

#include "constants.h"
#include <iostream>
#include <cstdlib>

// visual

// navigation
void printMenu(const Score& total);
void pirntSettingsMenu(const Setting& setting);
void printExit();

// settings
void printAskMaxHideNum();
void printAskAttemptsNum();

// play
void printRound(const GameCondition& condition, const Setting& setting);
void printYourLower();
void printYourHigher();
void printWin(const GameCondition& condition, const Setting& setting);
void printLose(const Setting& setting);

// utility
void dravScreen();

#endif // !VISUAL_H

