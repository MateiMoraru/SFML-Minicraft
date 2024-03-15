class Spritesheet
{
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        std::string path_to_file;
        int spritesNumber, spriteSize;

        Spritesheet()
        {
    
        }

        Spritesheet(std::string path, int sprites_number, int sprite_size)
        {
            path_to_file = path;
            spritesNumber = sprites_number;
            spriteSize = sprite_size;
            if (!texture.loadFromFile(path))
            {
                std::cout << "Error occured whilst loading spritesheet" << std::endl;
            }
        }

        sf::Sprite getSprite(int id)
        {
            int x = (id % (spritesNumber)) * spriteSize;
            int y = (id / (spritesNumber)) * spriteSize;
            return sf::Sprite(texture, sf::IntRect(x, y, x + spriteSize, y + spriteSize));
        }
};
