#pragma once
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/PlayState.h"
#include "screenFolder.h/Instructions.h"
#include "Utilities.h"
#include "Buttons.h/Button.h"
#include <SFML/Graphics.hpp>



class LooseScreen : public GameState
{
public:
    LooseScreen(sf::RenderWindow* window);
    ~LooseScreen();
    void draw() override;
    void update(float deltatime) override;
    void handleEvent(sf::Event event);
//    std::shared_ptr <GameState> isStateChanged() override;
    std::shared_ptr <GameState> isStateChanged(sf::Event event) override;

private:


    std::vector<std::unique_ptr<Button>> m_buttons;  // []




  
};
