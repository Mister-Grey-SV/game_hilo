#include "game_engine.h"
#include "score.h"

int main()
{
	Setting setting
	{
		10, 5
	};

	Score total = loadScore();

	while (true)
	{
		printMenu(total);

		switch (getNum(0, sizeof(main_menu) / sizeof(main_menu[0]) - 1))
		{
			case static_cast<int>(MainMenu::Exit):
				if (exitFrom())
				{
					saveScore(total);
					return 0;
				}
				break;

			case static_cast<int>(MainMenu::Settings):
				gameSettings(setting);
				break;

			case static_cast<int>(MainMenu::Play):
				gamePlay(setting, total);
				break;
		}
	}
}