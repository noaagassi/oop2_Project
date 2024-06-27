#include "screenFolder.h/PlayState.h"

PlayState::PlayState(sf::RenderWindow* window)
    :GameState(window,PLAY_WINDOW_WIDTH,PLAY_WINDOW_HEIGHT)
{
    
       
    setScale(PLAY_SCREEN_OBJ);
    setObjTexture(PLAY_SCREEN_OBJ);

}

PlayState::~PlayState()
{
}

sf::Vector2f PlayState::getPlayerLocation() const
{
    return m_board.getPlayrLocation();
}

sf::FloatRect PlayState:: getPlayerBounds() const
{
    return m_board.getPlayerBounds();
}


void PlayState::draw()
{
    m_window->setTitle("Brawl stars");
    m_window->setSize(m_windowSize);
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
