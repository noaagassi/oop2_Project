#pragma once
//#include "InstructionsButton.h"
#include "screenFolder.h/GameState.h"
#include "screenFolder.h/PlayState.h"
#include "screenFolder.h/Instructions.h"
#include "Utilities.h"
#include "Buttons.h/Button.h"
#include <SFML/Graphics.hpp>

class PausePage : public GameState
{
public:
    PausePage(sf::RenderWindow* window);
    ~PausePage();
    void draw() override;
    void update() override;
    //std::shared_ptr <GameState> isStateChanged() override;
    std::shared_ptr <GameState> isStateChanged(sf::Event event) override;
private:

    std::vector<std::unique_ptr<Button>> m_buttons; // [resume, restart, exit, instructions]





};
