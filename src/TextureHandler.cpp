
#include "TextureHandler.h"


// loads the textures into an array of textures
TextureHandler::TextureHandler()
{
    for (int i = 0; i < NUMBER_OF_OBJECTS; ++i)
    {
        m_textures[i].loadFromFile(m_imgNames[i]);
    }

}

TextureHandler& TextureHandler::getInstance()
{
    static TextureHandler instance;
    return instance;
}


//returns the appropriate texture according to the nmber received
sf::Texture* TextureHandler::getObjTexture(Object_ID name)
{
    return &m_textures[name];
}



TextureHandler::~TextureHandler() {}