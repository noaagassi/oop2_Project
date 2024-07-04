#pragma once
#include "MovingObject.h"
//-------------------------------------------------------
class BaseEnemyObject : public MovingObject
{
public:
    BaseEnemyObject(const sf::Vector2f& initPosition, int big ,int small,float);
    BaseEnemyObject();
    void update(float deltatime, sf::RenderWindow* window) override;
    void moveAndShoot(float deltaTime);
    void setPlayerPos(sf::Vector2f playerPos);
    void setPoisonBounds(std::vector<sf::Vector2f> poisBounds);

    void directionUp();
    void directionDown();
    void directionRight();
    void directionLeft();
    void moveRandom(float deltaTime);
    void moveSmart(float deltaTime);

protected:
    virtual void resetSprite(int) =0;
    sf::Vector2f m_playerPos;
    float m_speed;
    sf::Vector2f m_direction;
    int m_bigRadius;
    int m_smallRadius;
    sf::CircleShape m_rangeForMove;
    sf::CircleShape m_rangeForShoot;

    std::vector<sf::Vector2f> m_poisonBounds;
};