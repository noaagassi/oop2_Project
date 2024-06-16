#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerObject.h"
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/Menu.h"
#include "screenFolder.h/Instructions.h"
#include "screenFolder.h/PlayState.h"
//#include "screenFolder.h/PauseState.h"



class Controller {
public:
    Controller();
    void run();

private:
    sf::RenderWindow m_window;
    PlayerObject m_playerObject;
    GameState* m_currentScreen;
    
    Menu m_menu;
    Instructions m_instructions;
    PlayState m_playState;
   // PauseState m_pauseState;

    void handleEvents();
    void update(float deltaTime);
    void render();
};