#pragma once
#include "BaseEnemyObject.h"

class SmallFastEnemyObject : public BaseEnemyObject
{
public:
    SmallFastEnemyObject(const sf::Vector2f& initPosition);
    void draw(sf::RenderWindow* window) const override;
    void update(float deltaTime, sf::RenderWindow* window);
    void animate(float deltaTime);

private:
    
    void resetSprite(int) override;
    sf::IntRect getFrame(int row, int col);
    
    static bool m_registerit;
    int m_spriteIndex;
    sf::Clock m_clock;
};