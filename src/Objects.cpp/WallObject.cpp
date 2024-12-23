#include "Objects.h/WallObject.h"



bool WallObject::m_registerit = FactoryObject::registerit(WALL_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<WallObject>(pos); });

WallObject::WallObject(const sf::Vector2f& initPosition)
    :StaticObject(initPosition)
{
    setTheScale(WALL_OBJ);
    setObjTexture(WALL_OBJ);

}

WallObject::WallObject()
{
    setObjTexture(WALL_OBJ);
}
