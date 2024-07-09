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

const sf::Vector2f textureSize(300.0f, 200.0f);

const unsigned int CLOUD_POISEN_HEIGHT = 980;
const unsigned int CLOUD_POISEN_WIDTH = 1060;
const unsigned int PLAY_WINDOW_HEIGHT = 1000;
const unsigned int PLAY_WINDOW_WIDTH = 1080;
const float VIEW_HEIGHT = 200;
const float VIEW_WIDTH = 400;
const float MAP_HEIGHT = 60;
const float MAP_WIDTH = 60;

const float PLAYER_WIDTH = 0.4F;
const float PLAYER_HEIGHT = 0.4F;


const float WIDTH = 3000,
            HEIGHT = 3000;

const bool LESS = false,
           MORE = true;

enum StateOptions {
    Null,
    PlayScrn,
    MenuScrn,
    PauseScrn,
    InstructionsScrn,
    ResumeScrn,
    Exit,
    LooseScrn,
    WinScrn,
    Instruction1,
    Instruction2

};



/// for the frames of the player and enemyies
//constant ans enum
const int PLAYER_SPRITE_WIDTH = 62;
const int PLAYER_SPRITE_HEIGHT = 54;
const int BIG_ENEMY_SPRITE_WIDTH = 57;
const int BIG_ENEMY_SPRITE_HEIGHT = 63;
const int SMALL_ENEMY_SPRITE_WIDTH = 63;
const int SMALL_ENEMY_SPRITE_HEIGHT = 63;
const int PLAYER_SPRITES_PER_ROW = 4;
const int PLAYER_SPRITES_PER_COLUMN = 4;
const float PLAYER_MOVE_SPEED = 0.25f;