#include "screenFolder.h/GameState.h"



GameState::GameState()
{
  
}

GameState::~GameState()
{
}

void GameState::initMap(std::shared_ptr<GameState> state_ptr, StateOptions state_name)
{
    m_states[state_name] = state_ptr;
}