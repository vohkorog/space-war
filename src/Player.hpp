#pragma once 
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class Player{
    private:
        void initPlayer();
        std::string texturePath;
        std::vector<Bullet> bullets;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock shootClock; // Таймер для отслеживания времени стрельбы
        float shootDelay;
        bool canShoot;
        
    public:
        Player(std::string texturePath);
        ~Player();
        void update();
        void render(sf::RenderWindow *window);
        void input();
        void shoot();
        sf::Vector2f getPosition();
        sf::FloatRect colision();
};