#include "Objects.h/RocketObject.h"

bool RocketObject::m_registerit = FactoryObject::registerit(ROCKET_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<RocketObject>(pos); });



RocketObject::RocketObject(const sf::Vector2f& position)
    : BulletObject(position)
{
    setObjTexture(ROCKET_OBJ);
    setTheScale(0.03f, 0.03f);
}

void RocketObject::update(float deltatime, sf::RenderWindow* window)
{
    m_velocity = m_direction * 200.0f;
    m_objectSprite.move(m_velocity * deltatime);
}

void RocketObject::draw(sf::RenderWindow* window) const
{
    window->draw(m_objectSprite);
}


