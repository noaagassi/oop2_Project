
#include "SoundsHandler.h"
#include <iostream>
#include <filesystem>  // כלול את הספרייה של filesystem

namespace fs = std::filesystem;
 //loadds the sounds into the buffer array

SoundsHandler::SoundsHandler()
{
    for (int i = 0; i < SOUND_NUM; i++)
    {
        m_buffers[i].loadFromFile(m_soundNames[i]);
        m_sounds[i].setBuffer(m_buffers[i]);
    }

    m_music.openFromFile("game_op2.wav");
}

SoundsHandler::~SoundsHandler() {}


 
SoundsHandler& SoundsHandler::getInstance()
{
    static SoundsHandler instance;
    return instance;
}

void SoundsHandler::playMusic()
{
    m_music.setLoop(true);
    m_music.play();
}

void SoundsHandler::playSound(Sound_Id id)
{
    m_sounds[id].play();
}