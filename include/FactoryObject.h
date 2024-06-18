#pragma once
#include "BaseObject.h"

typedef std::vector<std::unique_ptr<BaseObject>> myObjects;

class FactoryObject
{
public:
	static std::unique_ptr<BaseObject> create(const sf::Texture& texture, const sf::Vector2f& position);
	static bool regesterit(const sf::Texture& texture, const sf::Vector2f& position, std::unique_ptr<BaseObject>(*)());
private:
	static myObjects& getVec();
};