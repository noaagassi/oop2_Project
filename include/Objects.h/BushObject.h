#pragma once
#include "StaticObject.h"

class BushObject : public StaticObject
{
public:
    BushObject(const sf::Vector2f& initPosition);
    BushObject();
    void resetColor();
    void makeTranslucent();

private:
    static bool m_registerit;
};