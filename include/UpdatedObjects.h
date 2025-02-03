#pragma once

//-----include section-----
#include "Objects.h"


//-----class section-----
class UpdatedObjects : public Objects
{
	using Base = Objects;
public:
	using Objects::Objects;
	UpdatedObjects();
	virtual ~UpdatedObjects() = default;

	//virtual sf::Vector2f updateMovement(ENUM DIRECTIONS,DELATTIME);
	void Move(sf::Vector2f offset);
	
	void setSpritePos(sf::Vector2f newPos);

	void setStartPos(const sf::Vector2f& startPos);
	sf::Vector2f getStartPosition() const;
	void setPrevPosition(sf::Vector2f position);
	sf::Vector2f getPrevPosition() const;
	

private:
	sf::Vector2f m_startPos;
	sf::Vector2f m_previousPos;
};
