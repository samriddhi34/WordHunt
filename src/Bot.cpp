#include "Bot.h"
#include <iostream>

Bot::Bot() {}

std::string Bot::provideFeedback(bool correctGuess, int attemptsLeft, const std::string& lastGuess) {
    if (correctGuess) {
        return "🎉 Great job! You've guessed the word!";
    } else if (attemptsLeft > 0) {
        return "🤔 Not quite! Try again. You have " + std::to_string(attemptsLeft) + " attempts left.";
    } else {
        return "Oh no! You're out of attempts. Better luck next time!";
    }
}

std::string Bot::getEncouragement() {
    return "You got this! Keep trying! ";
}

std::string Bot::revealSecretWord(const std::string& word) {
    return "The correct word was: " + word + ". Thanks for playing!";
}

