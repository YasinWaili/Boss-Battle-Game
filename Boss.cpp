#include "Boss.h"

Boss::Boss(int h) : Character(h) 
{
    shape.setSize(sf::Vector2f(100.0f, 100.0f)); 
    shape.setFillColor(sf::Color::Red); 

}

void Boss::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Boss::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
