#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


const int SOUND_NUM = 15;

enum Sound_Id {
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
    EXTRA_LIFE,
    POISON_HIT,
    PORTAL_ENTER

};

class SoundsHandler
{

public:

    SoundsHandler();
    ~SoundsHandler();
    static SoundsHandler& getInstance();
    void playMusic();

    void playSound(Sound_Id id);

private:

    const std::string m_soundNames[SOUND_NUM] = {
        "loose1.wav",       "win2.wav",       "poison2.wav",    
        "laser_shoot.wav",  "laser_hit.wav",  "rocket_shoot.wav",
        "rocket_hit.wav",   "ball_shoot1.wav","ball_pop.wav",
        "freeze_start.wav", "freeze_end.wav", "take_weapon.wav",
        "extra_life.wav",   "poison_hit.wav", "portal_enter.wav"};

    sf::Music m_music;
    sf::Sound m_sound;
    sf::Sound m_sounds[SOUND_NUM];
    sf::SoundBuffer m_buffers[SOUND_NUM];
};



//SoundsHandler::getInstance().playSound(Sound_Id::)

//THE_GAME_SOUND,