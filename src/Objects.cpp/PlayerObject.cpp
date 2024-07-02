#pragma once
#include "Objects.h/PlayerObject.h"
#include "Objects.h/BulletObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//------------------------------------------------
//constant ans enum
const int PLAYER_SPRITE_WIDTH = 64;
const int PLAYER_SPRITE_HEIGHT = 96;
const int PLAYER_SPRITES_PER_ROW = 4;
const int PLAYER_SPRITES_PER_COLUMN = 4;
const float PLAYER_MOVE_SPEED =5.0f;
//------------------------------------------------


bool PlayerObject::m_registerit = FactoryObject::registerit(PLAYER_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PlayerObject>(pos); });




PlayerObject::PlayerObject(const sf::Vector2f& initPosition)
    : MovingObject(initPosition)
{
    setObjTexture(PLAYER_OBJ);
    setTheScale(1.0f, 1.0f);

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

    handleInput(window);
    animate(deltaTime);
    m_objectSprite.setPosition(m_position);
    
    updateFlashlight(window);
    m_currentWeapon->update(deltaTime);
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

void PlayerObject::handleInput(sf::RenderWindow* window)
{

    isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_position.x -= PLAYER_MOVE_SPEED;
        currentFrames = &leftFrames;
        isMoving = true;
        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {      
        m_position.x += PLAYER_MOVE_SPEED;
        currentFrames = &rightFrames;
        isMoving = true;
       
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_position.y -= PLAYER_MOVE_SPEED;
        currentFrames = &upFrames;
        isMoving = true;
        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_position.y += PLAYER_MOVE_SPEED;
        currentFrames = &downFrames;
        isMoving = true;
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){


    }
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                shoot();
            }
        }
    }



  

    if (!isMoving) {
        currentFrames = &defaultFrames;
    }
}



void PlayerObject::animate(float deltaTime) 
{
    if (clock.getElapsedTime().asSeconds() > 0.1f) 
    {
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

bool PlayerObject::isInBush()
{
    return m_inBush;
}

void PlayerObject::setInBush(bool inBush)
{
    m_inBush = inBush;
}

void PlayerObject::shoot()
{
    sf::Vector2f start = m_flashlight.getShape().getPoint(0);
    sf::Vector2f vertex1 = m_flashlight.getShape().getPoint(1);
    sf::Vector2f vertex2 = m_flashlight.getShape().getPoint(2);

    for (int i = 0; i < 5; ++i) {
        float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        sf::Vector2f randomPoint = vertex1 + t * (vertex2 - vertex1);
        auto bullet = std::make_unique<BulletObject>(start);
        bullet->setTarget(randomPoint);
        m_bullets.push_back(std::move(bullet));
       
    } 
}


void PlayerObject::changeWeapon(std::unique_ptr<BaseWeaponObject> newWeapon)
{
    m_currentWeapon = std::move(newWeapon);
}


std::vector<std::unique_ptr<MovingObject>> PlayerObject::retrieveBullets()
{
    std::vector<std::unique_ptr<MovingObject>> bullets;
    bullets.swap(m_bullets); 
    return bullets;
}

