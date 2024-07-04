#include "Objects.h/BombObject.h"

bool BombObject::m_registerit = FactoryObject::registerit(BOMB_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<BombObject>(pos); });



BombObject::BombObject(const sf::Vector2f& position)
    : BulletObject(position)
{
    setObjTexture(BOMB_OBJ);
    setTheScale(0.01f, 0.01f);
}

void BombObject::update(float deltatime, sf::RenderWindow* window)
{
    m_velocity = m_direction * 200.0f;
    m_objectSprite.move(m_velocity * deltatime);
}

void BombObject::draw(sf::RenderWindow* window) const
{
    window->draw(m_objectSprite);
}


