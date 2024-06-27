#pragma once
#include <string>
#include <SFML/Graphics.hpp>

enum class TextureID {
    NewGame,
    Exit,
    Instructions,
    Pause,
    Resume
};
const std::string NAME_OF_PNG_FILES[] = {
    "new_game.png", // TextureID::NewGame
    "exit.png",     // TextureID::Exit
    "help.png",     // TextureID::Help
    "player.png"
};

const int NUM_OF_TEXTURES = sizeof(NAME_OF_PNG_FILES) / sizeof(NAME_OF_PNG_FILES[0]);

const sf::Vector2f textureSize(200.0f, 100.0f);

const unsigned int PLAY_WINDOW_HEIGHT = 850;
const unsigned int PLAY_WINDOW_WIDTH = 1000;
const float VIEW_HEIGHT = 400;
const float VIEW_WIDTH = 600;
const float MAP_HEIGHT = 60;
const float MAP_WIDTH = 60;



enum StateOptions {
    Null,
    PlayScrn,
    MenuScrn,
    PauseScrn,
    InstructionsScrn,
    ResumeScrn,
    Exit
};


//enum class COLOR_OF_OBJECT {
//    GREEN,              //TREE
//    LIGHT_GREEN,        //BUSH
//    PURPLE,             //PLAYER 
//    BROWN,              //WALL
//    BLUE               //PORTAL
//    
//};



