#pragma once
#include "StaticObject.h"
#include "FlashlightObject.h"

class BaseWeaponObject 
{
public:
    BaseWeaponObject();

    virtual void shoot(FlashlightObject flashlight) = 0;
    void setFireRate(float rate);
    void update(float deltaTime);
    std::vector<std::unique_ptr<MovingObject>> retrieveBullets();

protected:
    float m_fireRate;
    std::vector<std::unique_ptr<MovingObject>> m_bullets;
};