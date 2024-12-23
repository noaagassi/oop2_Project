#include "Objects.h/SuperWeaponObject.h"
#include <iostream>
#include "SoundsHandler.h"

SuperWeaponObject::SuperWeaponObject()
    :PlayerWeaponObject()
{
    m_fireRate = 1.0;

}

void SuperWeaponObject::shoot(FlashlightObject flashlight)
{
    sf::Vector2f start = flashlight.getShape().getPoint(0);
    sf::Vector2f vertex1 = flashlight.getShape().getPoint(1);
    sf::Vector2f vertex2 = flashlight.getShape().getPoint(2);

    SoundsHandler::getInstance().playSound(Sound_Id::BOMB_SHOOT);

    sf::Vector2f target = (vertex1 + vertex2) / 2.0f; 
    auto bomb = std::make_unique<BombObject>(start);
    bomb->setTarget(target);
    m_bullets.push_back(std::move(bomb));

    
}