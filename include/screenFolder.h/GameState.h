#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Utilities.h"
class GameState {
public:
	GameState();

	virtual void draw()=0;
	virtual void update()=0;

	virtual GameState* isStateChanged()=0;



private:
	
	
};