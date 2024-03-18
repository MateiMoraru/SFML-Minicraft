#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SFML/Graphics.hpp>

class GameObject
{
    private:
        sf::Vector2f position;
        sf::Vector2f size;
    public:
        GameObject(sf::Vector2f position, sf::Vector2f size);

};

#endif