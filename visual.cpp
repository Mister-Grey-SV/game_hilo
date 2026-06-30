#include "visual.h"

// visual

// navigation
void printMenu(const Score& total)
{
	dravScreen();

	std::cout << "Total score:        YOU:  " 
		<< total.your_score << " VS " 
		<< total.computer_score << "  :COMPUTER\n\t";
	std::cout << "Wins in a row:      " << total.in_row << "\n\n\t";

	for (const StructMainMenu& action : main_menu)
	{
		std::cout << '[' << action.name << ": " << static_cast<int>(action.menu) << "]        ";
	}

	std::cout << "\n\n\tEnter the namber of action: ";
}

void printExit()
{
	dravScreen();

	std::cout << "Exit ? \n\n";
	std::cout << "\t[YES: 1]\t[NO: 0]\n\n\t";
}

void pirntSettingsMenu(const Setting& setting)
{
	dravScreen();

	for (const StructSettingsMenu& action : settings_menu)
	{
		std::cout << '[' << action.name << ": " << static_cast<int>(action.menu) << "]        ";
	}

	std::cout << "\n\n\tEnter the namber of action: ";
}

// settings
void printAskMaxHideNum()
{
	dravScreen();

	std::cout << "Enter diapason you want play: ";
}

void printAskAttemptsNum()
{
	dravScreen();

	std::cout << "Enter number of attempts you want play: ";
}

// play
void printRound(const GameCondition& condition, const Setting& setting)
{
	dravScreen();

	std::cout << "Guess a number from " << 1 << " to " << setting.max_hide_num << "\n\n\t";
	std::cout << "You have " << condition.attempts_num << " attempts\n\n\t";
	std::cout << "End this number is?: ";
}

void printYourLower()
{
	std::cout << "\n\t";
	std::cout << "Your number is lower\n";
}

void printYourHigher()
{
	std::cout << "\n\t";
	std::cout << "Your number is higher\n";
}

void printWin(const GameCondition& condition, const Setting& setting)
{
	std::cout << "\n\t";
	std::cout << "CONGRATULATIONS!!!\n\n\t";
	std::cout << "You have won whith " << setting.max_attempts_num - condition.attempts_num + 1;

	if (setting.max_attempts_num - condition.attempts_num + 1 == 1)
	{
		std::cout << " attempt!\n";
	}

	else
	{
		std::cout << " attempts!\n";
	}
}

void printLose(const Setting& setting)
{
	std::cout << "\n\t";
	std::cout << "GAME OVER\n\n\t";
	std::cout << "You have spent all " << setting.max_attempts_num;

	if (setting.max_attempts_num == 1)
	{
		std::cout << "your attempt!\n";
	}

	else
	{
		std::cout << "your attempts!\n";
	}
}

// utility
void dravScreen()
{
	system("cls");
	std::cout << "\n\n\t";
}