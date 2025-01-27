//-----include section-----
#include "Level.h"

#include <SFML/Graphics.hpp>
#include <iostream>


//-----functions section------
//-----------------------------------------------------------------------------
void Level::setLevelCols(const int cols)
{
	m_cols = cols;
}


//-----------------------------------------------------------------------------
const int Level::getRows() const
{
	return m_rows;
}


//-----------------------------------------------------------------------------
const int Level::getCols() const
{
	return m_cols;
}


//-----------------------------------------------------------------------------
void Level::setLevelRows(const int rows)
{
	m_rows = rows;
}


//-----------------------------------------------------------------------------
const std::vector<std::string>& Level::getMatrix()
{
	return m_matrix;
}


//-----------------------------------------------------------------------------
void Level::setCell(const std::string line)
{
	std::cout << "curr line in matrix:" << line << std::endl;
	m_matrix.push_back(line);
}


//-----------------------------------------------------------------------------
const char& Level::GetObjChar(int row, int col) const
{
	std::cout << "getObjChar returning:" << m_matrix[row][col] << std::endl;
	return m_matrix[row][col];
}