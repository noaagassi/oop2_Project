
#include "Objects.h/BallsWeaponObject.h"
#include "Objects.h/BallObject.h"
#include "SoundsHandler.h"

BallsWeaponObject::BallsWeaponObject()
    :PlayerWeaponObject()
{
    m_numOfBalls = 4;
    m_fireRate = 1.0f;
    
}


void BallsWeaponObject::shoot(FlashlightObject flashlight)
{
    sf::Vector2f start = flashlight.getShape().getPoint(0);
    sf::Vector2f vertex1 = flashlight.getShape().getPoint(1);
    sf::Vector2f vertex2 = flashlight.getShape().getPoint(2);

    for (int i = 0; i < m_numOfBalls; ++i) {
        float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        sf::Vector2f randomPoint = vertex1 + t * (vertex2 - vertex1);
        auto bullet = std::make_unique<BallObject>(start);
        bullet->setTarget(randomPoint);
        m_bullets.push_back(std::move(bullet));
        SoundsHandler::getInstance().playSound(Sound_Id::BALL_SHOOT);
    }
}



