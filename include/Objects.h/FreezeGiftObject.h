#pragma once
#include "Objects.h/BaseGiftObject.h"

class FreezeGiftObject : public BaseGiftObject
{
public:
    FreezeGiftObject(const sf::Vector2f& initPosition);
    FreezeGiftObject();
private:
    static bool m_registerit;
    bool m_isFreeze;
};