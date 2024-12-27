#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

/*
Class: Projectile
Purpose: A Projectile class that represents player projectiles in the game.
*/

class Projectile {
public:
    Projectile(); // Default constructor
    Projectile(float x, float y, float speed);
    void update();
    void draw(sf::RenderWindow& window) const; // Marked as const
    bool isOffScreen() const;
    sf::FloatRect getBounds();

private:
    sf::RectangleShape shape;
    float speed;
};

#endif
