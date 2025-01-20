//-----include section-----

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <LoadLevel.h>


//-----functions section------
//-----------------------------------------------------------------------------
bool LoadLevel::loadGameLevel(int levelNumber)
{
	std::string levelname = "level" + std::to_string(levelNumber) + ".txt";
	return readLevelFromFile(levelname);
}

//-----------------------------------------------------------------------------

bool LoadLevel::readLevelFromFile(const std::string& levelname)
{
	std::ifstream file(levelname);
	if (!file.is_open())
	{
		std::cerr << "Could not open level file: " << levelname << std::endl;
		return false;
	}

	m_board.resetBoard();

	std::string line;
	int row = 0;

	while (std::getline(file, line) && row < m_board.GetRows())
	{
		int lineLength = line.length(); // length of the line that read from the file
		int colsToRead = std::min(lineLength, m_board.GetCols()); // in order to avoid reading more than the board size

		for (int col = 0; col < colsToRead; col++)
		{
			m_board[row][col] = line[col];
		}
		row++;
	}

	file.close();
	return true;
}

//-----------------------------------------------------------------------------








