#include "Objects.h/FlashlightObject.h"

FlashlightObject::FlashlightObject()
{
    m_flashlightCone.setPointCount(4);
    m_flashlightCone.setFillColor(sf::Color(128, 128, 128 , 140));
}

void FlashlightObject::update(const sf::Vector2f& playerPos, const sf::Vector2f& direction)
{
   
    
    sf::Vector2f spriteCenter = playerPos + sf::Vector2f(15, 14);//(PLAYER_WIDTH / 2.0f, PLAYER_HEIGHT / 2.0f);

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    float minLength = 0.001f;
    sf::Vector2f adjustedDirection = direction;
    if (length < minLength) {
        adjustedDirection *= (minLength / length); // Escalar el vector para tener una longitud mínima
    }

    // Calcular el ángulo en grados
    float angle = std::atan2(adjustedDirection.y, adjustedDirection.x) * 180 / 3.14159265;
    float spreadAngle = 30.0f;

   
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

