#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Boss.h"
#include <iostream>

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
    void displayResults(int, int);
    bool isGameOver;
    Player *player;
    Boss *boss;

};

#endif