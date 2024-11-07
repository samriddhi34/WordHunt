#include "Bot.h"
Bot::Bot(std::string word) : word(word) {}
std::string Bot::provideDetailedFeedback(const std::string& guess) {
    std::string feedback;
    std::string secretWord = word.getWord();  // Assume `word` is the correct word stored in Bot

    // Track matched letters to avoid duplicate yellow marks
    bool matched[secretWord.size()] = {false};

    // First pass for exact matches (Green)
    for (size_t i = 0; i < guess.size() && i < secretWord.size(); ++i) {
        if (guess[i] == secretWord[i]) {
            feedback += "[🟩 " + std::string(1, guess[i]) + "] ";  // Green for correct position
            matched[i] = true;
        } else {
            feedback += "[⬜ " + std::string(1, guess[i]) + "] ";  // Placeholder for unmatched
        }
    }

    // Second pass for wrong position matches (Yellow)
    for (size_t i = 0; i < guess.size(); ++i) {
        if (guess[i] != secretWord[i] && secretWord.find(guess[i]) != std::string::npos) {
            for (size_t j = 0; j < secretWord.size(); ++j) {
                if (guess[i] == secretWord[j] && !matched[j]) {
                    matched[j] = true;
                    feedback.replace(i * 5, 3, "🟨");  // Yellow for wrong position
                    break;
                }
            }
        }
    }

    // Replace remaining placeholders with Gray
    for (size_t i = 0; i < guess.size(); ++i) {
        if (feedback[i * 5] == '[') {
            feedback.replace(i * 5, 3, "⬛");  // Gray for incorrect
        }
    }

    return feedback;
}

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

