#include "Player.h"
#include <iostream>

Player::Player(std::string name) : playerName(name), attemptsLeft(7) {}

std::string Player::getName() const {
    return playerName;
}

void Player::decrementAttempts() {
    attemptsLeft--;
}
void Player::resetAttempts(int maxAttempts) {
        this->attemptsLeft = maxAttempts;
        
}


bool Player::hasAttemptsLeft() const {
    return attemptsLeft > 0;
}

std::string Player::makeGuess() {
    std::string guess;
    std::cout << "Enter your guess: ";
    std::cin >> guess;
    return guess;
}

