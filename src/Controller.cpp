#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(800, 600), "Sprite Movement Example") {}

void Controller::run() {
    sf::Clock clock;

    while (m_window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        handleEvents();
        update(deltaTime);
        render();
    }
}

void Controller::handleEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}

void Controller::update(float deltaTime) {
    m_playerObject.update(deltaTime);
}

void Controller::render() {
    m_window.clear();
    m_playerObject.draw(m_window);
    m_window.display();
}