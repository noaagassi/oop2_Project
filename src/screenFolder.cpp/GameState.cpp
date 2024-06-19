#include "screenFolder.h/GameState.h"












GameState::GameState(sf::RenderWindow* window)
    :m_window(window)
{
}

void GameState::setObjTexture(Object_ID objNum)
{
    sf::Texture* texturePtr = TextureHandler::getInstance().getObjTexture(objNum);
    m_backGroundSprite.setTexture(*texturePtr);
}

GameState::~GameState()
{
}

void GameState::initMap(std::shared_ptr<GameState> state_ptr, StateOptions state_name)
{
    m_states[state_name] = state_ptr;
}