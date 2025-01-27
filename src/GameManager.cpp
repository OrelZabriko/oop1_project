//-----include section-----
#include "GameManager.h"


//-----functions section------
//-----------------------------------------------------------------------------
GameManager::GameManager(const Level& currLevel) : m_currLevel(currLevel)
{
	m_currBoard = Board(currLevel.getRows(), currLevel.getCols());
	std::cout << "starting game manager constr" << std::endl;
	std::cout << "curr level.rows = " << currLevel.getRows() << std::endl;
	std::cout << "curr level.cols = " << currLevel.getCols() << std::endl;
	for (int row = 0; row < currLevel.getRows(); row++)
	{
		for (int col = 0; col < currLevel.getCols(); col++)
		{
			std::cout << "first cell on the matrix" << std::endl;
			sf::Vector2f objLocMatrix = sf::Vector2f(col, row);
			std::cout << "before create cell" << std::endl;
			m_currBoard.createCell(currLevel.GetObjChar(row, col), objLocMatrix);
			std::cout << "after create cell" << std::endl;
		}
		std::cout << "finished a row in reading the level" << std::endl;
	}
	
	std::cout << "ending game manager constr" << std::endl;
}

void GameManager::draw(sf::RenderWindow& window)
{
	m_currBoard.draw(window);
}
