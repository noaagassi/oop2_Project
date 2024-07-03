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
    ROCKET_HEAT,
    BALL_SHOOT,
    BALL_HIT,
    FREEZE,
    UN_FREEZE,
    WEAPON_GIFT,
    EXTRA_LIFE


};

class SoundsHandler {
public:
    SoundsHandler();
    ~SoundsHandler();
    static SoundsHandler& getInstance();

    void playSound(Sound_Id id);

private:

    const std::string m_soundNames[SOUND_NUM] = {
        /*"sounds/.wav", */       "sounds/game_op2.wav"     ,"sounds/loose1.wav",
        "sounds/win2.wav",        "sounds/poison2.wav"      ,"sounds/laser_shoot.wav",
        "sounds/laser_hit.wav",   "sounds/rocket_shoot.wav" ,"sounds/rocket_hit.wav",
        "sounds/ball_shoot1.wav", "sounds/ball_pop.wav"     ,"sounds/freeze_start.wav",
        "sounds/freeze_end.wav",  "sounds/take_weapon.wav"  ,"sounds/extra_life.wav" };


    sf::Sound m_sound;
    sf::Sound m_sounds[SOUND_NUM];
    sf::SoundBuffer m_buffers[SOUND_NUM];
};
