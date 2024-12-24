#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>

class Character
{
    public:
    Character(int);
    void takeDamage(int);
    int getHealth();


    private:
    int health;
    float x;
    float y;
};

#endif