#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class BulletObject : public MovingObject {
public:
    BulletObject(const sf::Vector2f& position);
    void update(float deltatime, sf::RenderWindow* window) override;
    void draw(sf::RenderWindow* window) const override;
    sf::FloatRect getBounds() const ;
    void setDirection(const sf::Vector2f& direction);
    void setTarget(const sf::Vector2f& target);

private:
    static bool m_registerit;
    sf::Vector2f m_position;
    sf::Vector2f m_direction;
    sf::Vector2f m_target;
    float m_speed = 300.f;
    sf::CircleShape m_shape;
};