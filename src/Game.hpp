#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.hpp"
#include "ParallaxBackground.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

class Game{
    private:
        sf::RenderWindow *window;
        std::string title;
        sf::Event event;
        int screen_w;
        int screen_h;
        sf::Clock clock;
        sf::VideoMode videomode;
        // Задаем пути к текстурам и скорости для паралакса заднего фона 
        std::vector<std::string> texturesBackground;
        std::vector<float> speedsBackground; // Разные скорости для слоев фона 
        ParallaxBackground *parallaxBackground;
        Player *player;
        Bullet *bullet;
        Enemy *enemy;
        void initVar();
        void initWindow();
    public:
        Game(int screen_w, int screen_h, std::string title);
        virtual ~Game();
        void render();
        void update();
        void input();
        const bool running() const;
};