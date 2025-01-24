#pragma once

//-----include section-----
#include "cell.h"
#include "Constants.h"
#include "ResourceManager.h"
#include "Level.h"
#include "Robot.h"
#include "Guard.h"
#include "StaticObjects.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>



//-----class section-----
class Board
{
public:
	Board();

	void resetBoard(const Level& currLevel);

	int GetRows() const;
	int GetCols() const;

	//bool CheckIfInBoard(const sf::Vector2f mousePosition, sf::Vector2i& boardCord) const;
	//void update(const sf::Vector2i boardCord, OBJECT obj, bool& checkExistencePlayer);

	//bool CheckIfInBoard(const sf::Vector2f mousePosition, sf::Vector2i& boardCord) const;
	//void update(const sf::Vector2i boardCord, OBJECT obj, bool& checkExistencePlayer);

	void delete_board();
	bool isValidPosition(int row, int col) const;
	void Draw(sf::RenderWindow& window, const Level& currLevel) const;

	//void CheckHover(sf::Vector2f mousePosition,
	//sf::RenderWindow& m_gameWindow,
	//const TextureManager& textures);


private:
	int m_rows;
	int m_cols;
	//std::vector<std::vector<Cell>> m_board;
	std::unique_ptr<Robot> m_Robot;
	std::vector<std::unique_ptr<Guard>> m_Guards;
	std::vector<std::unique_ptr<StaticObjects>> m_StaticObjects;
};