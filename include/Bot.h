#ifndef BOT_H
#define BOT_H

#include <string>
#include "Word.h"

class Bot {
private:
    Word word;    // The secret word the bot is trying to guess

public:
    Bot() : word("") {}
    // Constructor to initialize the bot with a word
    Bot(std::string word);
    std::string provideDetailedFeedback(const std::string& guess);
    std::string provideFeedback(bool correctGuess, int attemptsLeft, const std::string& lastGuess);
    std::string getEncouragement();
    std::string revealSecretWord(const std::string& word);

    // Function to generate the bot's guess
    std::string generateGuess();
};

#endif

