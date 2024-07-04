#include "Objects.h/BaseEnemyObject.h"
#include <iostream>



BaseEnemyObject::BaseEnemyObject(const sf::Vector2f& initPosition, int big, int small)
	:MovingObject(initPosition), m_bigRadius(big), m_smallRadius(small)
{
	m_rangeForMove.setRadius(m_bigRadius);
	m_rangeForShoot.setRadius(m_smallRadius);
}

BaseEnemyObject::BaseEnemyObject()
{
}

void BaseEnemyObject::update(float deltatime, sf::RenderWindow* window)
{
	moveAndShoot(deltatime);
}


void BaseEnemyObject::setPoisonBounds(std::vector<sf::Vector2f> poisBounds)
{
	m_poisonBounds = poisBounds;
}

void BaseEnemyObject::moveAndShoot(float deltaTime)
{
    

	if (m_playerPos != sf::Vector2f(0.0, 0.0))      //if player not in bush (in bush- (0,0))
	{
        if (m_rangeForMove.getGlobalBounds().contains(m_playerPos))             //if player is 
        {
            moveSmart(deltaTime);
        }
        else                                            //if not bush and not near
        {
            moveRandom(deltaTime);
        }
	}
    else                                            //if in bush
    {
        moveRandom(deltaTime);
    }
	
}

void BaseEnemyObject::setPlayerPos(sf::Vector2f playerPos)
{
	m_playerPos = playerPos;
}

void BaseEnemyObject::moveRandom(float deltaTime)
{
    int direction=-1;
    int switchD = rand() % 30;
    if (switchD == 15)
    {
        direction = rand() % 4;
    }

    switch (direction) {
    case 0:
        directionUp();
        break;
    case 1:
        directionRight();
        break;
    case 2:
        directionDown();
        break;
    case 3:
        directionLeft();
        break;

    default:
        break;
    }

    m_position += m_direction * m_speed * deltaTime;
    m_objectSprite.setPosition(m_position);
    
}


void BaseEnemyObject::moveSmart(float deltaTime)
{
}






void BaseEnemyObject:: directionUp()
{
    m_direction.x = 0;
    m_direction.y = -1;
}

void BaseEnemyObject::directionDown()
{
    m_direction.x = 0;
    m_direction.y = 1;
}

void BaseEnemyObject::directionRight()
{
    m_direction.x = 1;
    m_direction.y = 0;
}
void BaseEnemyObject::directionLeft()
{
    m_direction.x = -1;
    m_direction.y = 0;
}