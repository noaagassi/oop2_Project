#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
//#include "PauseButton.h"
#include "screenFolder.h/GameState.h"
#include "Board.h"



class PlayState : public GameState
{
public:
    PlayState(sf::RenderWindow* window);
    ~PlayState();

    void draw() override;
    void update(float deltatime) override;
    //std::shared_ptr <GameState> isStateChanged() override;
    std::shared_ptr <GameState> isStateChanged(sf::Event event) override;

private:
    
    
    
    sf::View view;
    Board m_board;
    
};