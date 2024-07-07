#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class BulletObject : public MovingObject {
public:
    BulletObject(const sf::Vector2f& position);
    sf::FloatRect getBounds() const ;
    virtual void update(float deltatime, sf::RenderWindow* window) =0;
    bool toDelete();
    void toDelete(bool);
    void setTarget(const sf::Vector2f& target) ;


protected:
    static bool m_registerit;
    sf::Vector2f m_target;
    sf::Vector2f m_direction;
    float m_speed;
    bool m_toDelete;
};