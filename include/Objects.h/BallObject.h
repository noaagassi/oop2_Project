#pragma once
#include <SFML/Graphics.hpp>
#include "BulletObject.h"

class BallObject : public BulletObject {
public:
    BallObject(const sf::Vector2f& position);
    void update(float deltatime, sf::RenderWindow* window) override;
    //void draw(sf::RenderWindow* window) const override;
    
    //void setTarget(const sf::Vector2f& target) ;

private:
    static bool m_registerit;
    //sf::Vector2f m_target;
    //sf::Vector2f m_direction;
    //float m_speed = 100.f;
   // bool m_toDelete;
};