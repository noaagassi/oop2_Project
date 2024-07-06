#pragma once
#include "MovingObject.h"
#include "EnemyWeaponObject.h"
#include "CharacterObject.h"
//-------------------------------------------------------
class BaseEnemyObject : public CharacterObject
{
public:
    BaseEnemyObject(const sf::Vector2f& initPosition, int big ,int small,float, Object_ID WeaponName, float weaponSpeed, float fireRate);

    void update(float deltatime, sf::RenderWindow* window) override;
    void moveAndShoot(float deltaTime);
    void setPlayerPos(sf::Vector2f playerPos);
    void setPoisonBounds(std::vector<sf::Vector2f> poisBounds);

    void directionUp();
    void directionDown();
    void directionRight();
    void directionLeft();

    std::vector<std::unique_ptr<MovingObject>> retrieveBullets();

    void moveRandom(float deltaTime);
    void moveSmartandShoot(float deltaTime);
    void draw(sf::RenderWindow* window) const override;

    virtual void animate(float deltTime)=0;

protected:
    virtual void resetSprite(int) =0;
    sf::Vector2f m_playerPos;
    float m_speed;
    sf::Vector2f m_direction;
    int m_bigRadius;
    int m_smallRadius;
    sf::CircleShape m_rangeForMove;
    sf::CircleShape m_rangeForShoot;
    std::unique_ptr<EnemyWeaponObject> m_currentWeapon;
    bool m_isRandomMoving;
    sf::Clock m_randomMoveTimer;

    std::vector<sf::Vector2f> m_poisonBounds;

    float m_shootCooldown = 5.0f; 
    float m_timeSinceLastShot = 0.0f;
};