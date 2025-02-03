//-----include section-----
#include "Objects.h"

#include <iostream>


//-----functions section------
//-----------------------------------------------------------------------------
Objects::Objects(char objType, sf::Vector2f objPlace) //: m_objPlace(objPlace)
{
	m_objSprite.setTexture(ResourceManager::getInstance().getObjectTexture(getObjByChar(objType)));
	sf::Texture tex = ResourceManager::getInstance().getObjectTexture(getObjByChar(objType));
	m_objSprite.setPosition(objPlace.x * 55.f + 7.5f, objPlace.y * 55.f + INFOBAR_SPACE);
	m_defaultPos.x = objPlace.x * 55.f + 7.5f;
	m_defaultPos.y = objPlace.y * 55.f + INFOBAR_SPACE;
	sf::Vector2f scale = { 50.0f / tex.getSize().x,50.0f / tex.getSize().y };
	m_objSprite.setScale(scale);

}


//-----------------------------------------------------------------------------
void Objects::draw(sf::RenderWindow& window)
{
	window.draw(m_objSprite);
}

bool Objects::collideWithExplosiveBombs(Objects& object)
{
	bool  result = false;
	sf::FloatRect guardRect = m_objSprite.getGlobalBounds();
	sf::Vector2f center = object.getSprite().getPosition();
	std::cout << "guard rect pos  x : " << guardRect.getPosition().x << "guard rect pos y: " << guardRect.getPosition().y << std::endl;
	std::cout << "center of bomb x: " << center.x << "y: " << center.y << std::endl;
	std::vector<sf::Vector2f> positions = { {center.x + EXPLOSION_RANGE,center.y},
		{center.x - EXPLOSION_RANGE,center.y},
		{center.x,center.y - EXPLOSION_RANGE},
		{center.x,center.y + EXPLOSION_RANGE} }; // right left, up down
	for (auto& vector : positions)
	{
		if (guardRect.contains(vector))
			result = true;
	}
	return result;
}


//-----------------------------------------------------------------------------
void Objects::SetTexture(const sf::Texture& texture)
{
	m_objSprite.setTexture(texture);
}


//-----------------------------------------------------------------------------
//sf::Vector2f Objects::GetPosition() const
//{
//	return m_objPlace;
//}


//-----------------------------------------------------------------------------
sf::Sprite& Objects::getSprite()
{
	return m_objSprite;
}

sf::Vector2f Objects::getDefPos() const
{
	return m_defaultPos;
}



//-----------------------------------------------------------------------------
bool Objects::collideWithOthers(const Objects& object)
{
	return m_objSprite.getGlobalBounds().intersects(object.m_objSprite.getGlobalBounds());
}





//-----------------------------------------------------------------------------
//const sf::Vector2f& Objects::getPos() const
//{
//	return m_objPlace;
//}


//-----------------------------------------------------------------------------
void Objects::setSpritePos(sf::Vector2f newPos)
{
	m_objSprite.setPosition(newPos);
}


//-----------------------------------------------------------------------------
const sf::Vector2f& Objects::GetPosition() const
{
	return m_objSprite.getPosition();
}
