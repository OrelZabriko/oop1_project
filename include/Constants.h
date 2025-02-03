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
const std::string HELP_BUTTON_NAME = "HELP";
const std::string EXIT_BUTTON_NAME = "Exit Game";
const char START_MENU_INDENTIFIER[START_WINDOW_BUTTONS_NUM] = { 'N', 'H', 'E' };

const std::string BOMBERMAN_BACKGROUND_SOUND = "BombermanBackgroundMusic.ogg";
const std::string WIN_LEVEL_SOUND = "WinLevelSound.ogg";
const std::string LOSE_LEVEL_SOUND = "LoseLevelSound.ogg";

const int FONT_CHARACTERS_SIZE = 26;

//I define Full-HD resolution to fit as many different computer screens as possible.
const unsigned int WINDOW_WIDTH = 1920;
const unsigned int WINDOW_HEIGHT = 1080;

const int OBJECT_COUNT = 5;
const int EXPLOSION_TIME = 4;

const float BUTTON_WIDTH = 300;
const float BUTTON_HEIGHT = 100;

const float BOARD_WIDTH = 1400;
const float BOARD_HEIGHT = 720;

const float CELL_SPACING = 10.f;	//Space adding in calculations between cells in pixels
const float BUTTON_SPACING = 40.f; //Space between buttons in pixels
const float INFOBAR_SPACE = 50.f; //Spasce between the top ot the RenderWindow to the board for the InfoBar

const float PIXELS_FOR_MOVE_ROBOT = 450.f;
const float PIXELS_FOR_MOVE_GUARD = 50.f;
const float EXPLOSION_RANGE = 32.f;
const int TIME_LIMIT = 300; //the limit time for every level in seconds

const int ROBOT_LIVES = 5;
const int RESTART_ROBOT_SCORE = 0;


//-----enum section------
enum OBJECT {
	DOOR,
	WALL,
	ROCK,
	ROBOT,
	GUARD,
	NONE	//in case of creating default value
};

enum START_MENU_BUTTON {
	NewGame,
	Help,
	Exit
};


//-----functions section------
//-----------------------------------------------------------------------------
//functions which used in classes.
char getObjCharByEnum(OBJECT obj);
OBJECT getObjByChar(char obj);
char getStartMenuCharByEnum(START_MENU_BUTTON buttonType);
START_MENU_BUTTON getStartMenuButtonByChar(char buttonType);
std::string getStartMenuButtonStringByChar(char buttonType);
bool CheckLimits(const sf::Vector2f mousePosition,
	const sf::Vector2f buttonPos,
	const sf::Vector2f buttonSize);