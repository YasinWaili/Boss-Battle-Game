#include "Player.h"

Player::Player(int h, float s) : Character(h), movementSpeed(s) {
    shape.setRadius(25.0f); // Set player size
    shape.setFillColor(sf::Color::Green); // Set player color
}

void Player::setPosition(float x, float y) {
    shape.setPosition(x, y);
    setX(x);
    setY(y);
}

void Player::move(float offsetX, float offsetY) {
    float xMove = offsetX * movementSpeed;
    float yMove = offsetY * movementSpeed;

    // Get the current position of the shape
    float currentX = shape.getPosition().x;
    float currentY = shape.getPosition().y;
    float radius = shape.getRadius();

    // Calculate the new position
    float newX = currentX + xMove;
    float newY = currentY + yMove;

    // Ensure the new position stays within the bounds of the window
    if (newX - radius < 0) newX = radius; // Left boundary
    if (newX + radius > 1280) newX = 1280 - radius; // Right boundary
    if (newY - radius < 0) newY = radius; // Top boundary
    if (newY + radius > 720) newY = 720 - radius; // Bottom boundary

    // Update the position directly
    shape.setPosition(newX, newY);

    // Update logical coordinates
    setCoordinates(newX, newY);
}



void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

int Player::getMovementSpeed(){
    return movementSpeed;
}

void Player::setCoordinates(float x, float y) {
    setX(x);
    setY(y);
}
