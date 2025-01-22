#pragma once

//-----include section-----
#include "Objects.h"
#include "ResourceManager.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Robot : public Objects
{
public:
	using Objects::Objects;
	virtual ~Robot() = default;


	void SetTexture();

private:
	//sf::Sprite m_RobotSprite;
};