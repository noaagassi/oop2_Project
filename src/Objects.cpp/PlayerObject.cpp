#pragma once
#include "Objects.h/PlayerObject.h"
#include <SFML/Graphics.hpp>

//------------------------------------------------
//constant ans enum
const int PLAYER_SPRITE_WIDTH = 64;
const int PLAYER_SPRITE_HEIGHT = 96;
const int PLAYER_SPRITES_PER_ROW = 4;
const int PLAYER_SPRITES_PER_COLUMN = 4;
const float PLAYER_MOVE_SPEED =0.5f;
//------------------------------------------------


bool PlayerObject::m_registerit = FactoryObject::registerit(PLAYER_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PlayerObject>(pos); });




PlayerObject::PlayerObject(const sf::Vector2f& initPosition)
    : MovingObject(initPosition)
{
    //m_speed = PLAYER_MOVE_SPEED;
    setObjTexture(PLAYER_OBJ);
    setScale(1.0f, 1.0f);

    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    rightFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
    downFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
    upFrames = { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };

    currentFrames = &defaultFrames;
    m_objectSprite.setTextureRect((*currentFrames)[0]);

    
}
//------------------------------------------------

void PlayerObject::update(float deltaTime, sf::RenderWindow* window)
{

    handleInput();
    animate(deltaTime);

    m_objectSprite.setPosition(m_position);
    
    updateFlashlight(window);
}
//------------------------------------------------

void PlayerObject::draw(sf::RenderWindow* window) const
{
    BaseObject::draw(window); 
    m_flashlight.draw(window);
}

//------------------------------------------------

//------------------------------------------------
sf::IntRect PlayerObject::getFrame(int row, int col)
{
    return sf::IntRect(col * PLAYER_SPRITE_WIDTH, row * PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
}

void PlayerObject::handleInput()
{
    isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_position.x -= PLAYER_MOVE_SPEED;
        currentFrames = &leftFrames;
        isMoving = true;
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {      
        m_position.x += PLAYER_MOVE_SPEED;
        currentFrames = &rightFrames;
        isMoving = true;
       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_position.y -= PLAYER_MOVE_SPEED;
        currentFrames = &upFrames;
        isMoving = true;
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_position.y += PLAYER_MOVE_SPEED;
        currentFrames = &downFrames;
        isMoving = true;
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){


    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        
    }





    if (!isMoving) {
        currentFrames = &defaultFrames;
    }
}



void PlayerObject::animate(float deltaTime) {
    if (clock.getElapsedTime().asSeconds() > 0.1f) {
        spriteIndex = (spriteIndex + 1) % currentFrames->size();
        m_objectSprite.setTextureRect((*currentFrames)[spriteIndex]);
        clock.restart();
    }
}


 
void PlayerObject:: updateFlashlight(sf::RenderWindow* window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f direction = sf::Vector2f(mousePosition) - m_position;
    m_flashlight.update(m_position, direction);

}