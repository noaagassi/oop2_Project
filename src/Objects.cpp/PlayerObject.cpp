#include "Objects.h/PlayerObject.h"

//------------------------------------------------
//constant ans enum
const float PLAYER_MOVE_SPEED = 0.1f;
//------------------------------------------------



bool PlayerObject::m_registerit = FactoryObject::registerit(PLAYER_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PlayerObject>(pos); });



PlayerObject::PlayerObject(const sf::Vector2f& initPosition)
    :MovingObject(initPosition),m_animation()
{
    setObjTexture(PLAYER_OBJ);












  /*  setScale(1.0f, 1.0f);

    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    rightFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
    downFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
    upFrames = { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };

    currentFrames = &defaultFrames;
    m_objectSprite.setTextureRect((*currentFrames)[0]);

    m_x = 100.f;
    m_y = 100.f;*/
}
void PlayerObject::update(sf::Time delta)
{
    
}
AnimationData PlayerObject::initAnimationData()
{
    const auto size = sf::Vector2i(40, 40);
    const auto initSpace = sf::Vector2i(851, 2);
    const auto middleSpace = sf::Vector2i(0, 10);

    auto player = AnimationData{};
    auto currentStart = initSpace;



}
//------------------------------------------------
//
//void PlayerObject::update(float deltaTime, sf::RenderWindow& window)
//{
//    animate(deltaTime);
//    m_objectSprite.setPosition(m_x, m_y);
//
//    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//    sf::Vector2f characterPosition = m_objectSprite.getPosition();
//    sf::Vector2f direction = sf::Vector2f(mousePosition) - characterPosition;
//    m_flashlight.update(characterPosition, direction);
//}
////------------------------------------------------
//
//
//
//void PlayerObject::draw(sf::RenderWindow *window) {
//    MovingObject::draw(window);
//    m_flashlight.draw(window);
//}
//void PlayerObject::move(float deltaTime)
//{
//}
////------------------------------------------------
//
////------------------------------------------------
//
//void PlayerObject::handleInput(sf::Keyboard::Key key)
//{
//    isMoving = false;
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//        m_x -= PLAYER_MOVE_SPEED;
//        currentFrames = &leftFrames;
//        isMoving = true;
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//        m_x += PLAYER_MOVE_SPEED;
//        currentFrames = &rightFrames;
//        isMoving = true;
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//        m_y -= PLAYER_MOVE_SPEED;
//        currentFrames = &upFrames;
//        isMoving = true;
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//        m_y += PLAYER_MOVE_SPEED;
//        currentFrames = &downFrames;
//        isMoving = true;
//    }
//
//    if (!isMoving) {
//        currentFrames = &defaultFrames;
//    }
//}
//
//
//
//
