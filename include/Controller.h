#pragma once
#include <SFML/Graphics.hpp>
#include "Objects.h/PlayerObject.h"
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/Menu.h"
#include "screenFolder.h/Instructions.h"
#include "screenFolder.h/PlayState.h"
#include "screenFolder.h/PausePage.h"



class Controller {
public:
    Controller();
    void run();

private:
    sf::RenderWindow m_window;
    std::shared_ptr <GameState> m_currentScreen;
    
    std::shared_ptr<Menu> m_menu;
    std::shared_ptr<PlayState> m_playState;
    std::shared_ptr<Instructions> m_instructions;
    std::shared_ptr<PausePage> m_pause;

};