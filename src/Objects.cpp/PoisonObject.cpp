#include "Objects.h/PoisonObject.h"

PoisonObject::PoisonObject(const sf::Vector2f& initPosition)
	:BaseObject(initPosition)
{
	setObjTexture(POISON_OBJ);
	setTheScale(0.04f, 0.04f);
}

void PoisonObject::draw(sf::RenderWindow* window)
{
	window->draw(m_objectSprite);
}
