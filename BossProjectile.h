#ifndef BOSSPROJECTILE_H
#define BOSSPROJECTILE_H

#include <SFML/Graphics.hpp>
#include <cmath>

/*
Class: BossProjectile
Purpose: A BossProjectile class that represents the projectiles shot by the boss
*/

class BossProjectile {
public:
    BossProjectile(float x = 0.0f, float y = 0.0f, float speedX = 0.0f, float speedY = 0.0f);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    bool isExpired() const;
    sf::FloatRect getBounds();

private:
    sf::CircleShape shape;
    float speedX;
    float speedY;
    sf::Clock lifeTimer;

    float speedMultiplier; // Increases speed with each bounce
};

#endif
