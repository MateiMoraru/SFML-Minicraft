#ifndef TREE_H
#define TREE_H
#include "game_object.h"
#include "block.h"

class Tree : public GameObject
{
    private:
        Block treeComponents[3];
    public:
        Tree::GameObject(sf::Vector2f position, sf::Vector2f size);
        void draw(sf::RenderWindow &window);
};

#endif
