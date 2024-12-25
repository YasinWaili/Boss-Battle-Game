#include "HealthBar.h"

HealthBar::HealthBar(float w, float h, sf::color fillColor, sf::color backgroundColor, sf::Vector2f position) : maxWidth(w){
    
}

void HealthBar::update(float, float);

void HealthBar::draw(sf::RenderWindow&);