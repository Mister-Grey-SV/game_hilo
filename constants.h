#ifndef CONSTANTS_H
#define CONSTANTS_H

// constants

struct Setting
{
	int max_hide_num;
	int max_attempts_num;
};

struct GameCondition
{
	int hide_num;
	int attempts_num;
	int user_try;
};

enum class MainMenu
{
	Exit,
	Settings,
	Play
};

struct StructMainMenu
{
	MainMenu menu;
	const char* name;
};

inline constexpr StructMainMenu main_menu[]
{
	{MainMenu::Exit,		"Exit"},
	{MainMenu::Settings,	"Settings"},
	{MainMenu::Play,		"Play"}
};

enum class SettingsMenu
{
	Cancel,
	MaxHideNum,
	MaxAttemptNum
};

struct StructSettingsMenu
{
	SettingsMenu menu;
	const char* name;
};

inline constexpr StructSettingsMenu settings_menu[]
{
	{SettingsMenu::Cancel,			"Cancel"},
	{SettingsMenu::MaxHideNum,		"Diapason"},
	{SettingsMenu::MaxAttemptNum,	"Attempts"}
};

struct Score
{
	int your_score;
	int computer_score;
	int in_row;
};

#endif // !CONSTANTS_H