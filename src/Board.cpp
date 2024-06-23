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

void Board::readLevel()
{
	std::string fileName = updateNameLevel(m_levelNum);
	readFile(fileName);

	readObject();
	m_levelNum++;
}
//----------------------------------------
std::string Board::updateNameLevel(int number)
{
	return "level" + std::to_string(number) + ".png";
}
//----------------------------------------
void Board::readFile(std::string& fileName)
{
	m_file.open(fileName);

	if (!m_file.is_open())
	{
		//handle 
		std::cout << "handle" << std::endl;
	}
}

//----------------------------------------
void Board::readObject()
{
	auto image = sf::Image();
	float location_y = 500.f;

	image.loadFromFile("level1.png");
	sf::Sprite sprite;

	for (int y = int(image.getSize().y) - 1; y >= 0; y--)
	{
		float location_x = 0.f;

		for (int x = 0; x<int(image.getSize().x); x++)
		{
			sf::Color pixelColor = image.getPixel(x, y);

			if (pixelColor == sf::Color(163, 73, 164))
			{
				sf::Vector2f position(location_x, location_y);
				auto player = FactoryObject::create(PLAYER_OBJ, position);
			}
			if (pixelColor == sf::Color(34, 177, 76))
			{
				sf::Vector2f position(location_x, location_y);
				auto player = FactoryObject::create(PLAYER_OBJ, position);
			}
		}
		location_x += 10.f;
	}
	location_y -= 90.f;
}