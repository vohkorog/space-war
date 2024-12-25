#include "Game.hpp"

void Game::initVar(){
    this->window = nullptr;
    this->player = new Player("/Users/kirillgorohov/Desktop/codes/c++/SFML Game/StarWars/res/spaceship.png");
    this->texturesBackground = {"/Users/kirillgorohov/Desktop/codes/c++/SFML Game/StarWars/res/bac.jpg"};
    this->speedsBackground = {0.5f, 0.3f, 0.1f};
    this->parallaxBackground = new ParallaxBackground(this->texturesBackground, this->speedsBackground);
    this->manager.add(6);
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(this->screen_w, this->screen_h), this->title);
    this->window->setFramerateLimit(144);
}

Game::Game(int screen_w, int screen_h, std::string title){
    this->screen_w = screen_w;
    this->screen_h = screen_h;
    this->title = title;
    initVar();
    initWindow();
}

Game::~Game(){ delete this->window;}


void Game::render(){
    this->window->clear(sf::Color::Black);
    this->parallaxBackground->render(this->window);
    this->player->render(this->window);
    manager.render(this->window);
    this->window->display();
}


void Game::update(){
    
    this->parallaxBackground->update(this->clock.restart().asSeconds()*100);
    this->player->update();
    this->manager.update();
    this->input();
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::input(){
    while(this->window->pollEvent(this->event)){
        if (event.type == sf::Event::Closed){
            this->window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->window->close();
        }
    }
}