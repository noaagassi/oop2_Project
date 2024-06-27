#include "Objects.h/PortalObject.h"
#include <iostream>


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
        // Encontrar el índice del portal actual en el vector
        auto it = std::find_if(m_ptr2portals->begin(), m_ptr2portals->end(),
            [this](const std::shared_ptr<PortalObject>& portal) {
                return portal.get() == this;
            });

        if (it != m_ptr2portals->end())
        {
            // Obtener el índice actual
            size_t current_index = std::distance(m_ptr2portals->begin(), it);

            // Generar un índice aleatorio diferente al actual
            size_t random_index;
            do {
                random_index = rand() % m_ptr2portals->size();
            } while (random_index == current_index);

            // Retornar el portal en el índice aleatorio
            return *m_ptr2portals->at(random_index);
        }
        else
        {
            throw std::logic_error("Current portal not found in m_ptr2portals");
        }
    }

    throw std::logic_error("m_ptr2portals is not initialized or empty.");
}