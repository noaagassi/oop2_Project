#pragma once
#include <SFML/Graphics.hpp>
#include "BulletObject.h"

class BallObject : public BulletObject {
public:
    BallObject(const sf::Vector2f& position);
    void update(float deltatime, sf::RenderWindow* window) override;
    

private:
    static bool m_registerit;
};