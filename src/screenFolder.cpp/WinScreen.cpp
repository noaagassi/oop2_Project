#include "screenFolder.h/WinScreen.h"
#include "screenFolder.h/Menu.h"
#include <iostream>


WinScreen::WinScreen(sf::RenderWindow& window)
    : m_window(window), m_stateChanged(false), m_nextState(nullptr) {
    loadTextures();

    // Configurar la textura de fondo
    m_backgroundSprite.setTexture(m_backgroundTexture);
    m_backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / m_backgroundTexture.getSize().x,
        static_cast<float>(window.getSize().y) / m_backgroundTexture.getSize().y);

    // Configurar los botones
    m_menuButtonSprite.setTexture(m_menuButtonTexture);
    m_menuButtonSprite.setPosition(window.getSize().x / 2 - m_menuButtonSprite.getGlobalBounds().width / 2, window.getSize().y / 2);

    m_exitButtonSprite.setTexture(m_exitButtonTexture);
    m_exitButtonSprite.setPosition(window.getSize().x / 2 - m_exitButtonSprite.getGlobalBounds().width / 2, window.getSize().y / 2 + 100);
}

void WinScreen::draw() {
    m_window.clear();
    m_window.draw(m_backgroundSprite);
    m_window.draw(m_menuButtonSprite);
    m_window.draw(m_exitButtonSprite);
    m_window.display();
}

void WinScreen::update() {
    handleInput();
}

GameState* WinScreen::isStateChanged() {
    if (m_stateChanged) {
        return m_nextState;
    }
    return nullptr;
}

void WinScreen::handleInput() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                if (m_menuButtonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    m_stateChanged = true;
                    m_nextState = new Menu();
                }
                else if (m_exitButtonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    m_window.close();
                }
            }
        }
    }
}

void WinScreen::loadTextures() {
    if (!m_backgroundTexture.loadFromFile("win_background.png")) {
        std::cerr << "Error al cargar la textura de fondo" << std::endl;
    }
    if (!m_menuButtonTexture.loadFromFile("menu_button.png")) {
        std::cerr << "Error al cargar la textura del botón Menu" << std::endl;
    }
    if (!m_exitButtonTexture.loadFromFile("exit_button.png")) {
        std::cerr << "Error al cargar la textura del botón Exit" << std::endl;
    }
}