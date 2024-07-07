#pragma once
#include "string"
#include <SFML/Graphics.hpp>
#include "Objects.h/BaseObject.h"
#include "Objects.h/StaticObject.h"
#include "Objects.h/MovingObject.h"
#include "Objects.h/PlayerObject.h"
#include "Objects.h/PortalObject.h"
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>
#include <fstream>
#include "Utilities.h"
#include "Objects.h/FactoryObject.h"
#include "Objects.h/CloudPoisonObject.h"
#include "Objects.h/BaseEnemyObject.h"

class Board
{
public:
	Board();
	~Board();

	//void handleInput();
	void update(float deltatime, sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);
	void checkCollisions();

	sf::Vector2f getPlayrLocation() const;
	sf::FloatRect getPlayerBounds() const;
	PlayerObject* getPlayer() const;

	bool isPlayerInPoison(sf::Vector2f playerPosition, std::vector<sf::Vector2f> poisonPoints);
	
	void handleMousePressed(sf::Event event);
	void handleKeyPress(sf::Keyboard::Key key); 
	bool loose();

	void addBullets(std::vector<std::unique_ptr<MovingObject>> bullets);

	void addSingleBullet(std::unique_ptr<MovingObject> bullet);

private:
	
	//member for reading levels
	int m_levelNum;
	std::ifstream m_file;

	//funcion for reading levels
	void readLevel();
	std::string updateNameLevel(int);

	//members for the object in the level
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	CloudPoisonObject m_cloud;


	void readMap(std::string fileName);

	int m_numberOfBushes;
	int m_checkNumberOfBushes;


	bool m_isGameOver;
};