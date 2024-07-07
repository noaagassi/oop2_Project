#pragma once
#include "FlashlightObject.h"
#include "MovingObject.h"

class BaseWeaponObject 
{
public:
    BaseWeaponObject();

    
    void setFireRate(float rate);
    void update(float deltaTime);
    std::vector<std::unique_ptr<MovingObject>> retrieveBullets();


protected:
    float m_fireRate;
    std::vector<std::unique_ptr<MovingObject>> m_bullets; 
};