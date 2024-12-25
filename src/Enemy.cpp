#include "Enemy.hpp"

Enemy::Enemy(float x, float y){
    this->sprite.setPosition(x, y);
    initEnemy();
}

Enemy::~Enemy(){

}

void Enemy::initEnemy(){
    this->texture.loadFromFile("/Users/kirillgorohov/Desktop/codes/c++/SFML Game/StarWars/res/enemy.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.3, 0.3);
}

void Enemy::update(){


}

void Enemy::render(sf::RenderWindow *window){
    window->draw(this->sprite);
    
}

sf::Sprite Enemy::getSprite(){
    return this->sprite;
}

void Enemy::setPosition(float x, float y){
    this->sprite.setPosition(x, y);
}

void Enemy::move(){

}