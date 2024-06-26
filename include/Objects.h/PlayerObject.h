#pragma once

#include "Objects.h/MovingObject.h"
#include "FactoryObject.h"
#include "FlashlightObject.h"
#include "Direction.h"
#include "Animation.h"

class PlayerObject : public MovingObject
{
public:
    //c-tor
    PlayerObject(const sf::Vector2f& pos);

    void update(float deltaTime, sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);
    void move(float deltaTime);


private:
    //Animation m_animation;
    //AnimationData initAnimationData();

    //Direction m_dir = Direction::Stay;
    //Animation m_animation;

    static bool m_registerit;
    //member of the texture of the player
    int spriteIndex;
    bool isMoving;

    sf::Clock clock;
    FlashlightObject m_flashlight;

    /*std::vector<sf::IntRect> defaultFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect>* currentFrames;

    sf::IntRect getFrame(int row, int col);
    void handleInput();
    void animate(float deltaTime);
    };