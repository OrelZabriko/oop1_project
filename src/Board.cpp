//-----include section-----
#include "Board.h"
#include "Cell.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>


//-----functions section------
//-----------------------------------------------------------------------------
Board::Board() : m_rows(0), m_cols(0)
{}

//-----------------------------------------------------------------------------
Board::Board(const char objChar, const sf::Vector2f objLoc)
{
	switch (objChar)
	{
	case 'D': //OBJECT::DOOR
	{
		

		break;
	}
	case '#': //OBJECT::WALL
	{
		

		break;
	}
	case '@': //OBJECT::ROCK
	{
		return '@';

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


	m_board.resize(m_rows);
	for (int row = 0; row < m_rows; row++)
	{
		m_board[row].resize(m_cols);
		for (int col = 0; col < m_cols; col++)
		{
			m_board[row][col].SetRow(m_rows);
			m_board[row][col].SetCol(m_cols);
			m_board[row][col].SetCellSize();
			m_board[row][col].SetCellPos(col, row);

			if (row < currLevel.getRows() && col < currLevel.getCols()) {
				m_board[row][col].SetObjectType(currLevel.GetObjChar(row, col));
			}
			else {
				// Handle the case where the indices are out of range
				m_board[row][col].SetObjectType(' '); // or some default value
			}
		}
	}
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
void Board::Draw(sf::RenderWindow& window, const Level& currLevel) const
{
	if (currLevel.getRows() != m_rows || currLevel.getCols() != m_cols)
	{
		std::cerr << "Error: Board and Level sizes do not match!" << std::endl;
		return;
	}

	std::cout << "Board cols: " << m_cols << " Board rows: " << m_rows << std::endl;

	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < m_cols; col++)
		{
			char objChar = currLevel.GetObjChar(row, col);
			m_board[row][col].draw(window, objChar);
		}
	}
}


//-----------------------------------------------------------------------------
//This function erase all the objects from the board.
void Board::delete_board()
{
	m_board.clear();
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