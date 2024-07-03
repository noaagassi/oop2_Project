#pragma once
#include "BaseWeaponObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "TextureHandler.h"

class PlayerWeaponObject : public BaseWeaponObject
{
public:
    PlayerWeaponObject();
    void addBall();
protected:
    int m_numOfBalls;
};