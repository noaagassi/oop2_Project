#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
	Animation(/*sf::Texture* texture*/sf::Sprite* sprite, sf::Vector2u imageCount, float switchTime);
	~Animation();
	
	void update(int row, float deltaTime);
	sf::IntRect uvrect;
private:

	//member about the image
	sf::Vector2u m_imageCount;
	sf::Vector2u m_currentImage;

	//member about the speed
	float m_totalTime;
	float m_switchTime;

	//

	//member
};























/*
#include "Direction.h"
#include "AnimationData.h"
#include <SFML/Graphics.hpp>

class Animation
{
public:
	#pragma once
#include "Direction.h"
#include "AnimationData.h"
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation()
	Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite);
	Animation& operator=(const Animation& other);
	~Animation() = default;

	void direction(Direction dir);

	void update(sf::Time delta);

private:
	void update();
	int m_numOfRect;
	const AnimationData* m_data = nullptr;
	sf::Time m_elapsed = {};
	Direction m_dir;
	sf::Sprite* m_sprite = nullptr;
};
	Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite);
	Animation& operator=(const Animation& other);
	~Animation() = default;

	void direction(Direction dir);

	void update(sf::Time delta);

private:
	void update();
	int m_numOfRect;
	const AnimationData* m_data = nullptr;
	sf::Time m_elapsed = {};
	Direction m_dir;
	sf::Sprite* m_sprite = nullptr;
};*/