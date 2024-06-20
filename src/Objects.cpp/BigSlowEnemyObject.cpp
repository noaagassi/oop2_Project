#include "Objects.h/BigSlowEnemyObject.h"



bool BigSlowEnemyObject::m_registerit = FactoryObject::registerit(ENEMY_1_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BigSlowEnemyObject>(pos); });

BigSlowEnemyObject::BigSlowEnemyObject(const sf::Vector2f& initPosition)
{
}