#include "Objects.h/BaseEnemyObject.h"




BaseEnemyObject::BaseEnemyObject(const sf::Vector2f& initPosition)
	:MovingObject(initPosition)
{
}

BaseEnemyObject::BaseEnemyObject()
{
}

void BaseEnemyObject::update(float deltatime, sf::RenderWindow* window)
{

}