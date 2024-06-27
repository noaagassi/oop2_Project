#include "Objects.h/PortalObject.h"



bool PortalObject::m_registerit = FactoryObject::registerit(PORTAL_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PortalObject>(pos); });

PortalObject::PortalObject(const sf::Vector2f& initPosition)
    :StaticObject(initPosition) , m_ptr2portals(nullptr)
{
    setObjTexture(PORTAL_OBJ);
    setScale(0.05f, 0.05f);
}

PortalObject::PortalObject()
    :m_ptr2portals(nullptr)
{
    setObjTexture(PORTAL_OBJ);
}

void PortalObject::setPortals(std::shared_ptr<std::vector<std::shared_ptr<PortalObject>>> portals)
{
    m_ptr2portals = portals;
}

PortalObject& PortalObject::getRandomPortal()
{
    if (m_ptr2portals && !m_ptr2portals->empty())
    {
        
        size_t random_index = rand() % m_ptr2portals->size();

        if ((*m_ptr2portals)[random_index].get() == this)
        {
            random_index = (random_index + 1) % m_ptr2portals->size();
        }

        return dynamic_cast<PortalObject&>(*(*m_ptr2portals)[random_index]);
    }
}