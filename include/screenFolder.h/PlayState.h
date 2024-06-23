#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
//#include "PauseButton.h"
#include "screenFolder.h/GameState.h"
#include "Board.h"
#include"BaseButton.h"
//

class PlayState : public GameState
{
public:
    PlayState(sf::RenderWindow* window);
    ~PlayState();
    void draw() override;
    void update() override;
    std::shared_ptr <GameState> isStateChanged() override;

private:

    //std::shared_ptr<PauseButton> m_pauseButton;
   
    sf::View view;
    Board m_board;

};