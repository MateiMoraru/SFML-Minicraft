#ifndef ENVIRONMENT_H
#define ENVIRONMENT_h
#include "chunk.h"

class Environment
{
    private:
        std::vector<Chunk> worldChunks;
        int WIDTH, HEIGHT, SPRITE_SIZE;
        Spritesheet spritesheet;
    public:
        Environment(int WIDTH, int HEIGHT, int SPRITE_SIZE);

        void setSpritesheet(Spritesheet &sprites);
        void generateChunk(int startX, int startY);
        void generateWorldChunks();
        void draw(sf::RenderWindow &window);
};

#endif
