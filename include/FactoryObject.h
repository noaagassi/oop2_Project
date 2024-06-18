#pragma once
#include "BaseObject.h"
#include "TextureHandler.h"

typedef std::map<Object_ID, std::unique_ptr<BaseObject>(*)()> myObjects;

class FactoryObject
{
public:
	static std::unique_ptr<BaseObject> create(const Object_ID, const sf::Vector2f& position);
	static bool regesterit(const Object_ID, std::unique_ptr<BaseObject>(*f)(sf::Vector2f&));
private:
	static myObjects& getMap();
};