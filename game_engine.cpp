#include "game_engine.h"

// game_engine

void gameSettings(Setting& setting)
{
	while (true)
	{
		pirntSettingsMenu(setting);

		switch (getNum(0, sizeof(settings_menu) / sizeof(settings_menu[0]) - 1))
		{
		case static_cast<int>(SettingsMenu::Cancel):
			if (exitFrom())
			{
				return;
			}
			break;

		case static_cast<int>(SettingsMenu::MaxHideNum):
			printAskMaxHideNum();
			setting.max_hide_num = getNum(0, std::numeric_limits<int>::max());
			break;

		case static_cast<int>(SettingsMenu::MaxAttemptNum):
			printAskAttemptsNum();
			setting.max_attempts_num = getNum(1, std::numeric_limits<int>::max());
			break;
		}
	}
}

void gamePlay(const Setting& setting, Score& total)
{
	GameCondition condition
	{
		getRandom(setting.max_hide_num),
		setting.max_attempts_num,
		-1
	};

	while (true)
	{
		printRound(condition, setting);

		condition.user_try = getNum(0, setting.max_hide_num);

		if (condition.hide_num > condition.user_try)
		{
			printYourLower();
		}

		else if (condition.hide_num < condition.user_try)
		{
			printYourHigher();
		}

		else if (condition.hide_num == condition.user_try)
		{
			printWin(condition, setting);
			++total.your_score;
			++total.in_row;
			std::this_thread::sleep_for(std::chrono::seconds(5));
			return;
		}

		--condition.attempts_num;

		if (condition.attempts_num <= 0)
		{
			printLose(setting);
			++total.computer_score;
			total.in_row = 0;
			std::this_thread::sleep_for(std::chrono::seconds(5));
			return;
		}

		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}

bool exitFrom()
{
	printExit();

	return static_cast<bool>(getNum(0, 1));
}