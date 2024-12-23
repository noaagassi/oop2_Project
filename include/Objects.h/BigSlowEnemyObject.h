#pragma once
#include "BaseEnemyObject.h"
#include "PlayerLives.h"

class BigSlowEnemyObject : public BaseEnemyObject
{
public:
    BigSlowEnemyObject(const sf::Vector2f& initPosition);
    void animate(float deltaTime) override;
    void draw(sf::RenderWindow*) const override;
private:
    void resetSprite(int num) override;
    sf::IntRect getFrame(int row, int col);
    static bool m_registerit;
    int m_spriteIndex;
    sf::Clock m_clock;

};

