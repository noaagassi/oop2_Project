#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Utilities.h"
class GameState {
public:
	GameState();
	virtual ~GameState();
	virtual void draw()=0;
	virtual void update()=0;

	virtual std::shared_ptr <GameState> isStateChanged()=0;
	void initMap(std::shared_ptr<GameState> state_ptr, StateOptions state_name);


protected:
	std::unordered_map<StateOptions, std::shared_ptr<GameState>> m_states;
	
};