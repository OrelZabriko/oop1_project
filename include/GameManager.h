#pragma once

//-----include section-----
#include "Board.h"
#include "Level.h"
#include "Bombs.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <memory>
#include <vector>


//-----class section-----
class GameManager
{
public:
	GameManager() = default;
	GameManager(const Level& currLevel);

	Board& getBoard();
	void dropBomb();
	void draw(sf::RenderWindow& window);
	void updateBombs(const sf::Time deltaTime);
	void updateRobot(sf::Keyboard::Key key,
					const sf::Time deltaTime);
	void updateGuards(const sf::Time deltaTime);
	sf::Vector2f getPlayerPosition() const;


private:
	const Level& m_currLevel;
	Board m_currBoard;
};