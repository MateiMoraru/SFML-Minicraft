class Chunk
{
    private:
        std::vector<Block> blocks;
    public:
        const int SIZE = 16;
        void addBlock(Block &block)
        {
            blocks.push_back(block);
        }

        void draw(sf::RenderWindow &window)
        {
            for(int i = 0; i < blocks.size(); i++)
                blocks[i].draw(window);
        }
        int getLen()
        {
            return blocks.size();
        }
        Block getBlock(int index)
        {
            return blocks[index];
        }
};
