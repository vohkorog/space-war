#include "Enemy.hpp"

Enemy::Enemy(std::string texturePath){
    this->texturePath = texturePath;
    initEnemy();
}

Enemy::~Enemy(){

}

void Enemy::initEnemy(){
    this->texture.loadFromFile(this->texturePath);
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(500,500);
    this->sprite.setScale(0.3, 0.3);
}

void Enemy::update(){

}

void Enemy::render(sf::RenderWindow *window){
    window->draw(this->sprite);
}