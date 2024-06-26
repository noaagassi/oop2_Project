#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "screenFolder.h/GameState.h"  
#include "Buttons.h/Button.h"

#include "Board.h"



class PlayState : public GameState
{
public:
    PlayState(sf::RenderWindow* window);
    ~PlayState();
    void draw() override;
    void update(float deltatime) override;
    void handleEvent(sf::Event event);
    std::shared_ptr <GameState> isStateChanged(sf::Event event) override;

private:
    
    std::vector<std::unique_ptr<Button>> m_buttons; // [pause]
    
    sf::View view;
    Board m_board;
    
};