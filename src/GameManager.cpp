//-----include section-----
#include "GameManager.h"


//-----functions section------
//-----------------------------------------------------------------------------
GameManager::GameManager(const Level& currLevel) : m_currLevel(currLevel)
{
	loadLevel(currLevel);	
}


//-----------------------------------------------------------------------------
void GameManager::loadLevel(const Level& currLevel)
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
	m_currBoard.handleObjectCollision(); //if something happened

	//check special status of the robot
	if (m_currBoard.getHideGiftStatus())
	{
		m_currBoard.HideSingleGuard();
	}
	if (m_currBoard.getFreezeGiftStatus())
	{
		m_currBoard.freezeGuards();
	}

	if (m_currBoard.getLifeGiftStatus())
	{
		m_currBoard.addLife();
	}

	if (m_currBoard.getTimeGiftStatus())
	{
		m_currBoard.addTime();
	}

	m_currBoard.updateGuards();  //will go over guard, and delete if needed
	m_currBoard.updateRocks();  //will go over static objects, and delete if needed a rocks
	m_currBoard.updateGifts();
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
void GameManager::updateRobot(sf::Keyboard::Key key, 
						      const sf::Time deltaTime)
{
	m_currBoard.MoveRobot(key, deltaTime);
}


//-----------------------------------------------------------------------------
void GameManager::updateGuards(const sf::Time deltaTime)
{
	if (GetIfStartGame()) //The guards will move just if we will start the new game
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


//-----------------------------------------------------------------------------
bool GameManager::checkIfRobotDead()
{
	return (m_currBoard.checkRobotEndOfLife());
}