//-----include section-----
#include "Level.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <iostream>



//-----functions section------
//-----------------------------------------------------------------------------
Level::Level() 
{
}


//-----------------------------------------------------------------------------
void Level::setCols(const int cols)
{
	m_cols = cols;
}


//-----------------------------------------------------------------------------
const int Level::getRows() const
{
	return m_rows;
}
const int Level::getCols() const
{
	return m_cols;
}


//-----------------------------------------------------------------------------
void Level::setRows(const int rows)
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
	m_matrix.push_back(line);
}

