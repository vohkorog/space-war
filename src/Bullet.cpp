#include "Bullet.hpp"

void Bullet::initBullet(){
    this->texture.loadFromFile(this->texturePath);
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.5, 0.2);
}

Bullet::Bullet(std::string texturePath){
    this->texturePath = texturePath;
    initBullet();
}
Bullet::~Bullet(){

}
void Bullet::render(sf::RenderWindow *window){
    window->draw(this->sprite);
    
}
void Bullet::update(){
    this->sprite.move(0,5);
}

bool Bullet::isOffScreen(){
    return this->sprite.getPosition().y>700;
}

sf::Sprite Bullet::getSprite(){
    return this->sprite;
}

void Bullet::setPosition(float x, float y){
    this->sprite.setPosition(x, y);
}