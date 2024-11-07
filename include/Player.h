#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string playerName;    // Name of the player
    int attemptsLeft;          // Number of attempts remaining

public:
    // Constructor to initialize player name and attempts
    Player(std::string name);

    // Function to get the player's name
    std::string getName() const;

    // Function to decrement the attempts
    void decrementAttempts();

    // Function to reset attempts to maxAttempts
    void resetAttempts(int maxAttempts);

    // Function to check if the player has any attempts left
    bool hasAttemptsLeft() const;

    // Function to make a guess
    std::string makeGuess();
};

#endif

