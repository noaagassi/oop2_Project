#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "screenFolder.h/GameState.h"  
#include "Buttons.h/Button.h"

#include "Board.h"
#include "Utilities.h"



class PlayState : public GameState
{
public:
    PlayState(sf::RenderWindow* window);
    ~PlayState();

    sf::Vector2f getPlayerLocation() const;
    sf::FloatRect getPlayerBounds() const;

    void draw() override;
    void update(float deltatime) override;
    std::shared_ptr <GameState> isStateChanged(sf::Event event) override;
    void handleView();

private:
    std::vector<std::unique_ptr<Button>> m_buttons; // [pause]

    
    
    sf::View m_view;
    sf::View m_uiView;
    Board m_board;
    
};