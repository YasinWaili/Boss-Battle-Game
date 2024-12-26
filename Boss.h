#ifndef BOSS_H
#define BOSS_H

#include "Character.h"

class Boss : public Character
{
    public:
    Boss(int);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    sf::FloatRect getBounds();

    private:
    sf::RectangleShape shape;
};

#endif