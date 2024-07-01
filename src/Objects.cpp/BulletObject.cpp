#include "Objects.h/BulletObject.h"


bool BulletObject::m_registerit = FactoryObject::registerit(BULLET_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BulletObject>(pos); });


BulletObject::BulletObject(const sf::Vector2f& position)
    : MovingObject(position)
{
        m_shape.setRadius(5.f); 
        m_shape.setPosition(m_position);
        m_shape.setFillColor(sf::Color::Red);
}



void BulletObject::update(float deltaTime, sf::RenderWindow* window)
{
    m_position += m_direction * m_speed * deltaTime;
    m_shape.setPosition(m_position);
}

void BulletObject::draw(sf::RenderWindow* window) const
{
    window->draw(m_shape);
}


sf::FloatRect BulletObject::getBounds() const
{
    return m_shape.getGlobalBounds();
}

void BulletObject::setDirection(const sf::Vector2f& direction)
{
    m_direction = direction;
}

void BulletObject::setTarget(const sf::Vector2f& target)
{
    m_target = target;
}


