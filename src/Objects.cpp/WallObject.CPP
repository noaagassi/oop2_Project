#include "Objects.h/WallObject.h"



bool WallObject::m_registerit = FactoryObject::registerit(WALL_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<WallObject>(pos); });

WallObject::WallObject(const sf::Vector2f& initPosition)
    :StaticObject(initPosition)
{
    setObjTexture(WALL_OBJ);
    setTheScale(0.05f, 0.05f);

}

WallObject::WallObject()
{
    setObjTexture(WALL_OBJ);
}
