#include "block.h"

Block::Block(sf::Vector2f pos, sf::Vector2f size)
{
    this->position = pos;
    this->size = size;
    this->block.setPosition(position);
    this->block.setSize(size);
}

void Block::setColor(sf::Color color)
{
    this->color = color;
    this->block.setFillColor(color);
}

void Block::setSprite(sf::Sprite sprite)
{
    this->hasSprite = true;
    this->sprite = sprite;
    this->sprite.setPosition(this->position);
    this->sprite.setScale(this->size.x / sprite.getLocalBounds().width,
                    this->size.y / sprite.getLocalBounds().height
    );
}

void Block::draw(sf::RenderWindow &window)
{
    if(hasSprite)
        window.draw(sprite);
    else
        window.draw(block);
}

sf::Vector2f Block::getPosition()
{
    return sprite.getPosition();
}
