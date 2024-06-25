#include "Animation.h"


const auto AnimationTime = sf::seconds(0.3f);


Animation::Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite)
    :
{
}

void Animation::direction(Direction dir)
{
    if (m_dir == dir || dir == Direction::Stay)
    {
        return;
    }

    m_dir = dir;
    update();
}

void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++ m_numOfRect;
        m_numOfRect %= m_data.m_data.find(m_dir)->second.size();
        update();
    }
}

void Animation::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_numOfRect]);
}
