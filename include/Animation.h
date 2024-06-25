#pragma once
#include "Direction.h"
#include "AnimationData.h"

#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite);
	~Animation();

	void direction(Direction dir);

	void update(sf::Time delta);

private:
	void update();
	int m_numOfRect;
	const AnimationData& m_data;
	sf::Time m_elapsed = {};
	Direction m_dir;
	sf::Sprite& m_sprite;
};