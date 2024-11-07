#include "Game.h"
#include <iostream>

int main() {
    std::string playerName;
    std::cout << "Welcome to WordHunt! Enter your name: ";
    std::cin >> playerName;

    std::string secretWord = "apple";  // You can choose a random word here
    Game game(secretWord, playerName);
    game.playGame();

    return 0;
}


