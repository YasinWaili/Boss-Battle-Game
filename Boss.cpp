#include "Boss.h"

Boss::Boss(int h) : Character(h) {
    shape.setSize(sf::Vector2f(100.0f, 100.0f)); 
    shape.setFillColor(sf::Color::Red); 

    healthBarPosition = sf::Vector2f(1060.0f, 20.0f); 
    healthBar = HealthBar(200.0f, 20.0f, sf::Color::Green, sf::Color::Red, healthBarPosition);
}

void Boss::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Boss::draw(sf::RenderWindow& window) {
    window.draw(shape);
    drawHealthBar(window);
}
