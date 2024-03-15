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
        Block(sf::Vector2f pos, sf::Vector2f s)
        {
            position = pos;
            size = s; 
            block.setPosition(pos.x, pos.y);
            block.setSize(size);
        }

        void setColor(sf::Color new_color)
        {
            block.setFillColor(new_color);
            color = new_color;
        }

        void setSprite(sf::Sprite new_sprite)
        {
            hasSprite = true;
            sprite = new_sprite; 
            sprite.setPosition(position);
            sprite.setScale(size.x / sprite.getLocalBounds().width,
                            size.y / sprite.getLocalBounds().height
            );
        }

        void draw(sf::RenderWindow &window)
        {
            if(!hasSprite)
                window.draw(block);
            else
                window.draw(sprite);
        }
};

#endif
