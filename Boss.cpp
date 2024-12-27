#include "Boss.h"
#include <cstdlib> 
#include <ctime>   
#include "Player.h"

Boss::Boss(int h) : Character(h), attackCooldown(1.0f), targetY(360.0f), moveSpeed(100.0f) {
    shape.setSize(sf::Vector2f(150.0f, 150.0f));
    shape.setFillColor(sf::Color::Red);

    healthBarPosition = sf::Vector2f(1060.0f, 20.0f);
    healthBar = HealthBar(200.0f, 20.0f, sf::Color::Green, sf::Color::Red, healthBarPosition);
    srand(static_cast<unsigned>(time(0)));
    size = 0;
}

void Boss::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Boss::draw(sf::RenderWindow& window) {
    window.draw(shape);
    drawHealthBar(window);

    projectiles.traverse([&](BossProjectile& projectile) {
        projectile.draw(window);
    });
}

sf::FloatRect Boss::getBounds() {
    return shape.getGlobalBounds();
}

void Boss::shoot() {
    if (size > 10){
        return;
    }

    if (attackTimer.getElapsedTime().asSeconds() >= attackCooldown) {
        sf::Vector2f position = shape.getPosition();

        float centerX = position.x + shape.getSize().x / 2;
        float centerY = position.y + shape.getSize().y / 2;

        // Increased speed range for faster initial movement
        float speedX = -(rand() % 100 + 200); // Random negative X speed (-300 to -500)
        float speedY = (rand() % 200 - 100);  // Random Y speed (-150 to +150)

        projectiles += BossProjectile(centerX, centerY, speedX, speedY);

        size++;
        attackTimer.restart();
    }
}

void Boss::updateProjectiles(float deltaTime, Player& player) {
    projectiles.removeIf([&](BossProjectile& projectile) {
        projectile.update(deltaTime);

        // Check if the projectile hits the player
        if (projectile.getBounds().intersects(player.getBounds())) {
            player.takeDamage(1); // Modify the player's health directly
            return true;          // Remove the projectile that hit the player
        }

        // Remove expired projectiles
        if (projectile.isExpired()) {
            size--;
            return true;
        }

        return false;
    });
}



void Boss::move(float deltaTime) {
    sf::Vector2f position = shape.getPosition();

    // If the boss is close to the target, select a new random target
    if (std::abs(position.y - targetY) < 5.0f) {
        targetY = static_cast<float>(rand() % (720 - static_cast<int>(shape.getSize().y))); // Random target Y within bounds
    }

    // Move smoothly toward the target Y
    if (position.y < targetY) {
        position.y += moveSpeed * deltaTime;
        if (position.y > targetY) position.y = targetY; // Clamp to target
    } else if (position.y > targetY) {
        position.y -= moveSpeed * deltaTime;
        if (position.y < targetY) position.y = targetY; // Clamp to target
    }

    // Set the new position
    shape.setPosition(position.x, position.y);
}
