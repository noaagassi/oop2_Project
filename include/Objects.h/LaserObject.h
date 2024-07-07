#pragma once
#include <SFML/Graphics.hpp>
#include "BulletObject.h"


class LaserObject : public BulletObject
{
public:
	LaserObject(const sf::Vector2f& position);
	void update(float deltaTime, sf::RenderWindow* window);
private:
	static bool m_registerit;
};
