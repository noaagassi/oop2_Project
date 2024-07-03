#include "Board.h"
#include "CollisionHandling.h"
#include "Objects.h/BushObject.h"
#include "Objects.h/BaseGiftObject.h"
#include "Objects.h/BulletObject.h"
#include "Objects.h/TreeObject.h"
//----------------------------------------
Board::Board()
	:m_levelNum(1)
{
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
	float location_y = PLAY_WINDOW_HEIGHT;
	float location_x = 0.f;
	sf::Color pixelColor;
	image.loadFromFile(fileName);
	for (int x = 0; x<int(image.getSize().x); x++)
	{
		location_y = PLAY_WINDOW_HEIGHT - (PLAY_WINDOW_HEIGHT / MAP_HEIGHT);
		for (int y = int(image.getSize().y) -1 ; y >= 0; y--)
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
				
				
				m_staticObjects.push_back(std::move(portal));
				
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
			location_y -= PLAY_WINDOW_HEIGHT/MAP_HEIGHT;
		}
		location_x += PLAY_WINDOW_WIDTH/MAP_WIDTH;
	}
}






void Board::update(float deltatime, sf::RenderWindow* window)
{
	m_cloud.update(deltatime, window);
	for (auto &currentObj : m_movingObjects)
	{
		currentObj->update(deltatime, window);
		
	}

	auto playerBullets = getPlayer()->retrieveBullets();
	addBullets(std::move(playerBullets));

	checkCollisions();

}

void Board::draw(sf::RenderWindow* window)
{
	m_cloud.draw(window);
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
	const auto& PoisonVec = m_cloud.getPoisonVec();

	for (auto moving = m_movingObjects.begin(); moving != m_movingObjects.end();)
	{
		
		for (auto staticObj = m_staticObjects.begin(); staticObj != m_staticObjects.end(); )
		{
			if ((*moving)->isCollidingWith(**staticObj))
			{
				try
				{
					processCollision(**moving, **staticObj);
				}
				catch (const UnknownCollision& e)
				{
					std::cerr << e.what() << std::endl;
				}

				BaseGiftObject* gift = dynamic_cast<BaseGiftObject*>((*staticObj).get());

				if (gift && gift->toDelete())
				{
					staticObj = m_staticObjects.erase(staticObj);
				}
				else
				{
					++staticObj;
				}
			}
			else
			{
				if (auto player = dynamic_cast<PlayerObject*>((*moving).get()))
				{
					if (auto bush = dynamic_cast<BushObject*>((*staticObj).get()))
					{
						bush->resetColor();
					}
				}
				++staticObj;
			}
			
		}

		BulletObject* bullet = dynamic_cast<BulletObject*>((*moving).get());

		if (bullet && bullet->toDelete())
		{
			moving = m_movingObjects.erase(moving);
		}
		else
		{
			++moving;
		}

		//check if the player is in the poison area
		if (auto player= dynamic_cast<PlayerObject*>((*moving).get()))
		{
			if (playerIsHittingPoison(player->getPosition()))
			{
				SoundsHandler::getInstance().playSound(Sound_Id::POISON_HIT);
			}
		}


	}

	
	//for (size_t i = 0; i < m_movingObjects.size(); ++i)
	//{
	//	//moving with moving
	//	for (size_t j = i + 1; j < m_movingObjects.size(); ++j)
	//	{
	//		if (m_movingObjects[i]->isCollidingWith(*m_movingObjects[j]))
	//		{
	//			try
	//			{
	//				processCollision(*m_movingObjects[i], *m_movingObjects[j]);
	//			}
	//			catch (const UnknownCollision& e)
	//			{
	//				std::cerr << e.what() << std::endl;
	//			}
	//		}
	//	}
	//	//moving with poison
	//	for (size_t k = 0; k < PoisonVec.size(); k++)
	//	{
	//		if (m_movingObjects[i]->isCollidingWith(*PoisonVec[k]))
	//		{
	//			try
	//			{
	//				processCollision(*m_movingObjects[i], *PoisonVec[k]);
	//			}
	//			catch (const UnknownCollision& e)
	//			{
	//				std::cerr << e.what() << std::endl;
	//			}
	//		}
	//	}
	//}


}


PlayerObject* Board::getPlayer() const
{
	for (const auto& obj : m_movingObjects)
	{
		PlayerObject* player = dynamic_cast<PlayerObject*>(obj.get());

		if (player != nullptr)
		{
			return player;
		}
	}
	return nullptr;
}

sf::FloatRect Board::getPlayerBounds() const
{
	return getPlayer()->getSpriteBounds();
}

sf::Vector2f Board::getPlayrLocation() const
{
	return getPlayer()->getPosition();
}

void Board::handleMousePressed(sf::Event event)
{
}

void Board::handleKeyPress(sf::Keyboard::Key key)
{
}

bool Board::playerIsHittingPoison(sf::Vector2f playerPosition)
{
	
	/*if (playerPosition.x > BOTTOM_RIGHT_POISON.x ||
		playerPosition.x < TOP_LEFT_POISON.x ||
		playerPosition.y >BOTTOM_RIGHT_POISON.y ||
		playerPosition.y < TOP_LEFT_POISON.y)
	{
		return true;
	}*/
	return false;
}

void Board::addBullets(std::vector<std::unique_ptr<MovingObject>> bullets)
{
	for (auto& bullet : bullets) {
		m_movingObjects.push_back(std::move(bullet));
	}
}

