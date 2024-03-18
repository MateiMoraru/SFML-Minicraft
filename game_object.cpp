#include <SFML/Graphics.hpp>
#include "game_object.h"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f size)
{
    this->position = position;
    this->size = size;
}