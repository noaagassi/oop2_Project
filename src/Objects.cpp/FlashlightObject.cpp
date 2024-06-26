#include "Objects.h/FlashlightObject.h"

FlashlightObject::FlashlightObject()
{
    m_flashlightCone.setPointCount(3);
    m_flashlightCone.setFillColor(sf::Color(128, 0, 128, 150));
}

void FlashlightObject::update(const sf::Vector2f& position, const sf::Vector2f& direction)
{
    float angle = atan2(direction.y, direction.x) * 180 / 3.14159265;

    m_flashlightCone.setPoint(0, position);
    m_flashlightCone.setPoint(1, position + sf::Vector2f(cos(angle * 3.14159265 / 180) * 150, sin(angle * 3.14159265 / 180) * 150));
    m_flashlightCone.setPoint(2, position + sf::Vector2f(cos((angle + 20) * 3.14159265 / 180) * 150, sin((angle + 20) * 3.14159265 / 180) * 150));
}

sf::ConvexShape FlashlightObject::getShape()
{
    return m_flashlightCone;
}

void FlashlightObject::draw(sf::RenderWindow* window)
{
    window->draw(m_flashlightCone);
}

