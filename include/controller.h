#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerObject.h"

class Controller {
public:
    Controller();
    void run();

private:
    sf::RenderWindow m_window;
    PlayerObject m_playerObject;

    void handleEvents();
    void update(float deltaTime);
    void render();
};