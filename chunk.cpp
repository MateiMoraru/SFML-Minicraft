#include "chunk.h"
#include "game_object.h"

void Chunk::addBlock(Block &block)
{
    blocks.push_back(block);
}

void Chunk::addObject(GameObject &obj)
{
    objects.push_back(obj);
}

void Chunk::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < blocks.size(); i++)
    {
        blocks[i].draw(window);
    }
}

int Chunk::getLen()
{
    return blocks.size();
}

Block Chunk::getBlock(int index)
{
    return blocks[index];
}

