#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "BaseObject.h"
#include "FactoryObject.h"
#include "Utilities.h"

class MovingObject : public BaseObject
{
public:
    MovingObject(const sf::Vector2f& initPosition);
    MovingObject();


protected:

};