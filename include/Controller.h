#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerObject.h"
#include "screenFolder.h/GameState.h"

class Controller {
public:
    Controller();
    void run();

private:
    sf::RenderWindow m_window;
    PlayerObject m_playerObject;
    GameState* m_currentScreen;

    void handleEvents();
    void update(float deltaTime);
    void render();
};