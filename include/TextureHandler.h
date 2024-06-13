#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>

class TextureHandler
{
public:
	TextureHandler();
	sf::Texture* getObjTexture(int objNum);

private:
	sf::Texture m_textures[NUM_OF_TEXTURES];
};