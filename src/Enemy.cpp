#include "Enemy.hpp"

Enemy::Enemy(float x, float y){
    this->directionX = (rand() % 3 - 1) * 1;
    this->directionY = (rand() % 3 - 1) * 1;
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
    sf::Vector2f currentPosition = this->sprite.getPosition();
    this->sprite.setPosition(currentPosition.x + this->directionX, currentPosition.y + this->directionY);
    if(this->sprite.getPosition().x > 950){
        this->directionX *= -1;
    }
    if(this->sprite.getPosition().x < 0){
        this->directionX *= -1;
    }
    if(this->sprite.getPosition().y < 400){
        this->directionY *= -1;
    }
    if(this->sprite.getPosition().y > 750){
        this->directionY *= -1;
    }




    // float x = this->sprite.getPosition().x+this->directionX;
    // float y = this->sprite.getPosition().y+this->directionY;
    // this->sprite.setPosition(x,y);
    // if(x>800){
    //     this->directionX *= -1;
    // }
    // if(x<0){
    //     this->directionX *= -1;
    // }
    // if(y>800){
    //     this->directionY *= -1;
    // }
    // if(x<400){
    //     this->directionY *= -1;
    // }
}


// void Enemy::moveRandomly(float deltaTime) {
//     // Генерация случайного направления
//     static float  = (rand() % 3 - 1) * 100; // -1, 0 или 1
//     static float directionY = (rand() % 3 - 1) * 100; // -1, 0 или 1

//     // Изменение позиции спрайта
//     this->sprite.move(directionX * deltaTime, directionY * deltaTime);

//     // Проверка границ окна
//     if (this->sprite.getPosition().x < 0 || this->sprite.getPosition().x + this->sprite.getGlobalBounds().width > 1000) {
//         directionX = -directionX; // Изменение направления по X
//     }
//     if (this->sprite.getPosition().y < 0 || this->sprite.getPosition().y + this->sprite.getGlobalBounds().height > 1000) {
//         directionY = -directionY; // Изменение направления по Y
//     }
// }
