#include "Board.h"
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
void Board::handleKeyPress(sf::Keyboard::Key key)
{
	for (const auto& currentObject : m_movingObjects) 
	{
		if (auto player = dynamic_cast<PlayerObject*>(currentObject.get())) 
		{
			//player->handleInput(key);
		}
	}
}
//----------------------------------------

void Board::readLevel()
{
	std::string fileName = updateNameLevel(m_levelNum);

	readObject(fileName);
	m_levelNum++;
}
//----------------------------------------
std::string Board::updateNameLevel(int number)
{
	return "level" + std::to_string(number) + ".png";
}

//----------------------------------------
void Board::readObject(std::string fileName)
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

			if (pixelColor == sf::Color(163, 73, 164))   //purple color
			{
				sf::Vector2f position(location_x,location_y);
				auto player = FactoryObject::createMoving(PLAYER_OBJ, position);
				m_movingObjects.push_back(std::move(player));
			}
			if (pixelColor == sf::Color(34, 177, 76))      //green color
			{
				sf::Vector2f position(location_x, location_y);
				auto tree = FactoryObject::createStatic(TREES_OBJ, position);
			}
			location_y -= 28.f;
		}
		location_x += 40.f;
	}
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
