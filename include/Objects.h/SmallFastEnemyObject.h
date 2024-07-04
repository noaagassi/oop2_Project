#pragma once
#include "BaseEnemyObject.h"

class SmallFastEnemyObject : public BaseEnemyObject
{
public:
    SmallFastEnemyObject(const sf::Vector2f& initPosition);
    void draw(sf::RenderWindow* window) const override;

private:
    
    
    sf::IntRect getFrame(int row, int col);
    
    
    static bool m_registerit;
};