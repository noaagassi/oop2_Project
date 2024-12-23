#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int NUMBER_OF_OBJECTS =34;

enum Object_ID {
    CLOCK_OBJ,
    INSTRUCTION_PAGE_1_OBJ,
    INSTRUCTION_PAGE_2_OBJ,
    LOOSE_SCREEN_OBJ,
    WEEN_SCREEN_OBJ,
    PAUSE_SCREEN_OBJ,
    MENU_BACK_GROUND_OBJ,
    NEW_GAME_BUTTON_OBJ,
    RESUME_GAME_BUTTON_OBJ,
    EXIT_BUTTON_OBJ,
    INSTRUCTION_BUTTON_OBJ,
    PAUSE_BUTTON_OBJ, 
    WALL_OBJ,
    BUSH_OBJ,
    PORTAL_OBJ,
    POISON_OBJ,
    ENEMY_1_OBJ,
    ENEMY_2_OBJ,
    TREES_OBJ,
    REGULAR_LASER_WEAPON_1_OBJ,
    BOMB_OBJ,
    MASSIVE_LASER_WEAPON_3_OBJ,
    BALLS_WEAPON_4,
    WEAPON_SUPER_OBJ,
    WEAPON_ENEMY_1_OBJ,
    WEAPON_ENEMY_2_OBJ,
    FREEZE_GIFT_OBJ,
    LIFE_GIFT_OBJ,
    WEAPON_GIFT_OBJ,
    PLAYER_OBJ,
    PLAY_SCREEN_OBJ,
    BULLET_OBJ,
    HEARTS_PLAYER_OBJ,
    SPREADING_LASER,
    EXPLOSION
};

class TextureHandler
{
public:
    TextureHandler();

    static TextureHandler& getInstance();

    sf::Texture* getObjTexture(Object_ID name);

    ~TextureHandler();

private:

    std::string m_imgNames[NUMBER_OF_OBJECTS] = {
        "clock.png",              "instruction1.png",       "instruction2.png",
        "looseBackGround.png",    "weenBackGround.png",     "pauseBackGround.png",
        "menuBackGround.png",     "newGameButton.png",      "resumeButton.png",
        "exitButton.png",         "instructionButton.png",  "pauseButton.png",   
        "wall.png",               "bush.png",               "portal.png",        
        "poison.png",             "enemy1.png",             "enemy2.png",
        "trees.png",              "regularLaserWeapon1.png","bomb.png",
        "massiveLaserWeapon3.png","ballWeapon.png",         "weaponSuper.png",   
        "weaponEnemy1.png",       "weaponEnemy2.png",       "freezeGift.png",    
        "lifeGift.png",           "weaponGift.png",         "player.png",        
        "playBackGround.png",     "bullet.png",             "heartplayer.png",
        "explosion.png"};


    sf::Texture m_textures[NUMBER_OF_OBJECTS];
};