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
//This function draw the current board on the window (m_gameWindow).
void Board::draw(sf::RenderWindow& window, const TextureManager& tex) const
{
	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < m_cols; col++)
		{
			m_board[row][col].draw(window, tex);
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

//-----------------------------------------------------------------------------
//This function load exist board file.
void Board::LoadFile()
{
	std::fstream saved_file(BOARD_FILE_NAME);
	if (!saved_file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	saved_file >> m_rows >> m_cols;

	if (m_rows <= 0 || m_cols <= 0)
	{
		std::cerr << "Error: wrong values for board" << std::endl;
		return;
	}
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




//void Board::initialize(int rows, int cols)
// {
//    m_rows = rows;
//    m_cols = cols;
//    m_cells.resize(rows);
//
//    for (int i = 0; i < rows; ++i)
//    {
//        m_cells[i].resize(cols);
//    }
//
//    calculateCellDimensions();
//}
//
//void Board::calculateCellDimensions() 
// {
//    float cellWidth = (BOARD_WIDTH - (m_cols + 1) * CELL_SPACING) / m_cols;
//    float cellHeight = (BOARD_HEIGHT - (m_rows + 1) * CELL_SPACING) / m_rows;
//
//    for (int row = 0; row < m_rows; ++row) {
//        for (int col = 0; col < m_cols; ++col) {
//            float x = 30.f + (cellWidth + CELL_SPACING) * col;
//            float y = BUTTON_HEIGHT + 100.f + (cellHeight + CELL_SPACING) * row;
//
//            m_cells[row][col].setSize(cellWidth, cellHeight);
//            m_cells[row][col].setPosition(x, y);
//        }
//    }
//}

//void Board::draw(sf::RenderWindow& window, const TextureManager& tex) const {
//    for (int row = 0; row < m_rows; ++row) {
//        for (int col = 0; col < m_cols; ++col) {
//            m_cells[row][col].draw(window, tex);
//        }
//    }
//}
//
//void Board::loadFromFile(const std::string& filename) {
//    std::ifstream file(filename);
//    if (!file.is_open()) {
//        throw std::runtime_error("Unable to open board file: " + filename);
//    }
//
//    file >> m_rows >> m_cols;
//    file.ignore(); // Skip newline
//
//    initialize(m_rows, m_cols);
//
//    std::string line;
//    for (int row = 0; row < m_rows; ++row) {
//        std::getline(file, line);
//        for (int col = 0; col < m_cols && col < line.length(); ++col) {
//            m_cells[row][col].setObjectType(line[col]);
//        }
//    }
//}
//
//void Board::saveToFile(const std::string& filename) const {
//    std::ofstream file(filename);
//    if (!file.is_open()) {
//        throw std::runtime_error("Unable to create board file: " + filename);
//    }
//
//    file << m_rows << " " << m_cols << std::endl;
//    for (int row = 0; row < m_rows; ++row) {
//        for (int col = 0; col < m_cols; ++col) {
//            file << m_cells[row][col].getObjectType();
//        }
//        file << std::endl;
//    }
//}
//
//void Board::clear() {
//    m_cells.clear();
//    m_rows = 0;
//    m_cols = 0;
//}
//
//Cell& Board::getCell(int row, int col) {
//    if (!isValidPosition(row, col)) {
//        throw std::out_of_range("Cell position out of bounds");
//    }
//    return m_cells[row][col];
//}
//
//const Cell& Board::getCell(int row, int col) const {
//    if (!isValidPosition(row, col)) {
//        throw std::out_of_range("Cell position out of bounds");
//    }
//    return m_cells[row][col];
//}
//
//bool Board::isValidPosition(int row, int col) const {
//    return row >= 0 && row < m_rows && col >= 0 && col < m_cols;
//}














//-----------------------------------------------------------------------------
//This function update the board in case of changes.
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
