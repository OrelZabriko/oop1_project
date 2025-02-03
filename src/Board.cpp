//-----include section-----
#include "Board.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>

#include <stdio.h>


//-----functions section------
// //-----------------------------------------------------------------------------
Board::Board()
{}


//-----------------------------------------------------------------------------
Board::Board(int rows,int cols) : m_rows(rows), m_cols(cols)
{}


//-----------------------------------------------------------------------------
void Board::createCell(const char objChar, const sf::Vector2f objLoc)
{
	std::cout << "got the following objchar: " << objChar << std::endl;
	switch (objChar)
	{
	case 'D': //OBJECT::DOOR
	{
		m_StaticObjects.push_back(std::make_unique<Door>(objChar, objLoc));

		break;
	}
	case '#': //OBJECT::WALL
	{
		m_StaticObjects.push_back(std::make_unique<Wall>(objChar, objLoc));

		break;
	}
	case '@': //OBJECT::ROCK
	{
		m_StaticObjects.push_back(std::make_unique<Rock>(objChar, objLoc));

		break;
	}
	case '/': //OBJECT::ROBOT
	{
		m_Robot = std::make_unique<Robot>(objChar, objLoc);

		break;
	}
	case '!': //OBJECT::GUARD
	{
		m_Guards.push_back(std::make_unique<Guard>(objChar, objLoc));

		break;
	}
	case 'T': //GIFT::TIME
	{
		m_Gifts.push_back(std::make_unique<AddTime>(objChar, objLoc));
		std::cout << "pushed add time into gifts vector" << std::endl;
		std::cout << "m_gifts size:" << m_Gifts.size() << std::endl;
		break;
	}
	case 'L': //GIFT::LIFE
	{
		m_Gifts.push_back(std::make_unique<AddLife>(objChar, objLoc));

		break;
	}
	case 'F': //GIFT::FROZEN GUARD
	{
		m_Gifts.push_back(std::make_unique<FrozenGuard>(objChar, objLoc));

		break;
	}
	case 'H': //GIFT::HIDE GUARD
	{
		m_Gifts.push_back(std::make_unique<HideGuard>(objChar, objLoc));
		break;
	}
	}

}


//-----------------------------------------------------------------------------
//This function initialized the board and ask from the user to enter new
//number of rows and cols.
void Board::resetBoard(const Level& currLevel)
{
	m_rows = currLevel.getRows();
	m_cols = currLevel.getCols();
}


//-----------------------------------------------------------------------------
int Board::GetRows() const
{
	return m_rows;
}


//-----------------------------------------------------------------------------
int Board::GetCols() const
{
	return m_cols;
}


//-----------------------------------------------------------------------------
const sf::Vector2f& Board::GetBoardPos()
{
	return m_boardPosition;
}


//-----------------------------------------------------------------------------
void Board::SetBoardPos(const sf::Vector2f& boardPos)
{
	m_boardPosition = boardPos;
}


//-----------------------------------------------------------------------------
//This function draw the current board on the window (m_gameWindow).
void Board::draw(sf::RenderWindow& window) const
{
	//draw the robot
	m_Robot->draw(window);

	//draw the guards
	for (int guardIndex = 0; guardIndex < m_Guards.size(); guardIndex++)
	{
		m_Guards[guardIndex]->draw(window);
	}

	//draw the static objects
	for (int objIndex = 0; objIndex < m_StaticObjects.size(); objIndex++)
	{
		m_StaticObjects[objIndex]->draw(window);
	}

	//draw the bombs
	for (int bombIndex = 0; bombIndex < m_Bombs.size(); bombIndex++)
	{
		m_Bombs[bombIndex]->draw(window);
	}
	//std::cout << "m_gifts size in draw:  " << m_Gifts.size() << std::endl;
	for (int giftIndex = 0; giftIndex < m_Gifts.size(); giftIndex++)
	{
		//std::cout << "printing gift in index:" << giftIndex << std::endl;
		m_Gifts[giftIndex]->draw(window);
	}

	
}


//-----------------------------------------------------------------------------
void Board::addBomb(const sf::Vector2f& position)
{
	m_Bombs.push_back(std::make_unique<Bombs>(position));
	m_Bombs.back()->setBomb(position);
}


//-----------------------------------------------------------------------------
sf::Vector2f Board::getRobotPosition() const
{
	sf::Vector2f robotPos = m_Robot->GetPosition();
	return robotPos;
}


//-----------------------------------------------------------------------------
void Board::handleBombs(sf::Time deltaTime)
{
	for (int bombIndex = 0; bombIndex < m_Bombs.size(); bombIndex++) //take care active bombs
	{
		m_Bombs[bombIndex]->updateBomb(deltaTime);
	}

	for (int bombIndex = 0; bombIndex < m_Bombs.size(); bombIndex++) //delete bomb if finish 
	{
		if (!m_Bombs[bombIndex]->isBombActive() && !m_Bombs[bombIndex]->isBombExploding())
		{
			m_Bombs.erase(m_Bombs.begin() + bombIndex);
		}
	}
}


//-----------------------------------------------------------------------------
void Board::setRobotDirections(const sf::Keyboard::Key key)
{
	m_Robot->changeDirection(key);
}


//-----------------------------------------------------------------------------
void Board::MoveRobot(const sf::Keyboard::Key key, const sf::Time& deltaTime)
{
	m_Robot->Move(key, deltaTime);
}


//-----------------------------------------------------------------------------
void Board::MoveGuards(const sf::Time& deltaTime)
{
	for (int guardIndex = 0; guardIndex < m_Guards.size(); guardIndex++)
	{
		m_Guards[guardIndex]->Move(deltaTime, m_Robot->GetPosition());
	}
}


//-----------------------------------------------------------------------------
void Board::handleObjectCollision()
{
	for (const auto& staticObj : m_StaticObjects)
	{
		if (m_Robot->collideWithOthers(*staticObj))
		{
			m_Robot->handleCollision(*staticObj);
		}
	}

	for (const auto& gift : m_Gifts)
	{
		if (m_Robot->collideWithOthers(*gift))
		{
			m_Robot->handleCollision(*gift);
		}
	}

	for (int guardNum = 0; guardNum < m_Guards.size(); guardNum++)
	{
		if (m_Robot->collideWithOthers(*m_Guards[guardNum]))
		{
			m_Robot->handleCollision(*m_Guards[guardNum]);

			for (int reLocGuard = 0; reLocGuard < m_Guards.size(); reLocGuard++)
			{
				m_Guards[reLocGuard]->setSpritePos(m_Guards[reLocGuard]->getDefPos());
			}

			m_Bombs.clear();
		}

		for (int bombNum = 0; bombNum < m_Bombs.size() ;bombNum++)
		{
			if (m_Bombs[bombNum]->isBombExploding())
			{
				if (m_Guards[guardNum]->collideWithExplosiveBombs(*m_Bombs[bombNum]))
				{
					m_Guards[guardNum]->SetGuardDead(false);
				}
			}
		}
	}


	//need to change when checking if the guard is alive (?)
	for (int guardNum = 0; guardNum < m_Guards.size(); guardNum++)
	{
		for (const auto& staticObj : m_StaticObjects)
		{
			if (m_Guards[guardNum]->collideWithOthers(*staticObj))
			{
				m_Guards[guardNum]->handleCollision(*staticObj);
			}
		}

		for (int anotherGuard = 0; anotherGuard < m_Guards.size(); anotherGuard++)
		{
			if (guardNum == anotherGuard) continue;
			else
			{
				if (m_Guards[guardNum]->collideWithOthers(*m_Guards[anotherGuard]))
				{
					m_Guards[guardNum]->handleCollision(*m_Guards[anotherGuard]);
				}
			}
		}
	}
}


//-----------------------------------------------------------------------------
void Board::updateGuards()
{
	std::erase_if(m_Guards, [](const std::unique_ptr<Guard>& g) {return !g->GetIfGuardAlive(); });
}

//-----------------------------------------------------------------------------
void Board::updateGifts()
{
	//std::cout << "deleting gift" << std::endl;
	std::erase_if(m_Gifts, [](const std::unique_ptr<Gifts>& g) {return !g->isGiftTaken(); });
}

bool Board::getHideGiftStatus()
{
	return m_Robot->getHideGift();
}

void Board::HideSingleGuard()
{
	
		//rand a random number between 0 and guard.size()
		if (m_Guards.size() == 0)
			return;

		int val = rand() % m_Guards.size() - 1;
		std::cout << "deleted this random guard: " << val << std::endl;

		m_Guards[val]->SetGuardDead(false);

		m_Robot->setHideGift(false);
	
}


//-----------------------------------------------------------------------------
bool Board::isValidPosition(int row, int col) const
{
	if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
	{
		return true;
	}
	return false;
}	