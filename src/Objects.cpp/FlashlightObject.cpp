#include "Objects.h/FlashlightObject.h"

FlashlightObject::FlashlightObject()
{
    m_flashlightCone.setPointCount(4);
    m_flashlightCone.setFillColor(sf::Color(128, 128, 128 , 140));
}

void FlashlightObject::update(const sf::Vector2f& position, const sf::Vector2f& direction)
{

    float angle = atan2(direction.y, direction.x) * 180 / 3.14159265;
    float spreadAngle = 30.0f; // הזווית שתתווסף לכל צד (15 מעלות לכל צד)
    
    m_flashlightCone.setPoint(0, position);
    m_flashlightCone.setPoint(1, position + sf::Vector2f(cos((angle-spreadAngle /2) * 3.14159265 / 180) * 150, sin((angle - spreadAngle / 2) * 3.14159265 / 180) * 150));
    m_flashlightCone.setPoint(2, position + sf::Vector2f(cos((angle + spreadAngle / 2) * 3.14159265 / 180) * 150, sin((angle + spreadAngle / 2) * 3.14159265 / 180) * 150));
    m_flashlightCone.setPoint(3, position);
}


sf::ConvexShape FlashlightObject::getShape()
{
    return m_flashlightCone;
}

void FlashlightObject::draw(sf::RenderWindow* window) const
{
    window->draw(m_flashlightCone);
}

