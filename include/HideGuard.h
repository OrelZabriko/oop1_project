#pragma once

//-----include section-----
#include "Gifts.h"
#include "constants.h"
#include "ResourceManager.h"
#include "Robot.h"

#include <SFML/Graphics.hpp>

class HideGuard : public Gifts
{
public:
    using Gifts::Gifts;
    HideGuard(char objType, sf::Vector2f objPlace);
    //void draw(sf::RenderWindow& window);

   // virtual void handleCollision(Objects& otherObject) override {}
    virtual void handleCollision(Robot& robot) override;
    virtual void handleCollision(Guard& guard) override {}
    virtual void handleCollision(Wall& wall) override {}
    virtual void handleCollision(Rock& rock) override {}
    virtual void handleCollision(Door& door) override {}
    virtual void handleCollision(HideGuard& gift) override;
};