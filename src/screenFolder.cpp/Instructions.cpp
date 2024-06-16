#pragma once

#include "screenFolder.h/Instructions.h"
#include "screenFolder.h/Menu.h"
#include <iostream>
/*
Instructions:: Instructions()
    : m_window(sf::VideoMode(1000, 600), "Instructions") , 
    m_currentPage(Page::Page1), m_stateChanged(false), m_nextState(nullptr) {
    loadTextures();

    // Configurar la textura de fondo
    m_backgroundSprite.setTexture(m_backgroundTexture);
    m_backgroundSprite.setScale(
        static_cast<float>(m_window.getSize().x) / m_backgroundTexture.getSize().x,
        static_cast<float>(m_window.getSize().y) / m_backgroundTexture.getSize().y);

    // Configurar el texto de instrucciones
    if (!m_font.loadFromFile("path/to/font.ttf")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
    }
    m_instructionsText.setFont(m_font);
    m_instructionsText.setCharacterSize(24);
    m_instructionsText.setFillColor(sf::Color::White);

    // Configurar los botones
    m_nextButtonSprite.setTexture(m_nextButtonTexture);
    m_nextButtonSprite.setPosition(m_window.getSize().x - 150, m_window.getSize().y - 50);

    m_playButtonSprite.setTexture(m_playButtonTexture);
    m_playButtonSprite.setPosition(m_window.getSize().x - 150, m_window.getSize().y - 50);

    m_backButtonSprite.setTexture(m_backButtonTexture);
    m_backButtonSprite.setPosition(50, m_window.getSize().y - 50);
}


void Instructions::draw()
{
    m_window.clear();
    m_window.draw(m_backgroundSprite);

    if (m_currentPage == Page::Page1) {
        m_instructionsText.setString("Instructions Page 1:\n\n- Step 1\n- Step 2\n- Step 3");
        m_window.draw(m_nextButtonSprite);
    }
    else if (m_currentPage == Page::Page2) {
        m_instructionsText.setString("Instructions Page 2:\n\n- Step 4\n- Step 5\n- Step 6");
        m_window.draw(m_playButtonSprite);
        m_window.draw(m_backButtonSprite);
    }

    m_instructionsText.setPosition(50, 50);
    m_window.draw(m_instructionsText);
    m_window.display();
}

void Instructions::update()
{
    handleInput();
}

GameState* Instructions::isStateChanged()
{
    if (m_stateChanged) {
        return m_nextState;
    }
    return nullptr;
}

void Instructions::handleInput()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                if (m_currentPage == Page::Page1 && m_nextButtonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    m_currentPage = Page::Page2;
                }
                else if (m_currentPage == Page::Page2 && m_playButtonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    m_stateChanged = true;
                    m_nextState = new Menu(); 
                }
                else if (m_currentPage == Page::Page2 && m_backButtonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    m_currentPage = Page::Page1;
                }
            }
        }
    }
}

void Instructions::loadTextures()
{
    if (!m_backgroundTexture.loadFromFile("background.png")) {
        std::cerr << "Error al cargar la textura de fondo" << std::endl;
    }
    if (!m_nextButtonTexture.loadFromFile("next_button.png")) {
        std::cerr << "Error al cargar la textura del botón Next" << std::endl;
    }
    if (!m_playButtonTexture.loadFromFile("play_button.png")) {
        std::cerr << "Error al cargar la textura del botón Play" << std::endl;
    }
    if (!m_backButtonTexture.loadFromFile("back_button.png")) {
        std::cerr << "Error al cargar la textura del botón Back" << std::endl;
    }
}
*/