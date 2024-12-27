#include "BossProjectile.h"

BossProjectile::BossProjectile(float x, float y, float speedX, float speedY)
    : speedX(-std::abs(speedX)), speedY(speedY), speedMultiplier(1.05f) { // Ensure projectiles start leftward
    shape.setRadius(40.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
}

void BossProjectile::update(float deltaTime) {
    sf::Vector2f pos = shape.getPosition();

    // Reverse direction and increase speed on bounce
    if (pos.x <= 0 || pos.x + shape.getRadius() * 2 >= 1280) {
        speedX = -speedX * speedMultiplier; // Reverse and increase speed
    }
    if (pos.y <= 0 || pos.y + shape.getRadius() * 2 >= 720) {
        speedY = -speedY * speedMultiplier; // Reverse and increase speed
    }

    // Move the projectile
    shape.move(speedX * deltaTime, speedY * deltaTime);
}

void BossProjectile::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

bool BossProjectile::isExpired() const {
    return lifeTimer.getElapsedTime().asSeconds() > 20.0f; // Disappear after 10 seconds
}

sf::FloatRect BossProjectile::getBounds() {
    return shape.getGlobalBounds();
}

