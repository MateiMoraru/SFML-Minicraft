#include "tree.h"
#include <SFML/Graphics.hpp>

Tree::Tree(sf::Vector2f position, sf::Vector2f size)
{
    this->position = position;
    this->size = size;
    this->treeComponents[3] = {
        Block::Block(position.x, position.y),
        Block::Block(position.x, position.y - size.y),
        Block::Block(position.x, position.y - size.y * 2),
    };
}


void Tree::draw(sf::RenderWindow &window)
{
    this->treeComponents[0].draw(window);
    this->treeComponents[1].draw(window);
    this->treeComponents[2].draw(window);
}
