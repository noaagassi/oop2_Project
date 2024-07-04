#include "Objects.h/BallObject.h"
#include <iostream>

bool BallObject::m_registerit = FactoryObject::registerit(BULLET_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BallObject>(pos); });


BallObject::BallObject(const sf::Vector2f& position)
    : BulletObject(position)
{
    m_speed = 100.0f;
    setObjTexture(BULLET_OBJ);
    setTheScale(0.02f, 0.02f);

}


void BallObject::update(float deltaTime, sf::RenderWindow* window)
{
    m_position += m_direction * m_speed * deltaTime;
    m_objectSprite.setPosition(m_position);


    if ((m_target.x - m_position.x) <= 5
        && (m_target.x - m_position.x) >= -5
        && (m_target.y - m_position.y) <= 5
        && (m_target.y - m_position.y) >= -5)
    {
        m_toDelete = true;
    }

}




