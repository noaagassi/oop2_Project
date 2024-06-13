#include "Menu.h"
#include <iostream>
Menu::Menu()
    : m_window(sf::VideoMode(1000, 600), "Game Menu") 
{
    if (!m_backgroundTexture.loadFromFile("background.png")) 
    {
    }
    m_backgroundSprite.setTexture(m_backgroundTexture);
    
    sf::Vector2u windowSize = m_window.getSize();
    sf::Vector2u textureSize = m_backgroundTexture.getSize();

  //  float scaleX = static_cast<float>(windowSize.m_x) / textureSize.m_x;
   // float scaleY = static_cast<float>(windowSize.m_y) / textureSize.m_y;

  //  m_backgroundSprite.setScale(scaleX, scaleY);


    m_buttons.push_back(new NewGameButton("new_game.png", 100, 200));
    m_buttons.push_back(new ExitButton("exit.png", 100, 300));
    m_buttons.push_back(new InstructionsButton("instructions.png", 100, 400));
}

void Menu::run()
{
    while (m_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Menu::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                for (auto& button : m_buttons) {
                    if (button->isMouseOver(m_window)) {
                        button->onClick();
                    }
                }
            }
        }
    }
}

void Menu::update()
{
}

void Menu::render()
{
    m_window.clear();
    m_window.draw(m_backgroundSprite);

    for (auto& button : m_buttons) {
        button->render(m_window);
    }
    m_window.display();
}
