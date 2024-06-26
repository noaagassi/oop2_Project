#pragma once
#include "ExpandObject.h"
#include "FactoryObject.h"

class PoisonObject : public BaseObject
{
public:
    PoisonObject(const sf::Vector2f& initPosition);
    void update(const sf::Time elapceTime);
    std::vector<PoisonObject> getPoisonVec();
private:
    void ExpandPoisen();
    int m_PoisenFrame;
    std::vector<PoisonObject> m_Poisons;
    static bool m_registerit;
    sf::Time m_checkTime;
};