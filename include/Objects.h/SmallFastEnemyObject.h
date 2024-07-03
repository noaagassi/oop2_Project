#pragma once
#include "BaseEnemyObject.h"

class SmallFastEnemyObject : public BaseEnemyObject
{
public:
    SmallFastEnemyObject(const sf::Vector2f& initPosition);

    void move(float deltaTime) override;
    virtual void handleInput(sf::RenderWindow);
private:
    
    
    sf::IntRect getFrame(int row, int col);
    
    
    static bool m_registerit;
};