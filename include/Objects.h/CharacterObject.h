#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "BaseObject.h"
#include "FactoryObject.h"
#include "Utilities.h"
#include "BaseWeaponObject.h"

class CharacterObject : public MovingObject
{
public:
    CharacterObject(const sf::Vector2f& initPosition);
    //CharacterObject();
    virtual void update(float deltatime, sf::RenderWindow* window) = 0;
   /* void goLeft();
    void goRight();
    void goUp();
    void goDown();*/
    void animate(float deltaTime);
   //std::vector<std::unique_ptr<MovingObject>> retrieveBullets();
    //bool toDelete();
protected:
    std::vector<sf::IntRect> defaultFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect>* currentFrames;
    //std::unique_ptr<BaseWeaponObject> m_currentWeapon;
    float m_speed;
    bool m_isMoving;
    sf::Vector2f m_direction;
    bool m_toDelete = false;

};