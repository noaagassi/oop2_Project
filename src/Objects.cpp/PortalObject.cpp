#include "Objects.h/PortalObject.h"



bool PortalObject::m_registerit = FactoryObject::registerit(PORTAL_OBJ,
    [](const sf::Vector2f& pos) -> std::unique_ptr<BaseObject> {return std::make_unique<PortalObject>(pos); });

PortalObject::PortalObject(const sf::Vector2f& initPosition)
    :StaticObject(initPosition) , m_ptr2portals(nullptr)
{
    setTheScale(PORTAL_OBJ);
    setObjTexture(PORTAL_OBJ);
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
        // Obtener un índice aleatorio dentro del rango válido
        size_t current_index = 0;
        for (size_t i = 0; i < m_ptr2portals->size(); ++i)
        {
            if ((*m_ptr2portals)[i].get() == this)
            {
                current_index = i;
                break;
            }
        }

        size_t random_index = current_index;
        do {
            random_index = (random_index + 1) % m_ptr2portals->size();
        } while (random_index == current_index);

        return dynamic_cast<PortalObject&>(*(*m_ptr2portals)[random_index]);
    }

    // En caso de que m_ptr2portals no esté inicializado o esté vacío,
    // deberías manejar esta situación según lo que sea apropiado para tu juego.
    // Puedes lanzar una excepción, retornar un portal por defecto, etc.
    throw std::logic_error("m_ptr2portals is not initialized or empty.");
}