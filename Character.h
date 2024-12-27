#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "HealthBar.h"

/*
Class: Character
Purpose: A Character class that represents the characters in the game
*/

class Character
{
    public:
    Character(int);
    void takeDamage(int);
    int getHealth();
    
    void updateHealthBar(); 
    void drawHealthBar(sf::RenderWindow& window);


    float getX();
    float getY();
    void setX(float);
    void setY(float);

    protected:
    int maxHealth;
    int health;
    HealthBar healthBar;
    sf::Vector2f healthBarPosition; 
    

    private:
    float x;
    float y;
};

#endif