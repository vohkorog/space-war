#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>

class Bullet{
    private:
        void initBullet();
        std::string texturePath;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f pos;
       
    public:
        Bullet(std::string texturePath);
        ~Bullet();
        void update();
        void render(sf::RenderWindow *window);
        sf::FloatRect colision();
        bool isOffScreen();
        sf::Sprite getSprite();
        void input();
        void setPosition(float x, float y);
};