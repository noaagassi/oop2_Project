#include "screenFolder.h/PlayState.h"

#include "Buttons.h/PauseGameCommand.h"
#include "Buttons.h/Button.h"

PlayState::PlayState(sf::RenderWindow* window)
    :GameState(window,PLAY_WINDOW_WIDTH,PLAY_WINDOW_HEIGHT)
{
    
    setObjTexture(PLAY_SCREEN_OBJ);
    setScale(PLAY_SCREEN_OBJ);

    std::unique_ptr<CommandButton> pauseCmd = std::make_unique<PauseGameCommand>();
   
    m_buttons.push_back(std::make_unique<Button>(std::move(pauseCmd), PAUSE_BUTTON_OBJ, 100, 200));
   
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
    for (auto& button : m_buttons) {
        button->draw(m_window);
    };
   
    m_window->display();
}

void PlayState::update(float deltatime)
{
    //m_board.update(deltatime,m_window);
}


  /*
std::shared_ptr<GameState> PlayState::isStateChanged(sf:: Event event)
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
 */