#pragma once
#include <SFML/Graphics.hpp>
#include "BulletObject.h"


class LaserObject : public BulletObject
{
public:
	LaserObject(const sf::Vector2f& position);
	void update(float deltaTime, sf::RenderWindow* window);
	void setBulletMembers(Object_ID m_name, float m_speed, float m_fireRate);
private:
	static bool m_registerit;
	Object_ID m_name;
};
