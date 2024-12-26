#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

class Projectile {
public:
    Projectile(); // Default constructor
    Projectile(float x, float y, float speed);
    void update();
    void draw(sf::RenderWindow& window) const; // Marked as const
    bool isOffScreen() const;

private:
    sf::RectangleShape shape;
    float speed;
};

#endif
