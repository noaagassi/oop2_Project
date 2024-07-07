#include "Objects.h/BigSlowEnemyObject.h"


//----------------------------------------------------------------------------
bool BigSlowEnemyObject::m_registerit = FactoryObject::registerit(ENEMY_1_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BigSlowEnemyObject>(pos); });
//------------------------------------------------------
BigSlowEnemyObject::BigSlowEnemyObject(const sf::Vector2f& initPosition)
    :BaseEnemyObject(initPosition,150,150,6)
{

    setObjTexture(ENEMY_2_OBJ);
    setTheScale(PLAYER_WIDTH+0.2, PLAYER_HEIGHT+0.2);
    m_weapon = std::make_unique<EnemyWeaponObject>(MASSIVE_LASER_WEAPON_3_OBJ, 80.0, 15.0);

    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    upFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
     downFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
     rightFrames= { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };

    currentFrames = &defaultFrames;
    m_objectSprite.setTextureRect((*currentFrames)[0]);
    m_clock.restart();
}
//------------------------------------------------------
void BigSlowEnemyObject::animate(float deltaTime)
{
    if (m_clock.getElapsedTime().asSeconds() > 0.1f)
    {
        m_spriteIndex = (m_spriteIndex + 1) % currentFrames->size();
        m_objectSprite.setTextureRect((*currentFrames)[m_spriteIndex]);
        m_clock.restart();
    }
}
//------------------------------------------------------
void BigSlowEnemyObject::resetSprite(int num)
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
//------------------------------------------------------
sf::IntRect BigSlowEnemyObject::getFrame(int row, int col)
{
    return sf::IntRect(col * BIG_ENEMY_SPRITE_WIDTH, row * BIG_ENEMY_SPRITE_HEIGHT, BIG_ENEMY_SPRITE_WIDTH, BIG_ENEMY_SPRITE_HEIGHT);
}
//-----------------------------------------------------
//------------------------------------------------------
void BigSlowEnemyObject::draw(sf::RenderWindow* window) const
{
    BaseObject::draw(window);
    window->draw(m_rangeForMove);
    window->draw(m_rangeForShoot);
    m_lives.draw(window);

}
//------------------------------------------------------
