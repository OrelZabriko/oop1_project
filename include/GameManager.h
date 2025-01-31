#pragma once

//-----include section-----
#include "Board.h"
#include "Level.h"

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

	void draw(sf::RenderWindow& window);

	void setRobotDirection(sf::Keyboard::Key key);
	void HandleTheCollision();

	void updateRobot(sf::Keyboard::Key key,
					const sf::Time deltaTime);
	void updateGuards(const sf::Time deltaTime);


private:
	const Level& m_currLevel;
	Board m_currBoard;
};