#pragma once
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/PlayState.h"
#include "screenFolder.h/InstructionsState.h"
#include "Utilities.h"
#include "Buttons.h/Button.h"
#include <SFML/Graphics.hpp>

class PausePage : public GameState
{
public:
    PausePage(sf::RenderWindow* window);
    ~PausePage();
    void draw() override;
    void update(float deltatime) override;
    void handleEvent(sf::Event event);
    //std::shared_ptr <GameState> isStateChanged(sf::Event event) override;

private:

    //std::vector<std::unique_ptr<Button>> m_buttons; // [resume, restart, exit, instructions]





};
