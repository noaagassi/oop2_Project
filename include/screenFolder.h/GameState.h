#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Utilities.h"
#include "TextureHandler.h"


class GameState {
public:
	GameState(sf::RenderWindow* window);
	void setScale(Object_ID name);
	void setObjTexture(Object_ID name);

	virtual ~GameState();
	virtual void draw()=0;
	virtual void update()=0;

	virtual std::shared_ptr <GameState> isStateChanged(sf::Event event)=0;
	void initMap(std::shared_ptr<GameState> state_ptr, StateOptions state_name);


protected:
	sf::Sprite m_backGroundSprite;

	std::unordered_map<StateOptions, std::shared_ptr<GameState>> m_states;
	sf::RenderWindow* m_window;
};