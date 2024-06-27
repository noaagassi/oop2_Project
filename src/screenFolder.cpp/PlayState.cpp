#include "screenFolder.h/PlayState.h"

PlayState::PlayState(sf::RenderWindow* window)
    :GameState(window)
{

   
    setObjTexture(PLAY_SCREEN_OBJ);
    setScale(PLAY_SCREEN_OBJ);
}

PlayState::~PlayState()
{
}

sf::Vector2f PlayState::getPlayerLocation()
{
    return m_board.getPlayrLocation();
}



void PlayState::draw()
{
    m_window->setTitle("Brawl stars");
    
    m_window->setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));         //original- 1000,700
    m_window->draw(m_backGroundSprite);
    m_board.draw(m_window);
}

void PlayState::update(float deltatime)
{
    m_board.update(deltatime,m_window);
}


std::shared_ptr<GameState> PlayState::isStateChanged(sf:: Event event)
{
    /*return std::shared_ptr<GameState>();*/
    return nullptr;
}
