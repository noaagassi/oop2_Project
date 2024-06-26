#include "Objects.h/PoisonObject.h"


//--------------------------------------------------------------------------
bool PoisonObject::m_registerit = FactoryObject::registerit(POISON_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PoisonObject>(pos); });

//--------------------------------------------------------------------------
PoisonObject::PoisonObject(const sf::Vector2f& initPosition)
{
    setObjTexture(POISON_OBJ);
}
//--------------------------------------------------------------------------
void PoisonObject::update(const sf::Time elapceTime)
{
    if (m_checkTime >= elapceTime)
    {
        m_PoisenFrame++;
        ExpandPoisen();
        m_checkTime -= elapceTime;
    }
}
//--------------------------------------------------------------------------
std::vector<PoisonObject> PoisonObject::getPoisonVec()
{
    return m_Poisons;
}
//--------------------------------------------------------------------------
void PoisonObject::ExpandPoisen()
{

}
//--------------------------------------------------------------------------
