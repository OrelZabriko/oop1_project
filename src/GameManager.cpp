//-----include section-----
#include "GameManager.h"


//-----functions section------
//-----------------------------------------------------------------------------
GameManager::GameManager(const Level& currLevel) : m_currLevel(currLevel)
{
	m_currBoard = Board(currLevel.getRows(), currLevel.getCols());
	for (int row = 0; row < currLevel.getRows(); row++)
	{
		for (int col = 0; col < currLevel.getCols(); col++)
		{
			sf::Vector2f objLocMatrix = sf::Vector2f(col, row);
			m_currBoard.createCell(currLevel.GetObjChar(row, col), objLocMatrix);
		}
	}
}


//-----------------------------------------------------------------------------
Board& GameManager::getBoard()
{
	return m_currBoard;
}


//-----------------------------------------------------------------------------
void GameManager::draw(sf::RenderWindow& window)
{
	m_currBoard.draw(window);
}


//-----------------------------------------------------------------------------
void GameManager::updateRobot(sf::Keyboard::Key key, 
						      const sf::Time deltaTime)
{
	m_currBoard.MoveRobot(key, deltaTime);
}


//-----------------------------------------------------------------------------
void GameManager::updateGuards(const sf::Time deltaTime)
{
	m_currBoard.MoveGuards(deltaTime);
}


//-----------------------------------------------------------------------------
void GameManager::dropBomb()
{
	sf::Vector2f playerPos = m_currBoard.getRobotPosition();
	m_currBoard.addBomb(playerPos);
}


//-----------------------------------------------------------------------------
void GameManager::updateBombs(const sf::Time deltaTime)
{
	m_currBoard.handleBombs(deltaTime);
}


//-----------------------------------------------------------------------------
sf::Vector2f GameManager::getPlayerPosition() const
{
	return m_currBoard.getRobotPosition();
}