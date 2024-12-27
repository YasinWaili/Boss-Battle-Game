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

/*
Function: setPosition 
Purpose: Sets the position of the boss
*/

void Boss::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

/*
Function: Draw
Purpose: Draws the boss, healthbar and projectiles
*/

void Boss::draw(sf::RenderWindow& window) {
    window.draw(shape);
    drawHealthBar(window);

    projectiles.traverse([&](BossProjectile& projectile) {
        projectile.draw(window);
    });
}

/*
Function: getBounds()
Purpose: gets the bounds of the boss shape
*/

sf::FloatRect Boss::getBounds() {
    return shape.getGlobalBounds();
}

/*
Function: shoot
Purpose: Generates a projectile for the boss and randomly generates speeed values
*/

void Boss::shoot() {
    if (size > 10){
        return;
    }

    if (attackTimer.getElapsedTime().asSeconds() >= attackCooldown) {
        sf::Vector2f position = shape.getPosition();

        float centerX = position.x + shape.getSize().x / 2;
        float centerY = position.y + shape.getSize().y / 2;

        float speedX = -(rand() % 100 + 200); 
        float speedY = (rand() % 200 - 100);  

        projectiles += BossProjectile(centerX, centerY, speedX, speedY);

        size++;
        attackTimer.restart();
    }
}

/*
Function: updateProjectiles
Purpose: Updates all the projectiles in the linkedList and checks if a 
player was hit by the projectile. If they were hit then they take damage.
Also checks if a projectile has been spawned longer than 20 seconds, and despawns
if it is.
*/

void Boss::updateProjectiles(float deltaTime, Player& player) {
    projectiles.removeIf([&](BossProjectile& projectile) {
        projectile.update(deltaTime);

        if (projectile.getBounds().intersects(player.getBounds())) {
            player.takeDamage(1); 
            return true;         
        }

        if (projectile.isExpired()) {
            size--;
            return true;
        }

        return false;
    });
}

/*
Function: move
Purpose: Generates a randomly moving position for the boss on the Y axis
*/

void Boss::move(float deltaTime) {
    sf::Vector2f position = shape.getPosition();

    if (std::abs(position.y - targetY) < 5.0f) {
        targetY = static_cast<float>(rand() % (720 - static_cast<int>(shape.getSize().y))); 
    }

    if (position.y < targetY) {
        position.y += moveSpeed * deltaTime;
        if (position.y > targetY) position.y = targetY; 
    } else if (position.y > targetY) {
        position.y -= moveSpeed * deltaTime;
        if (position.y < targetY) position.y = targetY; 
    }

    shape.setPosition(position.x, position.y);
}
