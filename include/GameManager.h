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

	Board& getBoard();

	void draw(sf::RenderWindow& window);

	void moveObjects(sf::RenderWindow& window, sf::Keyboard::Key key,
					const sf::Time deltaTime);


private:
	const Level& m_currLevel;
	Board m_currBoard;
};