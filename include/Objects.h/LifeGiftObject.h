#pragma once
#include "Objects.h/BaseGiftObject.h"

class LifeGiftObject : public BaseGiftObject
{
public:
    LifeGiftObject(const sf::Vector2f& initPosition);
    LifeGiftObject();

private:
    static bool m_registerit;
};