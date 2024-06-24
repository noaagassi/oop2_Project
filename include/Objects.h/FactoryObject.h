#pragma once
#include "BaseObject.h"
#include "TextureHandler.h"
#include <SFML/System/Vector2.hpp>

class Playerobject;

typedef std::map<Object_ID, std::unique_ptr<BaseObject>(*)(const sf::Vector2f&)> myObjects;

class FactoryObject
{
public:
	FactoryObject() {};
	static std::unique_ptr<BaseObject> create(const Object_ID objectName, const sf::Vector2f& position);
	//static std::unique_ptr<MovingObject> create(const Object_ID objectName, const sf::Vector2f& position);
	//static std::unique_ptr<StaticObject> create(const Object_ID objectName, const sf::Vector2f& position);
	static bool registerit(const Object_ID objectName, std::unique_ptr<BaseObject>(*func)(const sf::Vector2f&));

private:
	static myObjects& getMap()
	{
		static myObjects m_map;
		return m_map;
	}
};