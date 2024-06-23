#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int NUMBER_OF_OBJECTS = 27;

enum Object_ID {
    CLOCK_OBJ,
    INSTRUCTION_PAGE_1_OBJ,
    INSTRUCTION_PAGE_2_OBJ,
    LOOSE_SCREEN_OBJ,
    WEEN_SCREEN_OBJ,
    PAUSE_SCREEN_OBJ,
    MENU_BACK_GROUND_OBJ,
    NEW_GAME_BUTTON_OBJ,
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
    ROCKET_WEAPON_2_OBJ,
    MASSIVE_LASER_WEAPON_3_OBJ,
    BALLS_WEAPON_4,
    WEAPON_SUPER_OBJ,
    WEAPON_ENEMY_1_OBJ,
    WEAPON_ENEMY_2_OBJ,
    FREEZE_GIFT_OBJ,
    LIFE_GIFT_OBJ,
    WEAPON_GIFT_OBJ,
    PLAYER_OBJ
};

class TextureHandler
{
public:
    TextureHandler();

    static TextureHandler& getInstance();

    sf::Texture* getObjTexture(Object_ID name);

    //sf::Font getFont() const;

    ~TextureHandler();

private:

    std::string m_imgNames[NUMBER_OF_OBJECTS] = {
        "clock.png",              "instruction1.png",  "instruction2.png",
        "looseBackGround.png"     "weenBackGround.png" "pauseBackGround.png"
        "menuBackGround.png",     "newGameButon.png",  "exitButton.png",
        "instructionButton.png",  "pauseButton.png",   "wall.png",
        "bush.png",               "portal.png",        "poison.png",        
        "enemy1.png",             "enemy2.png",        "trees.png",
        "regularLaserWeapon1.png","rocketWeapon2.png", "massiveLaserWeapon3.png" ,
        "weaponSuper.png",        "weaponSuper.png",   "weaponEnemy1.png",  
        "weaponEnemy2.png",       "freezeGift.png",    "lifeGift.png",      
        "weaponGift.png",         "player.png" };

    sf::Texture m_textures[NUMBER_OF_OBJECTS];
    //sf::Font m_font;
};