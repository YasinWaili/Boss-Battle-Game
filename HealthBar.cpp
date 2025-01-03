#include "HealthBar.h"

HealthBar::HealthBar(float w, float h, sf::Color fillColor, sf::Color backgroundColor, sf::Vector2f position) : maxWidth(w) {

    barBackground.setSize(sf::Vector2f(w, h));
    barBackground.setFillColor(backgroundColor);
    barBackground.setPosition(position);

    barForeground.setSize(sf::Vector2f(w, h));
    barForeground.setFillColor(fillColor);
    barForeground.setPosition(position);
}

/*
Function: update
Purpose: updates the health bar values
*/

void HealthBar::update(float currentHealth, float maxHealth) {
    float healthPercentage = currentHealth / maxHealth;
    barForeground.setSize(sf::Vector2f(maxWidth * healthPercentage, barForeground.getSize().y));
}

/*
Function: draw
Purpose: draws the health bar
*/

void HealthBar::draw(sf::RenderWindow& window) {
    window.draw(barBackground);
    window.draw(barForeground);
}