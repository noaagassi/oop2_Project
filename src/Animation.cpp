#include "Animation.h"





//
//const auto AnimationTime = sf::seconds(0.3f);
//
//Animation& Animation::operator=(const Animation& other)
//{
//    if (this != &other)
//    {
//        this->m_data = other.m_data;
//        this->m_dir = other.m_dir;
//        this->m_sprite = other.m_sprite;
//    }
//    return *this;
//}
//
//
//Animation::Animation::Animation()
//    :m_data(), m_dir(), m_sprite(), m_numOfRect(), m_elapsed()
//{
//}
//
//Animation::Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite)
//    :m_data(data),m_dir(dir),m_sprite(sprite),m_numOfRect(0), m_elapsed(sf::Time::Zero)
//{
//}
//
//
//
//void Animation::direction(Direction dir)
//{
//    if (m_dir == dir || dir == Direction::Stay)
//    {
//        return;
//    }
//
//    m_dir = dir;
//    update();
//}
//
//void Animation::update(sf::Time delta)
//{
//    m_elapsed += delta;
//    if (m_elapsed >= AnimationTime)
//    {
//        m_elapsed -= AnimationTime;
//        ++ m_numOfRect;
//        m_numOfRect %= m_data.m_data.find(m_dir)->second.size();
//        update();
//    }
//}
//
//void Animation::update()
//{
//    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_numOfRect]);
//}

Animation::Animation(/*sf::Texture* texture*/ sf::Sprite* sprite, sf::Vector2u imageCount, float switchTime)
{
	this->m_imageCount = imageCount;
	this->m_switchTime = switchTime;
	m_totalTime = 0.0f;
	m_currentImage.x = 0;
	/*
	uvrect.width = sprite->getSize().x / float(m_imageCount.x);
	uvrect.height = sprite->getSize().y / float(m_imageCount.y);*/
}

void Animation::update(int row, float deltaTime)
{
	m_currentImage.y = row;
	m_totalTime += deltaTime;
	
	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;
		if (m_currentImage.x >= m_imageCount.x)
		{
			m_currentImage.x = 0;
		}
	}
	uvrect.left = m_currentImage.x * uvrect.width;
	uvrect.top = m_currentImage.y * uvrect.height;
}
