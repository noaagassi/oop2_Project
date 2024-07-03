
#include "SoundsHandler.h"
#include <iostream>
#include <filesystem>  // כלול את הספרייה של filesystem

namespace fs = std::filesystem;
 //loadds the sounds into the buffer array

//SoundsHandler::SoundsHandler()
//{
//    for (int i = 0; i < SOUND_NUM; i++)
//    {
//        m_buffers[i].loadFromFile(m_soundNames[i]);
//    }
//
//     //matches each sound with it's own buffer
//    for (int i = 0; i < SOUND_NUM; i++)
//    {
//        m_sounds[i].setBuffer(m_buffers[i]);
//    }
//}

SoundsHandler::SoundsHandler() {
    for (int i = 0; i < SOUND_NUM; ++i) {
        std::string fullPath = fs::absolute(m_soundNames[i]).string();  // שימוש במשתנה fs במקום std::filesystem::absolute
        std::cout << "Loading sound file: " << fullPath << std::endl;
        if (!m_buffers[i].loadFromFile(fullPath)) {
            std::cerr << "Error loading sound file: " << fullPath << std::endl;
        }
        m_sounds[i].setBuffer(m_buffers[i]);
    }
}

SoundsHandler::~SoundsHandler() {}


 
SoundsHandler& SoundsHandler::getInstance()
{
    static SoundsHandler instance;
    return instance;
}

void SoundsHandler::playSound(Sound_Id id)
{
    m_sounds[id].play();
}