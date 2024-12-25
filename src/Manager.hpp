#pragma once 
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include <vector>
#include <ctime>
#include <random>

class Manager
{
    private:
        std::vector<Enemy*> resurces;
        Enemy *enemy;
        int num;

    public:
        Manager();
        ~Manager();
        void add(int num);
        void render(sf::RenderWindow *window);
        void update();
};