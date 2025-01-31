#pragma once

//-----include section-----
#include "OpeningMenu.h"
#include "GameManager.h"
#include "Objects.h"
#include "Board.h"
#include "LoadLevel.h"
#include "Level.h"
#include "InfoBar.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <fstream>
#include <memory>
#include <vector>


//-----class section-----
class Controller
{
public:
	Controller() = default;

	void Run();

	void handleOpenMenuMouseClick(sf::RenderWindow& window,
								  OpeningMenu& start_menu,
								  LoadLevel& levelManager);
	void handleKeyPressed(sf::Keyboard::Key key, 
						  const sf::Time deltaTime, 
						  GameManager& manager);

	void setMenuState(bool state);


private:
	sf::RenderWindow m_GameWindow;
	bool m_startMenuState = false;   //false == start menu //true == game started
	Level m_currLevel;
	InfoBar m_infoBar;
};