#include "Game.h"

Game::Game() : isGameOver(false) 
{ 
    player = new Player(10, 2.0f);
    boss = new Boss(10);
}

void Game::run() {
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Boss Battle");

    player->setPosition(100.0f, 360.0f);
    boss->setPosition(900.0f, 330.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            player->shoot();
        }

        player->updateProjectiles(*boss); // Pass the boss to check collisions

        window.clear();
        player->draw(window); // Draw the player
        boss->draw(window);
        window.display();

        if (boss->getHealth() == 0){
            exit(0);
        }
    }
}
