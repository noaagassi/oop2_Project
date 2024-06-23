#include "screenFolder.h/GameState.h"

GameState::GameState(sf::RenderWindow* window)
    :m_window(window)
{
}

void GameState::setScale(Object_ID name)
{

    sf::Vector2u windowSize = m_window->getSize();
    sf::Vector2u textureSize = TextureHandler::getInstance().getObjTexture(name)->getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

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

void GameState::initMap(std::shared_ptr<GameState> state_ptr, StateOptions state_name)
{
    m_states[state_name] = state_ptr;
}