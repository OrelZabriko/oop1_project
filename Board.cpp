
//-----include section-----
#include "Board.h"
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
Board::Board() : m_rows(0), m_cols(0), m_board()
{
}


//-----------------------------------------------------------------------------
//This function initialized the board and ask from the user to enter new 
//number of rows and cols.
void Board::resetBoard(const int rows, const int cols)
{
	m_rows = rows;
	m_cols = cols;

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
bool Board::CheckIfInBoard(const sf::Vector2f mousePosition, sf::Vector2i& boardCord) const
{
	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < m_cols; col++)
		{
			sf::Vector2f cellPos = m_board[row][col].GetCellPosition();
			sf::Vector2f cellSize = m_board[row][col].GetCellSize();

			if (CheckLimits(mousePosition, cellPos, cellSize))
			{
				boardCord = sf::Vector2i({ row, col });
				return true;
			}
		}
	}

	return false;
}


////-----------------------------------------------------------------------------
////This function update the board in case of changes.
//void Board::update(const sf::Vector2i boardCord, OBJECT obj,
//	bool& checkExistencePlayer)
//{
//	if (obj == OBJECT::Erase)
//	{
//		if (m_board[boardCord.x][boardCord.y].GetObjectType() ==
//			getCharByEnum(OBJECT::Robot))
//		{
//			checkExistencePlayer = true;
//			m_board[boardCord.x][boardCord.y].SetObjectType(' ');
//			return;
//		}
//
//		m_board[boardCord.x][boardCord.y].SetObjectType(' ');
//
//		return;
//	}
//
//	if (m_board[boardCord.x][boardCord.y].GetObjectType() ==
//		getCharByEnum(OBJECT::Robot))
//	{
//		checkExistencePlayer = true;
//	}
//
//	char objChar = getCharByEnum(obj);
//	m_board[boardCord.x][boardCord.y].SetObjectType(objChar);
//}
//
//
////-----------------------------------------------------------------------------
////This function draw the current board on the window (m_gameWindow).
//void Board::draw(sf::RenderWindow& window, const TextureManager& tex) const
//{
//	for (int row = 0; row < m_rows; row++)
//	{
//		for (int col = 0; col < m_cols; col++)
//		{
//			m_board[row][col].draw(window, tex);
//		}
//	}
//}


//-----------------------------------------------------------------------------
//This function erase all the objects from the board.
void Board::delete_board()
{
	m_board.clear();
}


//-----------------------------------------------------------------------------
//This function load exist board file.
void Board::LoadFile()
{
	std::fstream saved_file(BOARD_FILE_NAME);
	if (!saved_file.is_open())
	{
		std::cerr << "Error: file is already opened" << std::endl;
		return;
	}

	saved_file >> m_rows >> m_cols;
	saved_file.ignore();
	resetBoard(m_rows, m_cols);

	for (int row = 0; row < m_rows; row++)
	{
		std::string line;
		std::getline(saved_file, line);

		for (int col = 0; col < m_cols; col++)
		{
			m_board[row][col].SetObjectType(line[col]);
		}
	}

	saved_file.close();
}


//-----------------------------------------------------------------------------
//This function saving the file board at the moment of clicking the 'save' 
//button into the file 'Board.txt'.
void Board::SavingFile()
{
	std::ofstream saved_file(BOARD_FILE_NAME);

	if (!saved_file.is_open())
	{
		std::cerr << "Error: file is already open" << std::endl;
		return;
	}

	saved_file << m_rows << " " << m_cols << std::endl;

	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < m_cols; col++)
		{
			saved_file << m_board[row][col].GetObjectType();
		}
		saved_file << std::endl;
	}

	saved_file.close();
}


//-----------------------------------------------------------------------------
//This helper function check if the mouse is on one of the board cells. If yes,
//the function mark the cell in red rectangle.
//void Board::CheckHover(sf::Vector2f mousePosition,
//	sf::RenderWindow& m_gameWindow,
//	const TextureManager& textures)
//{
//	for (int row = 0; row < m_rows; row++)
//	{
//		for (int col = 0; col < m_cols; col++)
//		{
//			sf::Vector2f cellPos = m_board[row][col].GetCellPosition();
//			sf::Vector2f cellSize = m_board[row][col].GetCellSize();
//
//			bool isHovered = CheckLimits(mousePosition, cellPos, cellSize);
//			m_board[row][col].SetHovered(isHovered);
//
//			if (m_board[row][col].GetHovered())
//			{
//				m_board[row][col].draw(m_gameWindow, textures);
//			}
//		}
//	}
//}