#include "Game.h"
#include <iostream>

Game::Game(std::string word, std::string playerName) 
    : word(word), player(playerName), maxAttempts(7) {}

void Game::startGame() {
    bool correctGuess = false;
    int attempts = 0;
    
    while (player.hasAttemptsLeft() && !correctGuess) {
        std::string guess = player.makeGuess();
        correctGuess = word.checkGuess(guess);

        if (correctGuess) {
            std::cout << "Congrats! You guessed the word!" << std::endl;
        } else {
            player.decrementAttempts();
            std::cout << "Wrong guess! You have " << player.hasAttemptsLeft() 
                      << " attempts left." << std::endl;
        }

        attempts++;
    }

    if (!correctGuess) {
        std::cout << "Sorry! You've used all your attempts. The correct word was: " 
                  << word.getWord() << std::endl;
    }
}

void Game::showResult(bool correctGuess) {
    if (correctGuess) {
        std::cout << "You won the game!" << std::endl;
    } else {
        std::cout << "Game over! The word was: " << word.getWord() << std::endl;
    }
}

