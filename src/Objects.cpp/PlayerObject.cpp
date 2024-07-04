#pragma once
#include "Objects.h/PlayerObject.h"
#include "Objects.h/BulletObject.h"
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include <iostream>

//------------------------------------------------

//------------------------------------------------


bool PlayerObject::m_registerit = FactoryObject::registerit(PLAYER_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PlayerObject>(pos); });




PlayerObject::PlayerObject(const sf::Vector2f& initPosition)
    : MovingObject(initPosition),m_lives(initPosition.x-20,initPosition.y-10), m_eatLifeGift(false)
{
    setObjTexture(PLAYER_OBJ);
    setTheScale(PLAYER_WIDTH , PLAYER_HEIGHT);

    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    rightFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
    downFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
    upFrames = { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };
    
    currentFrames = &defaultFrames;
    m_objectSprite.setTextureRect((*currentFrames)[0]);
    
    m_weapons.push_back(std::make_unique<BallsWeaponObject>()); //index 0
    m_weapons.push_back(std::make_unique<RocketWeaponObject>()); //index 1
    m_weapons.push_back(std::make_unique<SuperWeaponObject>()); //index 2


    m_currentWeapon = m_weapons[0].get();

}
//------------------------------------------------

void PlayerObject::update(float deltaTime, sf::RenderWindow* window)
{
    m_numberForHeart++;
    if (m_numberForHeart % 100 == 0)
    {
        //m_lives.looseLive();
    }
    isAteLiveGift();
    handleInput(window);
    animate(deltaTime);
    m_objectSprite.setPosition(m_position);
    m_lifeTexture.setPosition(m_position.x, m_position.y + 40);
    updateFlashlight(window);
    sf::Vector2f pos4lives(m_position.x-20, m_position.y-10);
    m_lives.update(pos4lives);
    m_currentWeapon->update(deltaTime);
}
//------------------------------------------------

void PlayerObject::draw(sf::RenderWindow* window) const
{
    BaseObject::draw(window); 
    m_flashlight.draw(window);
    m_lives.draw(window);
}

//------------------------------------------------

void PlayerObject::changeHeart(bool updateLifes)
{
    if (updateLifes == LESS)
    {
        m_lifeTexture.setFillColor(sf::Color::Red);
    }
    else
    {
        m_lifeTexture.setFillColor(sf::Color::Blue);
    }
}
//------------------------------------------------
void PlayerObject::isAteLiveGift()
{
    if (m_eatLifeGift)
    {
        m_lives.addLive();
        m_eatLifeGift = false;
    }
}
//------------------------------------------------
sf::IntRect PlayerObject::getFrame(int row, int col)
{
    return sf::IntRect(col * PLAYER_SPRITE_WIDTH, row * PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
}
//-------------------------------------------------
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (m_rocketAviable  && !m_rocketFired) {
            changeWeapon(2); // Cambia al RocketWeaponObject
            shoot();
            m_rocketFired = true;
        }
    }
    else {
        m_rocketFired = false; // Reinicia la bandera cuando se suelta la tecla Space
    }
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                changeWeapon(0);
                shoot();
            }
        }
    }

    if (!isMoving) {
        currentFrames = &defaultFrames;
    }
}

//------------------------------------------------

void PlayerObject::animate(float deltaTime) 
{
    if (clock.getElapsedTime().asSeconds() > 0.1f) 
    {
        spriteIndex = (spriteIndex + 1) % currentFrames->size();
        m_objectSprite.setTextureRect((*currentFrames)[spriteIndex]);
        clock.restart();
    }
}

//------------------------------------------------
 
void PlayerObject:: updateFlashlight(sf::RenderWindow* window)
{
    sf::Vector2i mouseScreenPosition = sf::Mouse::getPosition(*window);
    sf::Vector2f mouseWorldPosition = window->mapPixelToCoords(mouseScreenPosition);

    sf::Vector2f direction = mouseWorldPosition - m_position;
    m_flashlight.update(m_position, direction);

}
//------------------------------------------------
bool PlayerObject::isInBush()
{
    return m_inBush;
}
//------------------------------------------------
void PlayerObject::setInBush(bool inBush)
{
    m_inBush = inBush;
}
//------------------------------------------------
void PlayerObject::shoot()
{
    m_currentWeapon->shoot(m_flashlight);
}

//------------------------------------------------
void PlayerObject::changeWeapon(int index)
{
    m_currentWeapon = m_weapons[index].get();
}
//------------------------------------------------

std::vector<std::unique_ptr<MovingObject>> PlayerObject::retrieveBullets()
{
    return m_currentWeapon->retrieveBullets();
    
}
void PlayerObject::weaponGift()
{
    m_currentWeapon->addBall();
}
//------------------------------------------------
void PlayerObject::ateLiveGift()
{
    m_eatLifeGift = true;
}

