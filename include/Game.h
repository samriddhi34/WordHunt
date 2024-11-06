#ifndef GAME_H
#define GAME_H

#include "Word.h"
#include "Player.h"
#include "Bot.h"

class Game {
private:
    Word word;                 // The secret word to guess
    Player player;             // The player making guesses
    int maxAttempts;           // Maximum number of attempts

public:
    // Constructor to initialize the game with word and player
    Game(std::string word, std::string playerName);

    // Function to start the game and manage attempts
    void startGame();

    // Function to show the result of the guess
    void showResult(bool correctGuess);
};

#endif

