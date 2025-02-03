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

	void loadLevel(const Level& currLevel);

	void draw(sf::RenderWindow& window);
	
	void setRobotDirection(sf::Keyboard::Key key);
	void HandleTheCollision();

	void dropBomb();
	void updateBombs(const sf::Time deltaTime);
	void updateRobot(sf::Keyboard::Key key,
					const sf::Time deltaTime);
	void updateGuards(const sf::Time deltaTime);

	void SetStartGame(const bool ifStart);
	const bool& GetIfStartGame() const;


private:
	const Level& m_currLevel;
	Board m_currBoard;
	bool m_startGame = false; //only if the player pressed new game it opposite to true and start the guards movement
};