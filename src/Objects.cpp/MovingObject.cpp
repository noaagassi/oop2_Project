#include "Objects.h/MovingObject.h"

//------------------------------------------------
//constant ans enum
const int PLAYER_SPRITE_WIDTH = 64;
const int PLAYER_SPRITE_HEIGHT = 96;
const int PLAYER_SPRITES_PER_ROW = 4;
const int PLAYER_SPRITES_PER_COLUMN = 4;
//------------------------------------------------

MovingObject::MovingObject(const sf::Vector2f& initPosition)
	: spriteIndex(0), isMoving(false), currentFrames(&defaultFrames), BaseObject(initPosition)
{}

MovingObject::MovingObject()
{
}



void MovingObject::setObjTexture(Object_ID id) {
    sf::Texture* texture = TextureHandler::getInstance().getObjTexture(id);
    if (texture) {
        m_objectSprite.setTexture(*texture);
    }
}

void MovingObject::setScale(float x, float y) {
    m_objectSprite.setScale(x, y);
}

sf::IntRect MovingObject::getFrame(int row, int col) {
    return sf::IntRect(col * PLAYER_SPRITE_WIDTH, row * PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
}

void MovingObject::update(float deltaTime, sf::RenderWindow* window) {
    animate(deltaTime);
    m_objectSprite.setPosition(m_position);
}

void MovingObject::draw(sf::RenderWindow* window) {
    window->draw(m_objectSprite);
}

void MovingObject::animate(float deltaTime) {
    if (clock.getElapsedTime().asSeconds() > 0.1f) {
        spriteIndex = (spriteIndex + 1) % currentFrames->size();
        m_objectSprite.setTextureRect((*currentFrames)[spriteIndex]);
        clock.restart();
    }
}