#pragma once
#include "screenFolder.h/GameState.h"
class Instructions : public GameState
{
public:
    Instructions(sf::RenderWindow& window);
    ~Instructions();
    void draw() override;
    void update() override;
    GameState* isStateChanged() override;
private:
    enum class Page {
        Page1,
        Page2
    };

    void handleInput();
    void loadTextures();

    sf::RenderWindow& m_window;
    Page m_currentPage;

    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;

    sf::Texture m_nextButtonTexture;
    sf::Sprite m_nextButtonSprite;

    sf::Texture m_playButtonTexture;
    sf::Sprite m_playButtonSprite;

    sf::Texture m_backButtonTexture;
    sf::Sprite m_backButtonSprite;

    sf::Font m_font;
    sf::Text m_instructionsText;

    bool m_stateChanged;
    GameState* m_nextState;
};