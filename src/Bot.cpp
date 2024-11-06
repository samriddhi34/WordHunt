#include "Bot.h"
#include <cstdlib>
#include <ctime>

Bot::Bot(std::string word) : word(word) {}

std::string Bot::generateGuess() {
    // Randomly generate a guess (you can make it more sophisticated)
    return "apple"; // for simplicity, return a fixed guess
}

