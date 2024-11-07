#include "Game.h"
#include "Bot.h"
#include <iostream>

Game::Game(std::string word, std::string playerName) 
    : word(word), player(playerName), maxAttempts(7), bot() {} // Initialized bot

void Game::startGame() {
    std::cout << "Starting the game for player " << player.getName() << "!" << std::endl;
    player.resetAttempts(maxAttempts);
}

void Game::playGame() {
    startGame();
    bool correctGuess = false;
    
    while (player.hasAttemptsLeft() && !correctGuess) {
        std::string guess = player.makeGuess();
        correctGuess = word.checkGuess(guess);

        if (correctGuess) {
            std::cout << bot.provideFeedback(true, player.hasAttemptsLeft(), guess) << std::endl;
        } else {
            player.decrementAttempts();
            std::cout << bot.provideFeedback(false, player.hasAttemptsLeft(), guess) << std::endl;
            if (player.hasAttemptsLeft()) {
                std::cout << bot.getEncouragement() << std::endl;
            }
        }
    }

    showResult(correctGuess);
}

void Game::showResult(bool correctGuess) {
    if (correctGuess) {
        std::cout << "You won the game!" << std::endl;
    } else {
        std::cout << bot.revealSecretWord(word.getWord()) << std::endl;
    }
}

