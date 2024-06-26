#pragma once
#include "string"
#include <SFML/Graphics.hpp>
#include "Objects.h/BaseObject.h"
#include "Objects.h/StaticObject.h"
#include "Objects.h/PlayerObject.h"
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include "Utilities.h"

class Board
{
public:
	Board();
	~Board();
	
	void update(sf::Time elapseTime);	
	void handleKeyPress(sf::Keyboard::Key key);
	void draw(sf::RenderWindow*);
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
	void readObject(std::string fileName);
};