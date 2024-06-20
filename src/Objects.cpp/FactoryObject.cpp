#include "Objects.h/FactoryObject.h"
//----------------------------------------------------

std::unique_ptr<BaseObject> FactoryObject::create(const Object_ID ObjectName, const sf::Vector2f& position)
{
	auto mapIterator = getMap().find(ObjectName);

	if (mapIterator == getMap().end())
	{
		return nullptr;
	}
	return mapIterator->second(position);

}
bool FactoryObject::registerit(const Object_ID objectName, std::unique_ptr<BaseObject>(*func)(const sf::Vector2f&))
