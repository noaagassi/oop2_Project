#include "screenFolder.h/PlayState.h"

PlayState::PlayState(sf::RenderWindow* window)
    :GameState(window), view(sf::FloatRect(0, 0, 400, 300))
{

    //m_pauseButton = std::make_shared<PauseButton>(sf::Vector2f(50, 50), "Pause");

    setObjTexture(PLAY_SCREEN_OBJ);
    setScale(PLAY_SCREEN_OBJ);
}

PlayState::~PlayState()
{
}
////////////////////////////////////////////////////////
void PlayState::draw()
{
    m_window->setTitle("Brawl stars");
    
    m_window->setSize(sf::Vector2u(1300, 900));         //original- 1000,700
    m_window->clear();
    m_window->draw(m_backGroundSprite);
    m_board.draw(m_window);
   
    m_window->display();
}

void PlayState::update(float deltatime)
{
    m_board.update(deltatime,m_window);
}

void PlayState::handleEvent(sf::Event event)
{
    while (m_window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            m_board.handleKeyPress(event.key.code);
            break;

        case sf::Event::MouseButtonPressed:         //for start shooting
                m_board.handleMousePressed(event);
                break;
        }
    }
}

//std::shared_ptr<GameState> PlayState::isStateChanged()
//{
//    return std::shared_ptr<GameState>();
//}
std::shared_ptr<GameState> PlayState::isStateChanged(sf:: Event event)
{
    return std::shared_ptr<GameState>();
}
///////////////////////////////////////////////////////

/*
GameState* PlayState::isStateChanged()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {

                if (m_pauseButton->isMouseOver(m_window)) {
                    return (m_pauseButton->onClick());
                }

            }
        }
    }
    return nullptr;
}*/