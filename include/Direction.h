#pragma once

#include <SFML/Graphics.hpp>

enum class Direction
{
    Backward,
    Forward,
    Right,
    Left,
    Stay
};

Direction opposite(Direction dir);
sf::Vector2f toVector(Direction dir);
