#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include "List.h"

/*
Class: Player
Purpose: Represents the player in the boss battle.
*/

class Player : public Character {
public:
    Player(int h, float s);
    void setPosition(float x, float y);
    void move(float offsetX, float offsetY);
    void shoot();
    void updateProjectiles();
    void draw(sf::RenderWindow& window);
    int getMovementSpeed();
    void setCoordinates(float, float);

private:
    float movementSpeed;
    sf::CircleShape shape; 
    List<Projectile> projectiles;

    float attackCooldown; 
    sf::Clock attackTimer;
};

#endif
