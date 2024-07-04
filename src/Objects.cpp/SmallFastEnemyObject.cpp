
#pragma once
#include "Objects.h/SmallFastEnemyObject.h"
#include "Utilities.h"



bool SmallFastEnemyObject::m_registerit = FactoryObject::registerit(ENEMY_2_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<SmallFastEnemyObject>(pos); });

SmallFastEnemyObject::SmallFastEnemyObject(const sf::Vector2f& initPosition)
    :BaseEnemyObject(initPosition,50,25)
{
    m_speed = 50.0;
    setObjTexture(ENEMY_1_OBJ);
    setTheScale(PLAYER_WIDTH, PLAYER_HEIGHT);
    


    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    rightFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
    downFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
    upFrames = { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };

    currentFrames = &defaultFrames;
    m_objectSprite.setTextureRect((*currentFrames)[0]);


}

void SmallFastEnemyObject::draw(sf::RenderWindow* window) const
{
    BaseObject::draw(window);
}



sf::IntRect SmallFastEnemyObject::getFrame(int row, int col)
{
    return sf::IntRect(col * PLAYER_SPRITE_WIDTH, row * PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
}

