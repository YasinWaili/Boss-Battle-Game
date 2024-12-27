#include "Player.h"
#include <vector> 

Player::Player(int h, float s) : Character(h), movementSpeed(s), attackCooldown(0.5f) {
    shape.setRadius(25.0f); 
    shape.setFillColor(sf::Color::Green); 

    healthBarPosition = sf::Vector2f(20.0f, 20.0f); 
    healthBar = HealthBar(200.0f, 20.0f, sf::Color::Green, sf::Color::Red, healthBarPosition);
}

/*
Function: setPosition
Purpose: Sets the position of the player shape
*/

void Player::setPosition(float x, float y) {
    shape.setPosition(x, y);
    setX(x);
    setY(y);
}

/*
Function: move
Purpose: Moves the player and makes sure they dont go out of bouunds
*/

void Player::move(float offsetX, float offsetY) {
    float xMove = offsetX * movementSpeed;
    float yMove = offsetY * movementSpeed;

    float currentX = shape.getPosition().x;
    float currentY = shape.getPosition().y;
    float radius = shape.getRadius();

    float newX = currentX + xMove;
    float newY = currentY + yMove;

    if (newX - radius < 0) newX = radius; 
    if (newX + radius > 1280) newX = 1280 - radius; 
    if (newY - radius < 0) newY = radius;
    if (newY + radius > 720) newY = 720 - radius; 

    shape.setPosition(newX, newY);

    setCoordinates(newX, newY);
}

/*
Function: shoot
Purpose: Generates a projectile and shoots it on screen
*/

void Player::shoot() {
    if (attackTimer.getElapsedTime().asSeconds() >= attackCooldown) {
        float x = shape.getPosition().x + shape.getRadius() * 2;
        float y = shape.getPosition().y + shape.getRadius() - 2.5f;
        projectiles += Projectile(x, y, 5.0f);
        attackTimer.restart();
    }
}

/*
Function: updateProjectiles
Purpose: updates all projectiles in the list and checks if its out of bounds
or if it hit the boss.
*/

void Player::updateProjectiles(Boss& boss) {
    projectiles.removeIf([&](Projectile& projectile) {
        projectile.update();

        if (boss.getBounds().intersects(projectile.getBounds())) {
            boss.takeDamage(1); 
            return true;        
        }

        return projectile.isOffScreen();
    });
}

/*
Function: draw
Purpose: Draws the health bar, player entity and projectiles in the list
*/

void Player::draw(sf::RenderWindow& window) {
    drawHealthBar(window);
    window.draw(shape);

    projectiles.traverse([&](Projectile& projectile) {
        projectile.draw(window);
    });
}

// getters and setters

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
