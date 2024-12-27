#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <SFML/Graphics.hpp>

/*
Class: HealthBar
Purpose: A HealthBar class that represents the health bar of characters in the game
*/

class HealthBar
{
    public:
    HealthBar(float w, float h, sf::Color fillColor, sf::Color backgroundColor, sf::Vector2f position);
    void update(float, float);
    void draw(sf::RenderWindow&);

    private:
    sf::RectangleShape barBackground;
    sf::RectangleShape barForeground;
    float maxWidth;
};

#endif