//-----include section-----
#include "GameWindow.h"


//-----functions section------
//-----------------------------------------------------------------------------
GameWindow::GameWindow(const Level& currLevel) : m_currLevel(currLevel)
{
	for (int row = 0; row < currLevel.getRows(); row++)
	{
		for (int col = 0; col < currLevel.getCols(); col++)
		{
			sf::Vector2f objLOcMatrix = sf::Vector2f(col, row);

			switch (currLevel.GetObjChar(row, col))
			{
			case 'D': //OBJECT::DOOR
			{
				m_currBoard = Board('D', objLOcMatrix);

				break;
			}
			case '#': //OBJECT::WALL
			{
				m_currBoard = Board('#', objLOcMatrix);

				break;
			}
			case '@': //OBJECT::ROCK
			{
				m_currBoard = Board('@', objLOcMatrix);

				break;
			}
			case '/': //OBJECT::ROBOT
			{
				m_currBoard = Board('/', objLOcMatrix);

				break;
			}
			case '!': //OBJECT::GUARD
			{
				m_currBoard = Board('!', objLOcMatrix);

				break;
			}
			}
		}
	}
}