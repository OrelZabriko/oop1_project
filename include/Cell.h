#pragma once

//-----include section-----
#include "ResourceManager.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


//-----class section-----
class Cell
{
public:
	Cell();

	void SetRow(int rows);
	void SetCol(int cols);

	void SetCellSize();
	sf::Vector2f GetCellSize() const;

	void SetCellPos(int col, int row);
	sf::Vector2f GetCellPosition() const;

	char GetObjectType() const;
	void SetObjectType(char obj);

	const sf::Sprite& GetObjectSprite() const;
	void SetObjectSprite(sf::Texture obj);


	//bool contains(const sf::Vector2f& point) const;
	
	//void SetHovered(bool isHovered);
	//bool GetHovered() const;

	sf::RectangleShape MakeCellRectangle() const;
	void draw(sf::RenderWindow& window, const char objChar) const;


private:
	int m_rows = 0; //save the number of the rows of the board vor calculations
	int m_cols = 0; //save the number of the cols of the board vor calculations

	char m_objectType;
	sf::Sprite m_cellSprite;

	sf::Vector2f m_position;
	sf::Vector2f m_size;

	//sf::RectangleShape createCellShape() const;
	
	bool m_isHovered = false;
};