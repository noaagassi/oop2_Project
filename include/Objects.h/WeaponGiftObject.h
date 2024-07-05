#pragma once
#include "BaseGiftObject.h"

class WeaponGiftObject : public BaseGiftObject
{
public:
    WeaponGiftObject(const sf::Vector2f& initPosition);
    WeaponGiftObject();

private:
    static bool m_registerit;
};