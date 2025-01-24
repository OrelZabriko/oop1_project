#pragma once

//-----include section-----
#include "Constants.h"
#include "ResourceManager.h"

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
class Button
{
public:
	Button(char buttonType);

	sf::Vector2f getPosition() const;
	void setPosition(int place);

	sf::Vector2f getSize() const;
	void setSize();

	const char getButtonType() const;

	void setIsOnIt(bool isOnIt);
	bool getIsOnIt() const;

	sf::RectangleShape makeButtonRectangle() const;
	void draw(sf::RenderWindow& window, char buttonType) const;


private:
	char m_buttonType;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	bool m_isOnIt = false;
};