#include "Objects.h/TreeObject.h"



bool TreeObject::m_registerit = FactoryObject::registerit(TREES_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<TreeObject>(pos); });

TreeObject::TreeObject(const sf::Vector2f& initPosition)
    :StaticObject(initPosition)
{
    setObjTexture(TREES_OBJ);
    //setTheScale(0.005f, 0.005f);
    setTheScale(TREES_OBJ);
}

TreeObject::TreeObject()
{
    setObjTexture(TREES_OBJ);
}

