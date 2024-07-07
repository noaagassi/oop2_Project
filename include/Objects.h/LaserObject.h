#pragma once
#include <SFML/Graphics.hpp>
#include "BulletObject.h"


class LaserObject : public BulletObject
{
public:
	LaserObject(const sf::Vector2f& position);
	void update(float deltaTime, sf::RenderWindow* window);
	void setMembers(Object_ID WeaponName, float weaponSpeed, float fireRate);
	
private:
	static bool m_registerit;
};
