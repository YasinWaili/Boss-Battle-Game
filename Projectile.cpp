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

void Projectile::update() {
    shape.move(speed, 0);
}

void Projectile::draw(sf::RenderWindow& window) const { // Marked as const
    window.draw(shape);
}

bool Projectile::isOffScreen() const {
    return shape.getPosition().x > 1280;
}

sf::FloatRect Projectile::getBounds() {
    return shape.getGlobalBounds();
}

