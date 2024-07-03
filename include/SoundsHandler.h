#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int SOUND_NUM = 14;

enum Sound_Id {
    /*FIRST_MENU,*/
    THE_GAME_SOUND,
    LOOSE,
    WIN,
    POISON,
    LASER_SHOOT,
    LASER_HIT,
    ROCKET_SHOOT,
    ROCKET_HIT,
    BALL_SHOOT,
    BALL_HIT,
    FREEZE,
    UN_FREEZE,
    WEAPON_GIFT,
    EXTRA_LIFE


};
/*
class SoundsHandler
{

public:

    SoundsHandler();
    ~SoundsHandler();
    static SoundsHandler& getInstance();

    void playSound(Sound_Id id);

private:

    const std::string m_soundNames[SOUND_NUM] = {
    "resources/sounds/game_op2.wav",
    "resources/sounds/loose1.wav",
    "resources/sounds/win2.wav",
    "resources/sounds/poison2.wav",
    "resources/sounds/laser_shoot.wav",
    "resources/sounds/laser_hit.wav",
    "resources/sounds/rocket_shoot.wav",
    "resources/sounds/rocket_hit.wav",
    "resources/sounds/ball_shoot1.wav",
    "resources/sounds/ball_pop.wav",
    "resources/sounds/freeze_start.wav",
    "resources/sounds/freeze_end.wav",
    "resources/sounds/take_weapon.wav",
    "resources/sounds/extra_life.wav"
    };

    //sf::Sound m_sound;
    sf::Sound m_sounds[SOUND_NUM];
    sf::SoundBuffer m_buffers[SOUND_NUM];

};
*/