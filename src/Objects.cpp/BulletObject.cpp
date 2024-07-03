#include "Objects.h/BulletObject.h"
#include <iostream>

bool BulletObject::m_registerit = FactoryObject::registerit(BULLET_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BulletObject>(pos); });


BulletObject::BulletObject(const sf::Vector2f& position)
    : MovingObject(position),m_toDelete(false)
{
        m_shape.setRadius(2.f); 
        m_shape.setPosition(m_position);
        m_shape.setFillColor(sf::Color::Red);

        
}

    
void BulletObject::update(float deltaTime, sf::RenderWindow* window)
{
    m_position += m_direction * m_speed * deltaTime;
    m_shape.setPosition(m_position);


    if( (m_target.x-m_position.x) <= 5
        && (m_target.x - m_position.x) >= -5
        && (m_target.y - m_position.y) <= 5
        && (m_target.y - m_position.y) >= -5 )
    {
        m_toDelete = true;
    }

}

void BulletObject::draw(sf::RenderWindow* window) const
{
    window->draw(m_shape);
}


sf::FloatRect BulletObject::getBounds() const
{
    return m_shape.getGlobalBounds();
}

bool BulletObject::toDelete()
{
    return m_toDelete;
}

void BulletObject::toDelete(bool x)
{
    m_toDelete = x;
}


void BulletObject::setTarget(const sf::Vector2f& target)
{
    m_target = target;

    sf::Vector2f direction = m_target - m_position;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        m_direction = direction / length;
    }
}


