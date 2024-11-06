#ifndef BOT_H
#define BOT_H

#include <string>
#include "Word.h"

class Bot {
private:
    Word word;    // The secret word the bot is trying to guess

public:
    // Constructor to initialize the bot with a word
    Bot(std::string word);

    // Function to generate the bot's guess
    std::string generateGuess();
};

#endif

