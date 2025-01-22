//-----include section-----
#include "Cell.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <cctype>


//-----functions section------
//-----------------------------------------------------------------------------
Cell::Cell() : m_objectType(' '),
m_position(sf::Vector2f(0, 0)), m_size(sf::Vector2f(0, 0))
{}


//-----------------------------------------------------------------------------
void Cell::SetRow(int rows)
{
    m_rows = rows;
}


//-----------------------------------------------------------------------------
void Cell::SetCol(int cols)
{
    m_cols = cols;
}


//-----------------------------------------------------------------------------
void Cell::SetCellSize()
{
    //set the size of each cell
    m_size.x = BOARD_WIDTH / m_rows;
    m_size.y = BOARD_HEIGHT / m_cols;
}


//-----------------------------------------------------------------------------
sf::Vector2f Cell::GetCellSize() const
{
    return m_size;
}


//-----------------------------------------------------------------------------
void Cell::SetCellPos(int col, int row)
{
    //set the position of each cell
    m_position.x = (m_size.x + CELL_SPACING) * col + 30.f;
    m_position.y = BUTTON_HEIGHT + 100.f + (m_size.y + CELL_SPACING) * row;
}


//-----------------------------------------------------------------------------
sf::Vector2f Cell::GetCellPosition() const
{
    return m_position;
}


//-----------------------------------------------------------------------------
sf::RectangleShape Cell::MakeCellRectangle() const
{
    sf::RectangleShape cellRectangle(m_size);

    cellRectangle.setPosition(m_position);

    if (m_isHovered)
    {
        cellRectangle.setOutlineThickness(7.5);
        cellRectangle.setOutlineColor(sf::Color::Red);
    }
    else
    {
        cellRectangle.setOutlineThickness(3);
        cellRectangle.setOutlineColor(sf::Color::Black);
    }

    cellRectangle.setTexture(NULL);

    return cellRectangle;
}


//-----------------------------------------------------------------------------
// Draws the cell: empty rectangle if no texture, textured sprite otherwise.
void Cell::draw(sf::RenderWindow& window, const char objChar) const
{
    // Create and draw the cell rectangle
    sf::RectangleShape cellRectangle = MakeCellRectangle();
    window.draw(cellRectangle);

    // Check if a texture exists
    if (objChar != ' ')
    //if (m_objectType != ' ')
    {
        //sf::Texture new_tex = ResourceManager::getInstance().getObjectTexture(getObjByChar(GetObjectType()));
        sf::Texture new_tex = ResourceManager::getInstance().getObjectTexture(getObjByChar(objChar));

        // Create and configure the sprite
        sf::Sprite cellSprite;
        cellSprite.setTexture(new_tex); // Dereference the texture pointer
        cellSprite.setPosition(m_position);

        // Scale the sprite to match the cell size
        sf::Vector2u textureSize = new_tex.getSize();
        float scaleX = m_size.x / textureSize.x;
        float scaleY = m_size.y / textureSize.y;
        cellSprite.setScale(scaleX, scaleY);

        // Draw the textured sprite
        window.draw(cellSprite);
    }
    else
    {
        // No texture, fill the cell with a default color (e.g., light gray)
        cellRectangle.setFillColor(sf::Color(200, 200, 200)); // Light gray
        window.draw(cellRectangle);
    }
}


//-----------------------------------------------------------------------------
//This function return the object type that the cell contain.
char Cell::GetObjectType() const
{
    return m_objectType;
}


//-----------------------------------------------------------------------------
//This function save the object type in the cell.
void Cell::SetObjectType(char obj)
{
    m_objectType = obj;
}


//-----------------------------------------------------------------------------
const sf::Sprite& Cell::GetObjectSprite() const
{
    return m_cellSprite;
}


//-----------------------------------------------------------------------------
void Cell::SetObjectSprite(sf::Texture obj)
{
    m_cellSprite.setTexture(obj);
}