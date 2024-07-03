#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class BulletObject : public MovingObject {
public:
    BulletObject(const sf::Vector2f& position);
    void update(float deltatime, sf::RenderWindow* window) override;
    void draw(sf::RenderWindow* window) const override;
    sf::FloatRect getBounds() const ;
    bool toDelete();
    void toDelete(bool);
    void setTarget(const sf::Vector2f& target);

private:
    static bool m_registerit;
    sf::Vector2f m_target;
    sf::Vector2f m_direction;
    float m_speed = 100.f;
    sf::CircleShape m_shape;
    bool m_toDelete;
};