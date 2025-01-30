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
void Board::updatePlayer(const sf::Keyboard::Key key, const sf::Time& deltaTime)
{
	m_Robot->setPrevPosition(m_Robot->getPrevPosition());
	m_Robot->changeDirection(key);
	sf::Vector2f moveOffset = m_Robot->getDirection() * PIXELS_FOR_MOVE * deltaTime.asSeconds();
	//m_Robot->updateSpritePos(moveOffset);
	m_Robot->getSprite().move(moveOffset);


	
	std::cout << "robot position: " << m_Robot->GetPosition().x << " " << m_Robot->GetPosition().y << std::endl;

	for (int guardIndex = 0; guardIndex < m_Guards.size(); guardIndex++)
	{
		std::cout << "Im in guard: " << guardIndex << std::endl;
		std::cout << "guard: " << guardIndex << "position is: " << m_Guards[guardIndex]->getDirection().x 
								<< " " << m_Guards[guardIndex]->getDirection().y << std::endl;

		m_Guards[guardIndex]->setDirection(m_Robot->GetPosition());

		std::cout << "guard: " << guardIndex << "position is: " << m_Guards[guardIndex]->getDirection().x
			<< " " << m_Guards[guardIndex]->getDirection().y << " after change" << std::endl;

		sf::Vector2f moveGuardOffset = m_Guards[guardIndex]->getDirection() * PIXELS_FOR_MOVE * deltaTime.asSeconds();

		std::cout << "moveGuardOffset position is: " << moveGuardOffset.x << " " << moveGuardOffset.y << std::endl;

		m_Guards[guardIndex]->getSprite().move(moveGuardOffset);
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
