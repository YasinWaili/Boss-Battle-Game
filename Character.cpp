#include "Character.h"

Character::Character(int h) : maxHealth(h), health(h), healthBarPosition(0, 0), healthBar(200.0f, 20.0f, sf::Color::Green, sf::Color::Red, healthBarPosition) { }

void Character::takeDamage(int damage){
    health -= damage;
    if (health < 0){
        health = 0;
    }
}

int Character::getHealth() { return health; }

float Character::getX(){
 return x;
}

float Character::getY(){
 return y;
}

void Character::setX(float x){
    this->x = x;
}

void Character::setY(float y){
    this->y = y;
}

void Character::updateHealthBar() {
    healthBar.update(health, maxHealth); 
}

void Character::drawHealthBar(sf::RenderWindow& window) {
    healthBar.draw(window); 
}