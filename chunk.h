#pragma once
#ifndef CHUNK_H
#define CHUNK_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "block.h"
#include "game_object.h"

class Chunk
{
    private:
        std::vector<Block> blocks;
        std::vector<GameObject> objects;
    public:
        const int SIZE = 16;
        void addBlock(Block &block);
        void addObject(GameObject &obj);

        void draw(sf::RenderWindow &window);
        int getLen();
        Block getBlock(int index);
};

#endif
