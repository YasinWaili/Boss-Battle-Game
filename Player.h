#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <SFML/Graphics.hpp>

/*
Class: Player
Purpose: Represents the player in the boss battle.
*/

class Player : public Character {
public:
    Player(int h, float s);
    void setPosition(float x, float y);
    void move(float offsetX, float offsetY);
    void draw(sf::RenderWindow& window);
    int getMovementSpeed();
    void setCoordinates(float, float);

private:
    float movementSpeed;
    sf::CircleShape shape; // Visual representation of the player
};

#endif
