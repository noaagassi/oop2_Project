#pragma once
#include "string"
#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "PlayerObject.h"
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
	void readFile(std::string&);

	//members for the object in the level
	std::vector<std::unique_ptr<BaseObject>> m_movingObjects;
	std::vector<std::unique_ptr<BaseObject>> m_staticObjects;

	//function of the object
	void readObject();
};