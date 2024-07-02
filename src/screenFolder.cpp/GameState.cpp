#include "screenFolder.h/GameState.h"

GameState::GameState(sf::RenderWindow* window, unsigned int width, unsigned int height)
    :m_window(window),m_windowSize(width,height)
{
}

void GameState::setScale(Object_ID name)
{

    sf::Vector2u textureSize = TextureHandler::getInstance().getObjTexture(name)->getSize();

    float scaleX = static_cast<float>(m_windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(m_windowSize.y) / textureSize.y;

    m_backGroundSprite.setScale(scaleX, scaleY);
}


void GameState::setObjTexture(Object_ID name)
{
    sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(name);
    m_backGroundSprite.setTexture(*texturePtr);
}

GameState::~GameState()
{
}

std::shared_ptr<GameState> GameState::isStateChanged(sf::Event event)
{
    if (event.type == sf::Event::Closed) {
        m_window->close();
    }
    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (auto& button : m_buttons) {
                if (button->isMouseOver(m_window)) {
                    StateOptions state = button->click();
                    if (state == StateOptions::Exit)
                    {
                        m_window->close();
                    }
                    return m_states[state];
                }
            }
        }
    }

    return nullptr;
}

void GameState::initMap(std::shared_ptr<GameState> state_ptr, StateOptions state_name)
{
    m_states[state_name] = state_ptr;
}