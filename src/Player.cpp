#include "Player.hpp"

void Player::initPlayer(){
    this->texture.loadFromFile(this->texturePath);
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(500, 100);
    this->sprite.setScale(0.02,0.02);
    this->shootDelay = 1.0f;
    this->canShoot = true;
}

Player::Player(std::string texturePath){
    this->texturePath = texturePath;
    initPlayer();
}

Player::~Player(){

}

void Player::render(sf::RenderWindow *window){
    window->draw(this->sprite);

    for(int i = 0; i<this->bullets.size(); i++){
        window->draw(bullets[i].getSprite());
    }
}

void Player::input(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->sprite.move(-2, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->sprite.move(2, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->sprite.move(0, -2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->sprite.move(0, 2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->sprite.move(0, 2);
    }
    if(this->canShoot && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->bullets.emplace_back("/Users/kirillgorohov/Desktop/codes/c++/SFML Game/StarWars/res/bullet.png"); 
        this->bullets.back().setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y);
        canShoot = false; // Блокируем стрельбу
        shootClock.restart();
    }
}

void Player::update(){
    input();
    if (!canShoot && shootClock.getElapsedTime().asSeconds() >= shootDelay) {
        canShoot = true; // Разрешаем стрелять снова
    }
    for(int i = 0; i<this->bullets.size(); i++){
        this->bullets[i].update();
    }
    for (auto it = this->bullets.begin(); it != this->bullets.end();) {
        if (it->isOffScreen()) {
            it = this->bullets.erase(it); // Удаление пули, если она вышла за экран
        } else {
            ++it;
        }
    }
}

sf::Vector2f Player::getPosition(){
    return this->sprite.getPosition();
}

void Player::shoot(){

    

    
}