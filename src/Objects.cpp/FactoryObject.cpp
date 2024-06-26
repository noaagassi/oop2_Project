#include "Objects.h/FactoryObject.h"
#include "Objects.h/PlayerObject.h"
#include "Objects.h/StaticObject.h"
#include"Objects.h/MovingObject.h"
//----------------------------------------------------
std::unique_ptr<MovingObject> FactoryObject::createMoving(const Object_ID ObjectName, const sf::Vector2f& position)
{
	auto mapIterator = getMap().find(ObjectName);

	if (mapIterator == getMap().end())
	{
		return nullptr;
	}	
	return std::unique_ptr<MovingObject>(dynamic_cast<MovingObject*>(mapIterator->second(position).release()));
}
//----------------------------------------------------
std::unique_ptr<StaticObject> FactoryObject::createStatic(const Object_ID ObjectName, const sf::Vector2f& position)
{
	auto mapIterator = getMap().find(ObjectName);

	if (mapIterator == getMap().end())
	{
		return nullptr;
	}
	return std::unique_ptr<StaticObject>(dynamic_cast<StaticObject*>(mapIterator->second(position).release()));
}
//----------------------------------------------------
bool FactoryObject::registerit(const Object_ID objectName, std::unique_ptr<BaseObject>(*func)(const sf::Vector2f&))
{
	getMap().emplace(objectName, func);
	return true;
}

