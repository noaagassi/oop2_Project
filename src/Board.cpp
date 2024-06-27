#include "Board.h"
#include "CollisionHandling.h"
//----------------------------------------
Board::Board()
	:m_levelNum(1)
{
	/*m_colorsCodes[sf::Color(34, 177, 76)] = COLOR_OF_OBJECT::GREEN;
	m_colorsCodes[sf::Color(181, 230, 29)] = COLOR_OF_OBJECT::LIGHT_GREEN;
	m_colorsCodes[sf::Color(163, 73, 164)] = COLOR_OF_OBJECT::PURPLE;
	m_colorsCodes[sf::Color(185, 122, 87)] = COLOR_OF_OBJECT::BROWN;
	m_colorsCodes[sf::Color(63, 72, 204)] = COLOR_OF_OBJECT::BLUE;*/

	readLevel();
}
//----------------------------------------
Board::~Board()
{
}



//----------------------------------------

void Board::readLevel()
{
	std::string fileName = updateNameLevel(m_levelNum);

	readMap(fileName);
	m_levelNum++;
}
//----------------------------------------
std::string Board::updateNameLevel(int number)
{
	return "level" + std::to_string(number) + ".png";
}

//----------------------------------------
void Board::readMap(std::string fileName)
{
	auto image = sf::Image();
	float location_y = 700.f;
	float location_x = 0.f;
	sf::Color pixelColor;
	image.loadFromFile(fileName);
	for (int x = 0; x<int(image.getSize().x); x++)
	{
		location_y = 700.f;
		for (int y = int(image.getSize().y) - 1; y >= 0; y--)
		{
	
			pixelColor = image.getPixel(x, y);

			if (pixelColor == sf::Color(163, 73, 164))   //purple color	player
			{
				sf::Vector2f position(location_x,location_y);
				auto player = FactoryObject::createMoving(PLAYER_OBJ, position);
				m_movingObjects.push_back(std::move(player));
			}
			else if (pixelColor == sf::Color(34, 177, 76))      //green color trees
			{
				sf::Vector2f position(location_x, location_y);
				auto tree = FactoryObject::createStatic(TREES_OBJ, position);
				m_staticObjects.push_back(std::move(tree));
			}
			else if (pixelColor == sf::Color(185,122, 87))      //brown color for wall
			{
				sf::Vector2f position(location_x, location_y);
				auto wall = FactoryObject::createStatic(WALL_OBJ, position);
				m_staticObjects.push_back(std::move(wall));
			}
			else if (pixelColor == sf::Color(0, 162,232))      //blue color for portal
			{
				sf::Vector2f position(location_x, location_y);
				auto portal = FactoryObject::createStatic(PORTAL_OBJ, position);
				
				

				auto sharedPortal = std::shared_ptr<PortalObject>(dynamic_cast<PortalObject*>(portal.get()));
				m_staticObjects.push_back(std::move(portal));
				m_portals.push_back(sharedPortal);

				// Configurar el puntero al vector de portales en PortalObject
				sharedPortal->setPortals(std::make_shared<std::vector<std::shared_ptr<PortalObject>>>(m_portals));


				
			}
			else if (pixelColor == sf::Color(181, 230, 29))      //light green color for bush
			{
				sf::Vector2f position(location_x, location_y);
				auto bush = FactoryObject::createStatic(BUSH_OBJ, position);
				m_staticObjects.push_back(std::move(bush));
			}
			else if (pixelColor == sf::Color(237, 28, 36))      //red color for life gift
			{
				sf::Vector2f position(location_x, location_y);
				auto lifeGift = FactoryObject::createStatic(LIFE_GIFT_OBJ, position);
				m_staticObjects.push_back(std::move(lifeGift));
			}
			else if (pixelColor == sf::Color(153, 217, 234))      //light blue color for freeze gift
			{
				sf::Vector2f position(location_x, location_y);
				auto freezeGift = FactoryObject::createStatic(FREEZE_GIFT_OBJ, position);
				m_staticObjects.push_back(std::move(freezeGift));
			}
			else if (pixelColor == sf::Color(127, 127, 127))      //dark grey color for weapon gift
			{
				sf::Vector2f position(location_x, location_y);
				auto weaponGift = FactoryObject::createStatic(WEAPON_GIFT_OBJ, position);
				m_staticObjects.push_back(std::move(weaponGift));
			}
			else if (pixelColor == sf::Color(255, 242, 0))      //dark yellow color for small fast enemy
			{
				sf::Vector2f position(location_x, location_y);
				auto smallFastEnemy = FactoryObject::createMoving(ENEMY_1_OBJ, position);
				m_movingObjects.push_back(std::move(smallFastEnemy));
			}
			else if (pixelColor == sf::Color(255, 127, 39))      //dark orange color for big slow enemy 
			{
				sf::Vector2f position(location_x, location_y);
				auto bigSlowEnemy= FactoryObject::createMoving(ENEMY_2_OBJ, position);
				m_movingObjects.push_back(std::move(bigSlowEnemy));
			}
			else if (pixelColor == sf::Color(0, 0, 0))      //black color for poison
			{
				sf::Vector2f position(location_x, location_y);
				auto poison = FactoryObject::createStatic(POISON_OBJ, position);
				m_staticObjects.push_back(std::move(poison));
			}
			location_y -= 28.f;
		}
		location_x += 40.f;
	}
}



void Board::update(float deltatime, sf::RenderWindow* window)
{
	
	for (auto &currentObj : m_movingObjects)
	{
		currentObj->update(deltatime, window);
	}

	checkCollisions();

}






void Board::draw(sf::RenderWindow* window)
{
	for (const auto& currentObject : m_movingObjects)
	{
		currentObject->draw(window);
	}
	for (const auto& currentObject : m_staticObjects)
	{
		currentObject->draw(window);
	}
}

void Board::checkCollisions()
{
	for (auto& moving : m_movingObjects)
	{
		for (auto& staticObj : m_staticObjects)
		{
			if (moving->isCollidingWith(*staticObj))
			{
				try
				{
					processCollision(*moving, *staticObj);
				}
				catch (const UnknownCollision& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}
	}

	// Verificar colisiones entre los propios objetos móviles
	for (size_t i = 0; i < m_movingObjects.size(); ++i)
	{
		for (size_t j = i + 1; j < m_movingObjects.size(); ++j)
		{
			if (m_movingObjects[i]->isCollidingWith(*m_movingObjects[j]))
			{
				try
				{
					processCollision(*m_movingObjects[i], *m_movingObjects[j]);
				}
				catch (const UnknownCollision& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}
	}
}

void Board::handleMousePressed(sf::Event event)
{
}

void Board::handleKeyPress(sf::Keyboard::Key key)
{
	switch (key){
	case sf::Keyboard::D:
		
		break;
	default:
		break;
	}
}

