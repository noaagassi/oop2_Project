#pragma once
#include "PlayerWeaponObject.h"
#include "FlashlightObject.h"
#include "BulletObject.h" 

class BallsWeaponObject : public PlayerWeaponObject
{
public:
    BallsWeaponObject();
    void shoot(FlashlightObject flashight) ;
    
private:
    //int m_numOfBalls;
};