#include "Objects.h/SmallFastEnemyObject.h"



bool SmallFastEnemyObject::m_registerit = FactoryObject::registerit(ENEMY_2_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<SmallFastEnemyObject>(pos); });

SmallFastEnemyObject::SmallFastEnemyObject(const sf::Vector2f& initPosition)
    :BaseEnemyObject(initPosition)
{
}

void SmallFastEnemyObject::move(float deltaTime)
{
}


void SmallFastEnemyObject::handleInput()
{
}
