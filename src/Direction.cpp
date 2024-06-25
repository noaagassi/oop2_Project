#include "Direction.h"

Direction opposite(Direction dir)
{
    switch (dir)
    {
    case Direction::Backward:
        return Direction::Forward;
    case Direction::Forward:
        return Direction::Backward;
    case Direction::Right:
        return Direction::Left;
    case Direction::Left:
        return Direction::Right;
    case Direction::Stay:
        return Direction::Stay;
    }
}

sf::Vector2f toVector(Direction dir)
{

    switch (dir)
    {
    case Direction::Backward:
        return { 0, -1 };
    case Direction::Forward:
        return { 0, 1 };
    case Direction::Right:
        return { 1, 0 };
    case Direction::Left:
        return { -1, 0 };
    case Direction::Stay:
        return { 0, 0 };
    }
}
