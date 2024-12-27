#include "BossProjectile.h"

BossProjectile::BossProjectile(float x, float y, float speedX, float speedY)
    : speedX(-std::abs(speedX)), speedY(speedY), speedMultiplier(1.05f) { 
    shape.setRadius(40.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
}

/*
Function: update
Purpose: Updates the speed of the boss projectiles and moves them
*/

void BossProjectile::update(float deltaTime) {
    sf::Vector2f pos = shape.getPosition();

    if (pos.x <= 0 || pos.x + shape.getRadius() * 2 >= 1280) {
        speedX = -speedX * speedMultiplier;
    }
    if (pos.y <= 0 || pos.y + shape.getRadius() * 2 >= 720) {
        speedY = -speedY * speedMultiplier; 
    }

    shape.move(speedX * deltaTime, speedY * deltaTime);
}

/*
Function: draw
Purpose: Draws the projectile
*/

void BossProjectile::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

/*
Function: isExpired
Purpose: Checks if a projectile has been spawned longer than 20 seconds
*/

bool BossProjectile::isExpired() const {
    return lifeTimer.getElapsedTime().asSeconds() > 20.0f; 
}

/*
Function: getBounds()
Purpose: gets the bounds of the projectile
*/

sf::FloatRect BossProjectile::getBounds() {
    return shape.getGlobalBounds();
}

