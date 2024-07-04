//to do:
//check handle input func needed
//check button need


#pragma once
#include <SFML/Graphics.hpp>
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/InstructionsState.h"
#include "Buttons.h/Button.h"


class Instructions : public GameState
{
public:
    Instructions(sf::RenderWindow* window); 
    ~Instructions();
    void draw() override;
    void update(float deltatime) override;
    void handleEvent(sf::Event event);
    //std::shared_ptr <GameState> isStateChanged() override;
   //std::shared_ptr <GameState> isStateChanged(sf::Event event) override;

private:

    enum class Page {
        Page1,
        Page2
    };

    Page m_currentPage;

    std::vector<std::unique_ptr<Button>> m_buttons; // [next page,  prious page, back to pause, back to menu]

    //****************************nned to handle the buttons***************************************************
    //****************************nned to handle the buttons***************************************************



};