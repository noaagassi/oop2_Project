#include "FactoryObject.h"


std::unique_ptr<BaseObject> FactoryObject::create(const sf::Texture& texture, const sf::Vector2f& position)
{

	return std::unique_ptr<BaseObject>();
}

bool FactoryObject::regesterit(const sf::Texture& texture, const sf::Vector2f& position, std::unique_ptr<BaseObject>(*)())
{
	getVec().push_back(texture, position);
	return false;
}

myObjects& FactoryObject::getVec()
{
	static myObjects m_objects;

	return m_objects;
}
