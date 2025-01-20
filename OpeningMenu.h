#pragma once

//-----include section-----
#include "Button.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <memory>
#include <vector>


//-----class section-----
class OpeningMenu
{
public:
	OpeningMenu();



private:
	sf::RenderWindow m_startMenu;
	std::unique_ptr<std::vector<Button>> m_menuButtons;
};