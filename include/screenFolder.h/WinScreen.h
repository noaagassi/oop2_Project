#pragma once
#include "screenFolder.h/GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>

class WinScreen : public GameState {
public:
    WinScreen(sf::RenderWindow& window);
    ~WinScreen();
    void draw() override;
    void update() override;
    std::shared_ptr <GameState> isStateChanged() override;

private:
    void handleInput();
    void loadTextures();

    sf::RenderWindow& m_window;

    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;

    sf::Texture m_menuButtonTexture;
    sf::Sprite m_menuButtonSprite;

    sf::Texture m_exitButtonTexture;
    sf::Sprite m_exitButtonSprite;

    bool m_stateChanged;
    GameState* m_nextState;
};
