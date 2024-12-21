#pragma once 
#include <SFML/Graphics.hpp>

class Enemy{
    private:
        void initEnemy();
        std::string texturePath;
        sf::Texture texture;
        sf::Sprite sprite;
        
    public:
        Enemy(std::string texturePath);
        ~Enemy();
        void update();
        void render(sf::RenderWindow *window);
};