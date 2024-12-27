#include "Projectile.h"

Projectile::Projectile() : speed(0.0f) {
    shape.setSize(sf::Vector2f(10.0f, 5.0f));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(0, 0); 
}

Projectile::Projectile(float x, float y, float speed) : speed(speed) {
    shape.setSize(sf::Vector2f(10.0f, 5.0f));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(x, y);
}

/*
Function: update
Purpose: Updates the projectile
*/

void Projectile::update() {
    shape.move(speed, 0);
}

/*
Function: draw
Purpose: Draws the projectile
*/

void Projectile::draw(sf::RenderWindow& window) const { 
    window.draw(shape);
}

/*
Function: isOffScreen
Purpose: Checks whether the projectile is off screen or not
*/

bool Projectile::isOffScreen() const {
    return shape.getPosition().x > 1280;
}

/*
Function: getBounds
Purpose: gets the bounds of the projectile
*/

sf::FloatRect Projectile::getBounds() {
    return shape.getGlobalBounds();
}

