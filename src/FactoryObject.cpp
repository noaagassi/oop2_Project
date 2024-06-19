#include "FactoryObject.h"
//----------------------------------------------------

std::unique_ptr<BaseObject> FactoryObject::create(const Object_ID ObjectName, const sf::Vector2f& position)
{
	auto iterator = getMap().find(ObjectName);

	if (iterator == getMap().end())
	{
		return nullptr;
	}

	return iterator->second(position);
}

//----------------------------------------------------

bool FactoryObject::regesterit(const Object_ID objectName, std::unique_ptr<BaseObject>(*f)())
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
