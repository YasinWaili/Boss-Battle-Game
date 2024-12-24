#include "Player.h"

Player::Player(int h, float s) : Character(h), movementSpeed(s) {
    shape.setRadius(25.0f); // Set player size
    shape.setFillColor(sf::Color::Green); // Set player color
}

void Player::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Player::move(float offsetX, float offsetY) {
    shape.move(offsetX * movementSpeed, offsetY * movementSpeed);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

int Player::getMovementSpeed(){
    return movementSpeed;
}