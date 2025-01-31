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
void GameManager::draw(sf::RenderWindow& window)
{
	m_currBoard.draw(window);
}


//-----------------------------------------------------------------------------
void GameManager::setRobotDirection(sf::Keyboard::Key key)
{
	m_currBoard.setRobotDirections(key);
}


//-----------------------------------------------------------------------------
void GameManager::HandleTheCollision()
{
	m_currBoard.handleObjectCollision();
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
	if (GetIfStartGame())
	{
		m_currBoard.MoveGuards(deltaTime);
	}
}


//-----------------------------------------------------------------------------
void GameManager::SetStartGame(const bool ifStart)
{
	m_startGame = ifStart;
}


//-----------------------------------------------------------------------------
const bool& GameManager::GetIfStartGame() const
{
	return m_startGame;
}
