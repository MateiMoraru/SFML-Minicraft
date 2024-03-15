#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "block.h"
#include "spritesheet.h"
#define WIDTH 1200
#define HEIGHT 800

int main()
{
    //------------------------------------------- SFML WINDOW INIT ---------------------------------//
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Minicraft");
    window.setFramerateLimit(0);

    sf::Font Arial;
    if(!Arial.loadFromFile("res/Arial.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }

    //------------------------------------------- GAME VARIABLES ---------------------------------//

    sf::Text TextFps;
    TextFps.setFont(Arial);
    TextFps.setString("FPS: -1");
    TextFps.setPosition(0, 0);

    Spritesheet spritesheet = Spritesheet("res/assets/spritesheet.png", 16, 16);

    Block block = Block(sf::Vector2f(100, 100), sf::Vector2f(100, 100));
    block.setColor(sf::Color(255, 0, 255));
    block.setSprite(spritesheet.getSprite(0));
    //------------------------------------------- WINDOW FPS -------------------------------------//
    std::chrono::milliseconds startTime = std::chrono::duration_cast<std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
    std::chrono::milliseconds endTime = std::chrono::duration_cast<std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );

    sf::Clock deltaClock;

    int frames = 0;
    sf::Time deltaTime;
    //------------------------------------------ GAME LOOP -------------------------------------//
    while(window.isOpen())
    {
        ++frames;
        //-------------------------------------- EVENT LOOP -----------------------------------//
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        //------------------------------------- RENDERING -------------------------------------//
   
        window.clear(sf::Color(52, 107, 235));
        block.draw(window);
        window.draw(TextFps);
        window.display();
    
        //------------------------------ FPS-DELTATIME CALCULATIONS ---------------------------//

        deltaTime = deltaClock.restart(); 
        
        std::chrono::milliseconds endTime = std::chrono::duration_cast<std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
        );
        if(std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() > 1000)
        {
            TextFps.setString("FPS: " + std::to_string(frames));
            startTime = std::chrono::duration_cast<std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()
            );
            frames = 0;
        }
    }
}

