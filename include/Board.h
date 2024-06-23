#pragma once
#include "string"
#include <SFML/Graphics.hpp>
#include "Objects.h/BaseObject.h"
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
private:

	//member for reading levels
	int m_levelNum;
	std::ifstream m_file;

	//funcion for reading levels
	void readLevel();
	std::string updateNameLevel(int);

	//members for the object in the level
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<St>> m_staticObjects;

	//function of the object
	void readObject(std::string fileName);
};