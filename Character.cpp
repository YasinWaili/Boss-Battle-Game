#include "Character.h"

Character::Character(int h) : health(h) { }

void Character::takeDamage(int damage){
    if (health < damage){
        health = 0;
    }
    health -= damage;
}

int Character::getHealth() { return health; }