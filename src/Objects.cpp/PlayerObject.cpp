
#include "Objects.h/PlayerObject.h"

//------------------------------------------------
//constant ans enum
const int PLAYER_SPRITE_WIDTH = 64;
const int PLAYER_SPRITE_HEIGHT = 96;
const int PLAYER_SPRITES_PER_ROW = 4;
const int PLAYER_SPRITES_PER_COLUMN = 4;
const float PLAYER_MOVE_SPEED = 0.1f;
//------------------------------------------------


bool PlayerObject::m_registerit = FactoryObject::registerit(PLAYER_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PlayerObject>(pos); });




PlayerObject::PlayerObject(const sf::Vector2f& initPosition)
    :MovingObject(initPosition)
{
    setObjTexture(PLAYER_OBJ);
    setScale(1.0f, 1.0f);

    defaultFrames = { getFrame(0, 0) };
    leftFrames = { getFrame(1, 0), getFrame(1, 1), getFrame(1, 2), getFrame(1, 3) };
    rightFrames = { getFrame(2, 0), getFrame(2, 1), getFrame(2, 2), getFrame(2, 3) };
    downFrames = { getFrame(0, 0), getFrame(0, 1), getFrame(0, 2), getFrame(0, 3) };
    upFrames = { getFrame(3, 0), getFrame(3, 1), getFrame(3, 2), getFrame(3, 3) };

    currentFrames = &defaultFrames;

    m_objectSprite.setTextureRect((*currentFrames)[0]);   //check

    m_x = 100.f;
    m_y = 100.f;

    spriteIndex = 0;
    isMoving = false;
}
//------------------------------------------------

void PlayerObject::update(float deltaTime, sf::RenderWindow& window)
{
    handleInput();
    animate(deltaTime);
    m_objectSprite.setPosition(m_x, m_y);


    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f characterPosition = m_objectSprite.getPosition();
    sf::Vector2f direction = sf::Vector2f(mousePosition) - characterPosition;
    m_flashlight.update(characterPosition, direction);

}
//------------------------------------------------

void PlayerObject::draw(sf::RenderWindow& window)
{
    window.draw(m_objectSprite);

    m_flashlight.draw(window);
}
//------------------------------------------------

sf::IntRect PlayerObject::getFrame(int row, int col)
{
    return sf::IntRect(col * PLAYER_SPRITE_WIDTH, row * PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT);
}
//------------------------------------------------

void PlayerObject::handleInput()
{
    isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_x -= PLAYER_MOVE_SPEED;
        currentFrames = &leftFrames;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_x += PLAYER_MOVE_SPEED;
        currentFrames = &rightFrames;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_y -= PLAYER_MOVE_SPEED;
        currentFrames = &upFrames;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_y += PLAYER_MOVE_SPEED;
        currentFrames = &downFrames;
        isMoving = true;
    }

    if (!isMoving) {
        currentFrames = &defaultFrames;
    }
}
//------------------------------------------------

void PlayerObject::animate(float deltaTime) {
    if (clock.getElapsedTime().asSeconds() > 0.1f) {
        spriteIndex = (spriteIndex + 1) % currentFrames->size();
        m_objectSprite.setTextureRect((*currentFrames)[spriteIndex]);
        clock.restart();
    }
}