#pragma once

//-----include section-----

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Constants.h"

//-----class section-----
class Board
{
public:
	Board();

	void resetBoard(const int rows, const int cols);

	int GetRows() const;
	int GetCols() const;

	bool CheckIfInBoard(const sf::Vector2f mousePosition, sf::Vector2i& boardCord) const;
	//void update(const sf::Vector2i boardCord, OBJECT obj, bool& checkExistencePlayer);

	void delete_board();

	//void draw(sf::RenderWindow& window, const TextureManager& tex) const;

	void LoadFile();
	void SavingFile();

	//void CheckHover(sf::Vector2f mousePosition,
		//sf::RenderWindow& m_gameWindow,
		//const TextureManager& textures);

private:
	int m_rows;
	int m_cols;
	//std::vector<std::vector<Cell>> m_board;
};