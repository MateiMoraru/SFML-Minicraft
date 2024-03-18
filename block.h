#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Graphics.hpp>

class Block
{
    private:
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color color;
        sf::RectangleShape block;
        sf::Sprite sprite;
        bool hasSprite = false;
    public:
        Block(sf::Vector2f pos, sf::Vector2f s);
        void setColor(sf::Color new_color);
        void setSprite(sf::Sprite new_sprite);
        void draw(sf::RenderWindow &window);
        sf::Vector2f getPosition();
};

#endif
