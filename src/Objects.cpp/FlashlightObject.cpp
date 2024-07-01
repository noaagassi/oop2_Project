#include "Objects.h/FlashlightObject.h"

FlashlightObject::FlashlightObject()
{
    m_flashlightCone.setPointCount(4);
    m_flashlightCone.setFillColor(sf::Color(128, 128, 128 , 140));
}

void FlashlightObject::update(const sf::Vector2f& position, const sf::Vector2f& direction)
{
   
    // חישוב מרכז הספרייט
    sf::Vector2f spriteCenter = position + sf::Vector2f(15, 28);//(PLAYER_WIDTH / 2.0f, PLAYER_HEIGHT / 2.0f);

    // חישוב זווית הפנס
    float angle = atan2(direction.y, direction.x) * 180 / 3.14159265;
    float spreadAngle = 30.0f; // הזווית שתתווסף לכל צד (15 מעלות לכל צד)

    // קביעת נקודות הפנס עם מרכז הספרייט כנקודה 0
    m_flashlightCone.setPoint(0, spriteCenter);
    m_flashlightCone.setPoint(1, spriteCenter + sf::Vector2f(cos((angle - spreadAngle / 2) * 3.14159265 / 180) * 150, sin((angle - spreadAngle / 2) * 3.14159265 / 180) * 100));
    m_flashlightCone.setPoint(2, spriteCenter + sf::Vector2f(cos((angle + spreadAngle / 2) * 3.14159265 / 180) * 150, sin((angle + spreadAngle / 2) * 3.14159265 / 180) * 100));
    m_flashlightCone.setPoint(3, spriteCenter);

}



sf::ConvexShape FlashlightObject::getShape()
{
    return m_flashlightCone;
}

void FlashlightObject::draw(sf::RenderWindow* window) const
{
    window->draw(m_flashlightCone);
}

