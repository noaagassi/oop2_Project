#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class BulletObject : public MovingObject {
public:
    BulletObject(const sf::Vector2f& position, const sf::Vector2f& direction);
    void update(float deltaTime) ;
    void draw(sf::RenderWindow* window) ;
    sf::FloatRect getBounds() const ;
    

private:
    static bool m_registerit;
    sf::Vector2f m_position;
    sf::Vector2f m_direction;
    float m_speed = 300.f;
    sf::CircleShape m_shape;
};