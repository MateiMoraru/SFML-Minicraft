#include <iostream>
#include <SFML/Graphics.hpp>
#include "spritesheet.h"
#include "environment.h"
#include "chunk.h"
#include "tree.h"

Environment::Environment(int WIDTH, int HEIGHT, int SPRITE_SIZE)
{
    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    this->SPRITE_SIZE = SPRITE_SIZE;
};

void Environment::setSpritesheet(Spritesheet &sp)
{
    this->spritesheet = sp;
}

void Environment::generateChunk(int startX, int startY)
{   
   Chunk currentChunk = Chunk();
 
   for(int x = startX; x < startX + currentChunk.SIZE * SPRITE_SIZE; x += SPRITE_SIZE)
   {
       for(int y = startY; y < startY + currentChunk.SIZE * SPRITE_SIZE; y += SPRITE_SIZE)
       {
            Block block = Block(sf::Vector2f(x, y), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
            block.setSprite(spritesheet.getSprite(0));
            currentChunk.addBlock(block);
            if(x > 300 && x < 400 && y > 300 && y < 400)
            {
                Tree tree = Tree(sf::Vector2f(x, y), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
                currentChunk.addObject(tree);
            
            }
       }
   }
 
   this->worldChunks.push_back(currentChunk);
}

void Environment::generateWorldChunks()
{
    for(int i = 0; i < WIDTH; i += 16 * SPRITE_SIZE)
    {
        for(int j = 0; j < HEIGHT; j += 16 * SPRITE_SIZE)
        {
            generateChunk(i, j);
         }
    }

}

void Environment::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < this->worldChunks.size(); i++)
    {
        this->worldChunks[i].draw(window);
    }
}
