#include "Objects.h/FlashlightObject.h"

FlashlightObject::FlashlightObject()
{
    m_flashlightCone.setPointCount(4);
    m_flashlightCone.setFillColor(sf::Color(128, 128, 128 , 140));
}

//void FlashlightObject::update(const sf::Vector2f& position, const sf::Vector2f& direction)
//{
//    
//    //// חישוב הזווית לפי הכיוון לעכבר
//    //float angle = atan2(direction.y - position.y, direction.x - position.x) * 180 / 3.14159265;
//    //// עדכון מיקום הנקודות של האור של הפנס
//    //m_flashlightCone.setPoint(0, position);
//    //m_flashlightCone.setPoint(1, position + sf::Vector2f(cos(angle * 3.14159265 / 180) * 150, sin(angle * 3.14159265 / 180) * 150));
//    //m_flashlightCone.setPoint(2, position + sf::Vector2f(cos((angle + 20) * 3.14159265 / 180) * 150, sin((angle + 20) * 3.14159265 / 180) * 150));
//    //
//
//    float angle = atan2(direction.y, direction.x) * 180 / 3.14159265;
//    float spreadAngle = 30.0f; // הזווית שתתווסף לכל צד (15 מעלות לכל צד)
//    
//    m_flashlightCone.setPoint(0, position);
//    m_flashlightCone.setPoint(1, position + sf::Vector2f(cos((angle-spreadAngle /2) * 3.14159265 / 180) * 150, sin((angle - spreadAngle / 2) * 3.14159265 / 180) * 150));
//    m_flashlightCone.setPoint(2, position + sf::Vector2f(cos((angle + spreadAngle / 2) * 3.14159265 / 180) * 150, sin((angle + spreadAngle / 2) * 3.14159265 / 180) * 150));
//    m_flashlightCone.setPoint(3, position);
//}

void FlashlightObject::update(const sf::Vector2f& position, const sf::Vector2f& direction)
{
    float angle = atan2(direction.y, direction.x) * 180 / 3.14159265;

    // מגדיר את הפנס עם 4 נקודות ליצירת אלומה רחבה יותר
    m_flashlightCone.setPointCount(4);

    // נקודת ההתחלה היא מיקום השחקן
    m_flashlightCone.setPoint(0, position);

    // מציאת כיוון מרוחק יותר מעבר לעכבר
    sf::Vector2f extendedDirection = direction * 5.0f; // מכפילים את הכיוון כדי להרחיק את הפנס

    // הגדרת נקודות הפנס ליצירת אלומה רחבה יותר
    m_flashlightCone.setPoint(1, position + sf::Vector2f(cos((angle - 15) * 3.14159265 / 180) * 150, sin((angle - 15) * 3.14159265 / 180) * 150));
    m_flashlightCone.setPoint(2, position + extendedDirection);
    m_flashlightCone.setPoint(3, position + sf::Vector2f(cos((angle + 15) * 3.14159265 / 180) * 150, sin((angle + 15) * 3.14159265 / 180) * 150));
}


sf::ConvexShape FlashlightObject::getShape()
{
    return m_flashlightCone;
}

void FlashlightObject::draw(sf::RenderWindow* window) const
{
    window->draw(m_flashlightCone);
}

