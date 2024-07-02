#include "Objects.h/MovingObject.h"

//------------------------------------------------
////constant ans enum
//const int PLAYER_SPRITE_WIDTH = 64;
//const int PLAYER_SPRITE_HEIGHT = 96;
//const int PLAYER_SPRITES_PER_ROW = 4;
//const int PLAYER_SPRITES_PER_COLUMN = 4;
//------------------------------------------------

MovingObject::MovingObject(const sf::Vector2f& initPosition)
	:BaseObject(initPosition)
{ }

MovingObject::MovingObject()
{
}

void MovingObject::goLeft()
{
	m_direction.x -= 1.f;
	currentFrames = &leftFrames;
	m_isMoving = true;
}

void MovingObject::goRight()
{
	m_direction.x += 1.f;
	currentFrames = &rightFrames;
	m_isMoving = true;
}

void MovingObject::goUp()
{
	m_direction.y -= 1.f;
	currentFrames = &upFrames;
	m_isMoving = true;
}

void MovingObject::goDown()
{
	m_direction.y += 1.f;
	currentFrames = &downFrames;
	m_isMoving = true;
}
