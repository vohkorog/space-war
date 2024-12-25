#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>

class Enemy{
    private:
        void initEnemy();
        std::string texturePath;
        sf::Texture texture;
        sf::Sprite sprite;
        
    public:
        Enemy(float x, float y);
        ~Enemy();
        void update();
        void render(sf::RenderWindow *window);
        sf::Sprite getSprite();
        void setPosition(float x, float y);
        void move();
};