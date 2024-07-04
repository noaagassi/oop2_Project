#pragma once
#include "MovingObject.h"

class BaseEnemyObject : public MovingObject
{
public:
    BaseEnemyObject(const sf::Vector2f& initPosition, int big ,int small);
    BaseEnemyObject();
    void update(float deltatime, sf::RenderWindow* window) override;
    void moveAndShoot(float deltaTime);
    void setPlayerPos(sf::Vector2f playerPos);
    void setPoisonBounds(std::vector<sf::Vector2f> poisBounds);

    void directionUp(float deltaTime);
    void directionDown(float deltaTime);
    void directionRight(float deltaTime);
    void directionLeft(float deltaTime);
    void moveRandom(float deltaTime);
    void moveSmart(float deltaTime);
private:
    sf::Vector2f m_playerPos;
    float m_speed;

    int m_bigRadius;
    int m_smallRadius;
    sf::CircleShape m_rangeForMove;
    sf::CircleShape m_rangeForShoot;

    std::vector<sf::Vector2f> m_poisonBounds;
};