#ifndef BOSS_H
#define BOSS_H

#include "Character.h"
#include "BossProjectile.h"
#include "List.h"

class Player;

class Boss : public Character
{
    public:
    Boss(int=0);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    sf::FloatRect getBounds();
    void shoot();
    void updateProjectiles(float, Player&);
    void move(float);

    private:
    sf::RectangleShape shape;
    List<BossProjectile> projectiles;
    int size;

    float attackCooldown; 
    sf::Clock attackTimer;

    float targetY;  
    float moveSpeed; 
};

#endif