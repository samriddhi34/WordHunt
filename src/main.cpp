#include <iostream>
#include "Game.h"

int main() {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    Game wordleGame("apple", playerName); // Example word is "apple"
    wordleGame.startGame();

    return 0;
}

