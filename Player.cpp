#include "Player.h"
#include <vector> 

Player::Player(int h, float s) : Character(h), movementSpeed(s), attackCooldown(0.5f) {
    shape.setRadius(25.0f); // Set player size
    shape.setFillColor(sf::Color::Green); // Set player color

    healthBarPosition = sf::Vector2f(20.0f, 20.0f); // Set health bar position
    healthBar = HealthBar(200.0f, 20.0f, sf::Color::Green, sf::Color::Red, healthBarPosition);
}
void Player::setPosition(float x, float y) {
    shape.setPosition(x, y);
    setX(x);
    setY(y);
}

void Player::move(float offsetX, float offsetY) {
    float xMove = offsetX * movementSpeed;
    float yMove = offsetY * movementSpeed;

    float currentX = shape.getPosition().x;
    float currentY = shape.getPosition().y;
    float radius = shape.getRadius();

    float newX = currentX + xMove;
    float newY = currentY + yMove;

    // Ensure the new position stays within the bounds of the window
    if (newX - radius < 0) newX = radius; // Left boundary
    if (newX + radius > 1280) newX = 1280 - radius; // Right boundary
    if (newY - radius < 0) newY = radius; // Top boundary
    if (newY + radius > 720) newY = 720 - radius; // Bottom boundary

    shape.setPosition(newX, newY);

    setCoordinates(newX, newY);
}

void Player::shoot() {
    if (attackTimer.getElapsedTime().asSeconds() >= attackCooldown) {
        float x = shape.getPosition().x + shape.getRadius() * 2;
        float y = shape.getPosition().y + shape.getRadius() - 2.5f;
        projectiles += Projectile(x, y, 5.0f);
        attackTimer.restart();
    }
}


void Player::updateProjectiles(Boss& boss) {
    projectiles.removeIf([&](Projectile& projectile) {
        projectile.update(); // Move the projectile

        // Check collision with boss
        if (boss.getBounds().intersects(projectile.getBounds())) {
            boss.takeDamage(1); 
            return true;        
        }

        // Remove off-screen projectiles
        return projectile.isOffScreen();
    });
}



void Player::draw(sf::RenderWindow& window) {
    drawHealthBar(window);
    window.draw(shape);

    projectiles.traverse([&](Projectile& projectile) {
        projectile.draw(window);
    });
}


int Player::getMovementSpeed(){
    return movementSpeed;
}

void Player::setCoordinates(float x, float y) {
    setX(x);
    setY(y);
}

sf::FloatRect Player::getBounds() {
    return shape.getGlobalBounds();
}
