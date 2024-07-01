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

const sf::Vector2f textureSize(100.0f, 100.0f);

const unsigned int PLAY_WINDOW_HEIGHT = 720;
const unsigned int PLAY_WINDOW_WIDTH = 1080;
const float VIEW_HEIGHT = 200;
const float VIEW_WIDTH = 400;
const float MAP_HEIGHT = 60;
const float MAP_WIDTH = 60;

const float PLAYER_WIDTH = 0.4F;
const float PLAYER_HEIGHT = 0.4F;


const float WIDTH = 3000,
            HEIGHT = 3000;




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



