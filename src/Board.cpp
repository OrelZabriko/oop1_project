//-----include section-----
#include "Board.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>


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

	for (const auto& guard : m_Guards)
	{
		if (m_Robot->collideWithOthers(*guard))
		{
			m_Robot->handleCollision(*guard);
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
	}
}


//-----------------------------------------------------------------------------
//This function erase all the objects from the board.
//void Board::delete_board()
//{
//	m_board.clear();
//}


//-----------------------------------------------------------------------------
bool Board::isValidPosition(int row, int col) const
{
	if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
	{
		return true;
	}
	return false;
}


//-----------------------------------------------------------------------------
