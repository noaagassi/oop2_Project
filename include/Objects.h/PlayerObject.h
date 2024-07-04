#pragma once

#include <SFML/Graphics.hpp>
#include "Objects.h/MovingObject.h"
#include "FactoryObject.h"
#include "FlashlightObject.h"
#include "PlayerLives.h"
#include "PlayerWeaponObject.h"
#include "BallsWeaponObject.h"
#include "RocketWeaponObject.h"
#include "SuperWeaponObject.h"
#include "BaseWeaponObject.h"
#include "SoundsHandler.h"

class PlayerObject : public MovingObject
{
public:
    //c-tor
    PlayerObject(const sf::Vector2f& pos);


    void update(float deltaTime, sf::RenderWindow* window);
    void draw(sf::RenderWindow* window) const override;
    void handleInput(sf::RenderWindow*);
    void updateFlashlight(sf::RenderWindow* window);
    bool isInBush();
    void setInBush(bool);
    void shoot();
    void changeWeapon(int index);
    std::vector<std::unique_ptr<MovingObject>> retrieveBullets();
    void weaponGift();
    //
    void ateLiveGift();
private:
    //member of the texture of the player
    int spriteIndex;
    bool isMoving;
    bool m_inBush;


    sf::Clock clock;
    //memebrs for accessories
    sf::RectangleShape m_lifeTexture;
    FlashlightObject m_flashlight;
    PlayerWeaponObject* m_currentWeapon;
    std::vector<std::unique_ptr<PlayerWeaponObject>> m_weapons;
    SuperWeaponObject m_superWeapon;
    

    PlayerLives m_lives;
    //function for the hearts
    void changeHeart(bool);
    int m_numberForHeart;
    void isAteLiveGift();
    bool m_eatLifeGift;


    bool m_rocketAviable = true;
    bool m_rocketFired = false;

    sf::IntRect getFrame(int row, int col);
    void animate(float deltaTime);
    static bool m_registerit;
};