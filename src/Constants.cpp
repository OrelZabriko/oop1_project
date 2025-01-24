//-----include section-----
#include "Constants.h"


//-----functions section------
//-----------------------------------------------------------------------------
char getObjCharByEnum(OBJECT obj)
{
	switch (obj)
	{
	case OBJECT::DOOR:
		return 'D';
	case OBJECT::WALL:
		return '#';
	case OBJECT::ROCK:
		return '@';
	case OBJECT::ROBOT:
		return '/';
	case OBJECT::GUARD:
		return '!';
	}
}


//-----------------------------------------------------------------------------
OBJECT getObjByChar(char obj)
{
	switch (obj)
	{
	case 'D':
		return OBJECT::DOOR;
	case '#':
		return OBJECT::WALL;
	case '@':
		return OBJECT::ROCK;
	case '/':
		return OBJECT::ROBOT;
	case '!':
		return OBJECT::GUARD;
	}
}


//-----------------------------------------------------------------------------
char getStartMenuCharByEnum(START_MENU_BUTTON buttonType)
{
	switch (buttonType)
	{
	case START_MENU_BUTTON::NewGame:
		return 'N';
	case START_MENU_BUTTON::Help:
		return 'H';
	case START_MENU_BUTTON::Exit:
		return 'E';
	}
}


//-----------------------------------------------------------------------------
START_MENU_BUTTON getStartMenuButtonByChar(char buttonType)
{
	switch (buttonType)
	{
	case 'N':
		return START_MENU_BUTTON::NewGame;
	case 'H':
		return START_MENU_BUTTON::Help;
	case 'E':
		return START_MENU_BUTTON::Exit;
	}
}


//-----------------------------------------------------------------------------
std::string getStartMenuButtonStringByChar(char buttonType)
{
	switch (buttonType)
	{
	case 'N':
		return NEW_GAME_BUTTON_NAME;
	case 'H':
		return HELP_BUTTON_NAME;
	case 'E':
		return EXIT_BUTTON_NAME;
	}
}


//-----------------------------------------------------------------------------
//This function check if the mouse is in the bounds of the button or the cell
//that called to this function.
bool CheckLimits(const sf::Vector2f mousePosition,
	const sf::Vector2f buttonCellPos,
	const sf::Vector2f buttonCellSize)
{
	if (buttonCellPos.x < mousePosition.x && buttonCellPos.x + buttonCellSize.x > mousePosition.x &&
		buttonCellPos.y < mousePosition.y && buttonCellPos.y + buttonCellSize.y > mousePosition.y)
	{
		return true;
	}

	return false;
}
