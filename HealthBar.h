#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <SFML/Graphics.hpp>

class HealthBar
{
    public:
    HealthBar(float, float, sf::color, sf::color, sf::Vector2f);
    void update(float, float);
    void draw(sf::RenderWindow&);

    private:
    sf::RectangleShape barBackground;
    sf::RectangleShape barForeground;
    float maxWidth;
};

#endif