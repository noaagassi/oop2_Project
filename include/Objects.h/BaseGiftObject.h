#pragma once
#include "StaticObject.h"

class BaseGiftObject : public StaticObject
{
public:
    BaseGiftObject(const sf::Vector2f& initPosition);
    BaseGiftObject();
    bool toDelete();
    void toDelete(bool);
private:
    bool m_toDelete;
};