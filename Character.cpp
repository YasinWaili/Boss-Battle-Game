#include "Character.h"

Character::Character(int h) : health(h) { }

void Character::takeDamage(int damage){
    if (health < damage){
        health = 0;
    }
    health -= damage;
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