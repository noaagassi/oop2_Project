#include "Objects.h/FreezeGiftObject.h"


//------------------------------------------------------------------
bool FreezeGiftObject::m_registerit = FactoryObject::registerit(FREEZE_GIFT_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<FreezeGiftObject>(pos); });
//------------------------------------------------------------------
FreezeGiftObject::FreezeGiftObject(const sf::Vector2f& initPosition)
    :BaseGiftObject(initPosition), m_isFreeze(false)
{
    setTheScale(FREEZE_GIFT_OBJ);
    setObjTexture(FREEZE_GIFT_OBJ);
}
//------------------------------------------------------------------
FreezeGiftObject::FreezeGiftObject()
{
    setObjTexture(FREEZE_GIFT_OBJ);
}
//------------------------------------------------------------------