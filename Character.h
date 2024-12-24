#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
    public:
    Character(int);
    void takeDamage(int);
    int getHealth();


    private:
    int health;
};

#endif