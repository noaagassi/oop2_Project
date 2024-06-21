#include <SFML/Graphics.hpp>
#include <cmath>

class FlashlightObject {
public:
    FlashlightObject();

    void update(const sf::Vector2f& position, const sf::Vector2f& direction);

    void draw(sf::RenderWindow& window);

private:
    sf::ConvexShape m_flashlightCone;
};