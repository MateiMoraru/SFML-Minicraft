#include "chunk.h"

class Environment
{
    private:
        std::vector<Chunk> worldChunks;
        int WIDTH, HEIGHT, SPRITE_SIZE;
        Spritesheet spritesheet;
    public:
        Environment(int w, int h, int size)
        {
            WIDTH = w;
            HEIGHT = h;
            SPRITE_SIZE = size;
        }

        void init()
        {
            generateWorldChunks();
        }

        void setSpritesheet(Spritesheet sprites)
        {
            spritesheet = sprites;
        }   

        void generateWorldChunks()
        {
            for(int i = 0; i < WIDTH; i += 16 * SPRITE_SIZE)
            {   
                for(int j = 0; j < HEIGHT; j += 16 * SPRITE_SIZE)
                {
                    Chunk currentChunk = Chunk();
                    
                    for(int x = i; x < i + currentChunk.SIZE * SPRITE_SIZE; x += SPRITE_SIZE)
                    {
                        for(int y = j; y < j + currentChunk.SIZE * SPRITE_SIZE; y += SPRITE_SIZE)
                        {
                            Block block = Block(sf::Vector2f(x, y), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
                            block.setSprite(spritesheet.getSprite(0));
                            currentChunk.addBlock(block);
                        }
                    }

                    worldChunks.push_back(currentChunk);
                }
            }            
        }

        void draw(sf::RenderWindow &window)
        {
            for(int i = 0; i < worldChunks.size(); i++)
            {
                worldChunks[i].draw(window);   
            }
        }
};
