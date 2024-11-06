#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
private:
    std::string secretWord;   // The actual word to guess

public:
    // Constructor to set the secret word
    Word(std::string word);

    // Function to get the secret word (only for testing purposes, not for the game)
    std::string getWord() const;

    // Function to check if the player's guess matches the secret word
    bool checkGuess(std::string guess);
};

#endif

