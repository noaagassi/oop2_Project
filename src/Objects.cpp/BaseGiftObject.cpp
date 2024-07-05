#include "Objects.h/BaseGiftObject.h"




BaseGiftObject::BaseGiftObject(const sf::Vector2f& initPosition)
	:StaticObject(initPosition)
{
}

BaseGiftObject::BaseGiftObject()
{
}

bool BaseGiftObject::toDelete()
{
	return m_toDelete;
}

void BaseGiftObject::toDelete(bool toDelete)
{
	m_toDelete = toDelete;
}
