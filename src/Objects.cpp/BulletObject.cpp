#include "Objects.h/BulletObject.h"


bool BulletObject::m_registerit = FactoryObject::registerit(TREES_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BulletObject>(pos); });


BulletObject::BulletObject(const sf::Vector2f& position, const sf::Vector2f& direction)
    : MovingObject(position), m_direction(direction) 
{
        m_shape.setRadius(5.f); 
        m_shape.setPosition(m_position);
}

void BulletObject::update(float deltaTime)
{
    m_position += m_direction * m_speed * deltaTime;
    m_shape.setPosition(m_position);
}

void BulletObject::draw(sf::RenderWindow* window)
{
    window->draw(m_shape);
}

sf::FloatRect BulletObject::getBounds() const
{
    return m_shape.getGlobalBounds();
}


