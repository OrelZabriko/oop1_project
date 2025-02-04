#pragma once

//-----include section-----
#include "Constants.h"
#include "ResourceManager.h"
#include "Level.h"
#include "Wall.h"
#include "Door.h"
#include "Robot.h"
#include "Guard.h"
#include "Rock.h"
#include "StaticObjects.h"
#include "Bombs.h"
#include "AddTime.h"
#include "AddLife.h"
#include "FrozenGuard.h"
#include "HideGuard.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


//-----class section-----
class Board
{
public:
	Board();
	Board(int rows, int cols);
	void createCell(const char objChar, const sf::Vector2f objLoc);

	void resetBoard(const Level& currLevel);

	int GetRows() const;
	int GetCols() const;

	const sf::Vector2f& GetBoardPos();
	void SetBoardPos(const sf::Vector2f& boardPos);

	bool isValidPosition(int row, int col) const;
	
	void draw(sf::RenderWindow& window) const;
	
	void handleBombs(sf::Time deltaTime);
	void addBomb(const sf::Vector2f& position);
	sf::Vector2f getRobotPosition() const;

	void setRobotDirections(const sf::Keyboard::Key key);
	void MoveRobot(const sf::Keyboard::Key key, const sf::Time& deltaTime);
	void MoveGuards(const sf::Time& deltaTime);

	void handleObjectCollision();

	bool returnIfNeedToDecLife();

	void updateGuards();

	void updateGifts();
	bool getHideGiftStatus();

	void HideSingleGuard();
	

private:
	int m_rows;
	int m_cols;
	sf::Vector2f m_boardPosition;
	std::unique_ptr<Robot> m_Robot;
	std::vector<std::unique_ptr<Guard>> m_Guards;
	std::vector<std::unique_ptr<StaticObjects>> m_StaticObjects;
	std::vector<std::unique_ptr<Gifts>> m_Gifts;
	std::vector<std::unique_ptr<Bombs>> m_Bombs;
};