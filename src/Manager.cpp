#include "Manager.hpp"


Manager::Manager()
{

}

Manager::~Manager()
{
    
}

void Manager::add(int num)
{
    this->num = num;
    this->resurces.reserve(num);

     // Создаем генератор случайных чисел для x
    std::srand(std::time(0));
    
    // Создаем генератор случайных чисел для x
    std::random_device rd;  // Источник случайных чисел
    std::mt19937 gen(rd()); // Инициализация генератора
    std::uniform_int_distribution<> distrib(400, 700); // Определяем диапазон

    for(int i=0; i<num; i++)
    {
        int x = std::rand()%750;
        int y = distrib(gen);
        this->enemy = new Enemy(x,y);
        this->resurces.push_back(this->enemy);
    }
}

void Manager::render(sf::RenderWindow *window)
{
    for(int i=0; i<this->num; i++)
    {
        this->resurces[i]->render(window);
        this->resurces[i]->move();
    }
}

void Manager::update()
{    
    for(int i =0; i<this->num; i++)
    {
        this->resurces[i]->move();
    }
}