#pragma once

//-----include section-----
#include "Gifts.h"
#include "constants.h"
#include "ResourceManager.h"
#include "Robot.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class HideGuard : public Gifts
{
public:
    using Gifts::Gifts;
    virtual ~HideGuard() = default;
    HideGuard(char objType, sf::Vector2f objPlace);

    virtual void handleCollision(Robot& robot) override;
};