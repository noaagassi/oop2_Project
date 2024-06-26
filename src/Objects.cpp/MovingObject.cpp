#include "Objects.h/MovingObject.h"

//------------------------------------------------
//constant ans enum
const int PLAYER_SPRITE_WIDTH = 64;
const int PLAYER_SPRITE_HEIGHT = 96;
const int PLAYER_SPRITES_PER_ROW = 4;
const int PLAYER_SPRITES_PER_COLUMN = 4;
//------------------------------------------------

MovingObject::MovingObject(const sf::Vector2f& initPosition)
	:BaseObject(initPosition)
{ }

MovingObject::MovingObject()
{
}