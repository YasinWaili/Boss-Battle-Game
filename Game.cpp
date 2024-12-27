#include "Game.h"

Game::Game() : isGameOver(false) 
{ 
    player = new Player(10, 2.0f);
    boss = new Boss(10);
}

/*
Function: run
Purpose: controls the main gmae loop
*/

void Game::run() {
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Boss Battle");

    player->setPosition(100.0f, 360.0f);
    boss->setPosition(900.0f, 330.0f);

    sf::Clock deltaClock;

    while (window.isOpen() && isGameOver == false) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calculate delta time
        float deltaTime = deltaClock.restart().asSeconds();

        // Handle player movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player->move(0, -player->getMovementSpeed()); // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player->move(0, player->getMovementSpeed()); // Move down
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player->move(-player->getMovementSpeed(), 0); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player->move(player->getMovementSpeed(), 0); // Move right
        }

        // Player actions
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            player->shoot();
        }

        // Boss actions
        boss->move(deltaTime);
        boss->shoot();

        // Update projectiles
        player->updateProjectiles(*boss);
        boss->updateProjectiles(deltaTime, *player);

        window.clear();
        player->draw(window);
        boss->draw(window);
        window.display();

        // End game scenario
        if (boss->getHealth() == 0 || player->getHealth() == 0) {
            isGameOver = true;
        }
    }

    // If the game is over then display the results
    if (isGameOver){
        displayResults(boss->getHealth(), player->getHealth());
    }
}

/*
Function: displayResults
Purpose: displays the result of the game
*/

void Game::displayResults(int b, int p){
    if (b == 0){
        std::cout << "Game over! You WIN.";
    }
    if (p == 0){
        std::cout << "Game over! You LOSE.";
    }
}
