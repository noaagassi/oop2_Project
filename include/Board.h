#pragma once
#include "string"
#include <SFML/Graphics.hpp>
#include "Objects.h/BaseObject.h"
#include "Objects.h/StaticObject.h"
#include "Objects.h/MovingObject.h"
#include "Objects.h/PlayerObject.h"
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>
#include <fstream>
#include "Utilities.h"
#include "Objects.h/FactoryObject.h"

class Board
{
public:
	Board();
	~Board();

	void handleInput();
	void update(float deltatime, sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);
	void checkCollisions();

	sf::Vector2f getPlayrLocation();
	
	void handleMousePressed(sf::Event event);
	void handleKeyPress(sf::Keyboard::Key key); 
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

	//function of the object
	void readMap(std::string fileName);


	//std::unordered_map <sf::Color, COLOR_OF_OBJECT> m_colorsCodes;
};