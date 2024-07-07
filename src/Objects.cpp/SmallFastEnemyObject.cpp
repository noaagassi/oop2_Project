
#pragma once
#include "Objects.h/SmallFastEnemyObject.h"
#include "Utilities.h"


//---------------------------------------------------------------------------------------
bool SmallFastEnemyObject::m_registerit = FactoryObject::registerit(ENEMY_2_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<SmallFastEnemyObject>(pos); });
//---------------------------------------------------------------------------------------
SmallFastEnemyObject::SmallFastEnemyObject(const sf::Vector2f& initPosition)
    :BaseEnemyObject(initPosition, 130, 80,15), m_spriteIndex(0)
{
    setObjTexture(ENEMY_1_OBJ);
    setTheScale(PLAYER_WIDTH, PLAYER_HEIGHT);
    m_weapon = std::make_unique<EnemyWeaponObject>(REGULAR_LASER_WEAPON_1_OBJ,220.0,4.0);
  
    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    rightFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
    downFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
    upFrames = { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };

    currentFrames = &defaultFrames;
    m_objectSprite.setTextureRect((*currentFrames)[0]);

    m_clock.restart();
}
//---------------------------------------------------------------------------------------
void SmallFastEnemyObject::draw(sf::RenderWindow* window) const
{
    BaseObject::draw(window);
    window->draw(m_rangeForMove);
    window->draw(m_rangeForShoot);
    m_lives.draw(window);
}

void SmallFastEnemyObject::resetSprite(int num)
{
    if (num == 0)
    {
        currentFrames = &upFrames;
    }
    else if (num == 1)
    {
        currentFrames = &rightFrames;
    }
    else if (num == 2)
    {
        currentFrames = &downFrames;
    }
    else if (num == 3)
    {
        currentFrames = &leftFrames;
    }
}
//---------------------------------------------------------------------------------------
sf::IntRect SmallFastEnemyObject::getFrame(int row, int col)
{
    return sf::IntRect(col * SMALL_ENEMY_SPRITE_WIDTH, row * SMALL_ENEMY_SPRITE_HEIGHT, SMALL_ENEMY_SPRITE_WIDTH, SMALL_ENEMY_SPRITE_HEIGHT);
}
//---------------------------------------------------------------------------------------
void SmallFastEnemyObject::animate(float deltaTime)
{
    if (m_clock.getElapsedTime().asSeconds() > 0.1f)
    {
        m_spriteIndex = (m_spriteIndex + 1) % currentFrames->size();
        m_objectSprite.setTextureRect((*currentFrames)[m_spriteIndex]);
        m_clock.restart();
    }
}