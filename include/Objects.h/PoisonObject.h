#pragma once

#include "FactoryObject.h"

class PoisonObject : public BaseObject
{
public:
	PoisonObject(const sf::Vector2f& initPosition);
	void draw(sf::RenderWindow*);
private:
};