#pragma once

//-----include section-----
#include <SFML/Graphics.hpp>
#include <string>


//-----constants section------
const std::string BOARD_FILE_NAME = "Board.txt";
const std::string TOOLBAROBJECTS = "ToolBar.txt";
const std::string LEVELS_FILE = "LevelList.txt";
const std::string OPENING_WINDOW_NAME = "Opening Window";
const std::string GAME_WINDOW_NAME = "Game Window";

const int START_WINDOW_BUTTONS_NUM = 3;
const std::string NEW_GAME_BUTTON_NAME = "New Game";
const std::string HELP_BUTTON_NAME = "Help";
const std::string EXIT_BUTTON_NAME = "Exit Game";
const char START_MENU_INDENTIFIER[START_WINDOW_BUTTONS_NUM] = { 'N', 'H', 'E' };

const std::string BOMBERMAN_CAKGROUND_SOUND = "BombermanBackgroundMusic.mp3";
const std::string WIN_LEVEL_SOUND = "WinLevelSound.wav";
const std::string LOSE_LEVEL_SOUND = "LoseLevelSound.wav";

const int FONT_CHARACTERS_SIZE = 26;

//I define Full-HD resolution to fit as many different computer screens as possible.
const unsigned int OPENINIG_MENU_WIDTH = 1920;
const unsigned int OPENINIG_MENU_HEIGHT = 1080;

const int OBJECT_COUNT = 5;
const unsigned int WINDOW_WIDTH = 3500;
const unsigned int WINDOW_HEIGHT = 1750;

const float BUTTON_WIDTH = 300;
const float BUTTON_HEIGHT = 100;

const float BOARD_WIDTH = 2000;
const float BOARD_HEIGHT = 1000;

const float CELL_SPACING = 6.f; // Space adding in calculations between cells in pixels
const float BUTTON_SPACING = 40.f; // Space between buttons in pixels


//-----enum section------
enum OBJECT {
	Door,
	Wall,
	Rock,
	Robot,
	Guard,
	Bomb,
	None //in case of creating default value
};

enum START_MENU_BUTTON {
	NewGame,
	Help,
	Exit
};


//-----functions section------
//-----------------------------------------------------------------------------
//functions which used in classes.
char getCharByEnum(OBJECT obj);
OBJECT getObjByChar(char obj);
char getStartMenuCharByEnum(START_MENU_BUTTON buttonType);
START_MENU_BUTTON getStartMenuButtonByChar(char buttonType);
std::string getStartMenuButtonStringByChar(char buttonType);
bool CheckLimits(const sf::Vector2f mousePosition,
				 const sf::Vector2f buttonPos,
				 const sf::Vector2f buttonSize);