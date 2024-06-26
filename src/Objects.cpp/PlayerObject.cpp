#pragma once
#include "Objects.h/PlayerObject.h"
#include <SFML/Graphics.hpp>

//------------------------------------------------
//constant ans enum
const int PLAYER_SPRITE_WIDTH = 64;
const int PLAYER_SPRITE_HEIGHT = 96;
const int PLAYER_SPRITES_PER_ROW = 4;
const int PLAYER_SPRITES_PER_COLUMN = 4;
const float PLAYER_MOVE_SPEED =1.9f;
//------------------------------------------------



bool PlayerObject::m_registerit = FactoryObject::registerit(PLAYER_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PlayerObject>(pos); });
//-------------------------------------------------

PlayerObject::PlayerObject(const sf::Vector2f& initPosition)
    :MovingObject(initPosition)
{
    setObjTexture(PLAYER_OBJ);
    //Animation a(initAnimationData(), Direction::Stay,&m_objectSprite);
    //m_animation = a;
    
    currentFrames = &defaultFrames;
    m_objectSprite.setTextureRect((*currentFrames)[0]);

    
    m_y = 100.f;
//------------------------------------------------

void PlayerObject::update(float deltaTime, sf::RenderWindow* window)
void PlayerObject::update(float deltaTime, sf::RenderWindow& window)
    handleInput();
    animate(deltaTime);
    m_objectSprite.setPosition(m_position);
//    MovingObject::update(deltaTime, window);
    
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f characterPosition = m_objectSprite.getPosition();
    sf::Vector2f direction = sf::Vector2f(mousePosition) - characterPosition;
    m_flashlight.update(characterPosition, direction);
    m_flashlight.update(characterPosition, direction);
//------------------------------------------------

void PlayerObject::draw(sf::RenderWindow* window)
{
    window->draw(m_objectSprite);
    //window->draw(m_flashlight.getShape());
    m_flashlight.draw(window);
}

//------------------------------------------------
//------------------------------------------------
//------------------------------------------------
sf::IntRect PlayerObject::getFrame(int row, int col)
{
    return sf::IntRect(col * PLAYER_SPRITE_WIDTH, row * PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
}

void PlayerObject::handleInput()
void PlayerObject::handleInput(sf::Keyboard::Key key)
    isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_position.x -= PLAYER_MOVE_SPEED;
        currentFrames = &leftFrames;
        isMoving = true;
        //goLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {      //right
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
