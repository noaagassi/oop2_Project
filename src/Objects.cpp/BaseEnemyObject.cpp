#include "Objects.h/BaseEnemyObject.h"
#include <iostream>


//------------------------------------------------------------------------
BaseEnemyObject::BaseEnemyObject(const sf::Vector2f& initPosition, int big, int small, float speed, Object_ID WeaponName, float weaponSpeed, float fireRate)
	:MovingObject(initPosition), m_bigRadius(big), m_smallRadius(small),m_speed(speed)
{


    m_currentWeapon = std::make_unique<EnemyWeaponObject> (WeaponName, weaponSpeed, fireRate);


	m_rangeForMove.setRadius(m_bigRadius);
	m_rangeForShoot.setRadius(m_smallRadius);
    m_rangeForMove.setPosition(m_position);
    m_rangeForMove.setOrigin(m_bigRadius, m_bigRadius);
    m_rangeForShoot.setPosition(m_position);
    m_rangeForShoot.setOrigin(m_smallRadius, m_smallRadius);
    m_rangeForMove.setFillColor(sf::Color::Transparent);
    m_rangeForMove.setOutlineColor(sf::Color::Red);
    m_rangeForMove.setOutlineThickness(3);
    m_rangeForShoot.setFillColor(sf::Color::Transparent);
    m_rangeForShoot.setOutlineColor(sf::Color::Blue);
    m_rangeForShoot.setOutlineThickness(3);

}
//------------------------------------------------------------------------
void BaseEnemyObject::update(float deltatime, sf::RenderWindow* window)
{
	moveAndShoot(deltatime);
    animate(deltatime);
    if (m_poisonBounds.size() >= 2)
    {
        if (m_position.x <= m_poisonBounds[0].x ||
            m_position.x >= m_poisonBounds[1].x ||
            m_position.y <= m_poisonBounds[0].y ||
            m_position.y >= m_poisonBounds[1].y)
        {
            m_position -= 2.0f * (m_direction)*m_speed * deltatime;
        }
    }
    m_rangeForMove.setPosition(m_position);
    m_rangeForShoot.setPosition(m_position);
    m_objectSprite.setPosition(m_position);
    m_currentWeapon->update(deltatime);
}


void BaseEnemyObject::setPoisonBounds(std::vector<sf::Vector2f> poisBounds)
{
	m_poisonBounds = poisBounds;
}
//------------------------------------------------------------------------
void BaseEnemyObject::moveAndShoot(float deltaTime)
{
	if (m_playerPos != sf::Vector2f(0.0, 0.0))      //if player not in bush (in bush- (0,0))
	{   
        
        if (m_rangeForMove.getGlobalBounds().contains(m_playerPos))             //if player is near
        {

            moveSmartandShoot(deltaTime);
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
    

    
}


void BaseEnemyObject::moveSmartandShoot(float deltaTime)
{

    if (m_rangeForShoot.getGlobalBounds().contains(m_playerPos))
    {
        m_currentWeapon->shoot(m_position, m_playerPos);
    }

    sf::Vector2f lastPosition = m_position;


    if (10 <= (m_playerPos.x - m_position.x))
    {
        directionRight();
        // add frames
    }
     if (10 <= (m_position.x - m_playerPos.x)) {
        directionLeft();
    }

     if (10 <= (m_playerPos.y - m_position.y))
    {
        directionDown();
    }
     if (10 <= (m_position.y - m_playerPos.y))
    {
        directionUp();
    }

    m_position += m_direction * m_speed * deltaTime;
}

void BaseEnemyObject:: directionUp()
{
    m_direction.x = 0;
    m_direction.y = -1;
    resetSprite(0);
}

void BaseEnemyObject::directionDown()
{
    m_direction.x = 0;
    m_direction.y = 1;
    resetSprite(2);
}

void BaseEnemyObject::directionRight()
{
    m_direction.x = 1;
    m_direction.y = 0;
    resetSprite(1);
}
void BaseEnemyObject::directionLeft()
{
    m_direction.x = -1;
    m_direction.y = 0;
    resetSprite(3);
}


std::vector<std::unique_ptr<MovingObject>> BaseEnemyObject::retrieveBullets()
{
    return m_currentWeapon->retrieveBullets();

}