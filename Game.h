#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Boss.h"

/*
Class: Game
Purpose: A game class that controls the game loop
*/

class Game
{
    public:
    Game();
    void run();

    private:
    bool isGameOver;
    Player *player;
    Boss *boss;

};

#endif