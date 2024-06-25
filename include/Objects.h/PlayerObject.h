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
    
    void update(sf::Time delta);
    void draw(sf::RenderWindow* window);
    void direction(sf::Keyboard::Key key);
    //void move(float deltaTime);

private:

    AnimationData initAnimationData();

    Direction m_dir = Direction::Stay;
    Animation m_animation;

    static bool m_registerit;
    //member of the texture of the player

    //FlashlightObject m_flashlight;

    /*std::vector<sf::IntRect> defaultFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect>* currentFrames;*/

    //sf::IntRect getFrame(int row, int col);
    //void handleInput(sf::Keyboard::Key key);
   // void animate(float deltaTime);
    
};
