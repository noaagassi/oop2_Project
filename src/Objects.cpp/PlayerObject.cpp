#include "Objects.h/PlayerObject.h"

//------------------------------------------------
//constant ans enum
const float PLAYER_MOVE_SPEED = 0.1f;
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
    

}
sf::Vector2u PlayerObject::getSpriteSheetDivision()
{
    sf::Vector2u sizeOfSprite = m_objectSprite.getTexture()->getSize();
    sizeOfSprite.x /= 4;
    sizeOfSprite.y /= 4;

    return sizeOfSprite;
}
/*
void PlayerObject::update(sf::Time delta)
{
    if (m_dir == Direction::Stay)
    {
        return;
    }
    m_objectSprite.move(toVector(m_dir) * delta.asSeconds() * PLAYER_MOVE_SPEED);
    m_animation.update(delta);
}*/
//-------------------------------------------------
void PlayerObject::draw(sf::RenderWindow* window)
{
    window->draw(m_objectSprite);
}

void PlayerObject::move(float deltaTime)
{
}
//-------------------------------------------------
//void PlayerObject::direction(sf::Keyboard::Key key)
//{
//    if (key == sf::Keyboard::W)
//    {
//        m_animation.direction(Direction::Forward);
//    }
//    else if (key == sf::Keyboard::A)
//    {
//        m_animation.direction(Direction::Left);
//    }
//    else if (key == sf::Keyboard::S)
//    {
//        m_animation.direction(Direction::Backward);
//    }
//    else if (key == sf::Keyboard::D)
//    {
//        m_animation.direction(Direction::Right);
//    }
//}
//void PlayerObject::move(float deltaTime)
//{
//}
////-------------------------------------------------
//AnimationData PlayerObject::initAnimationData()
//{
//    const auto size = sf::Vector2i(64, 96); 
//    const auto initSpace = sf::Vector2i(0, 0); 
//
//    auto player = AnimationData{};
//    auto currentStart = initSpace;
//
//    auto nextStart = [&](int row) {
//        currentStart.x = 0;
//        currentStart.y = row * size.y;
//        return currentStart;
//        };
//
//    for (int row = 0; row < 4; ++row)
//    {
//        for (int col = 0; col < 4; ++col)
//        {
//            auto rect = sf::IntRect(currentStart.x + col * size.x,
//                currentStart.y,
//                size.x,
//                size.y);
//            switch (row) 
//            {
//            case 0:
//                player.m_data[Direction::Forward].emplace_back(rect);
//                break;
//            case 1:
//                player.m_data[Direction::Left].emplace_back(rect);
//                break;
//            case 2:
//                player.m_data[Direction::Right].emplace_back(rect);
//                break;
//            case 3:
//                player.m_data[Direction::Backward].emplace_back(rect);
//                break;
//            }
//        }
//        nextStart(row + 1);
//    }
//
//    return player;
//}
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
