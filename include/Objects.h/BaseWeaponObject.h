#pragma once
#include "FlashlightObject.h"
#include "MovingObject.h"

class BaseWeaponObject 
{
public:
    BaseWeaponObject();

    void setFireRate(float rate);
    void update(float deltaTime,sf::RenderWindow* window);
    std::vector<std::unique_ptr<MovingObject>> retrieveBullets();
    void draw(sf::RenderWindow* window);

protected:
    float m_fireRate;
    std::vector<std::unique_ptr<MovingObject>> m_bullets; 
};