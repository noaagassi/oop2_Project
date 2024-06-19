#include "Objects.h/FactoryObject.h"

//----------------------------------------------------

std::unique_ptr<BaseObject> FactoryObject::create(const Object_ID ObjectName, const sf::Vector2f& position)
{
	auto iterator = getMap().find(ObjectName);

	if (iterator == getMap().end())
	{
		return nullptr;
	}
	return iterator->second();
	
}

//----------------------------------------------------

bool FactoryObject::registerit(const Object_ID objectName, std::unique_ptr<BaseObject>(*f)(const sf::Vector2f&))
{
	getMap().emplace(objectName, f);
	return true;
}

//----------------------------------------------------
myObjects& FactoryObject::getMap()
{
	static myObjects m_map;
	return m_map;
}
