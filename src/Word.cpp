#include "Word.h"
#include <iostream>

Word::Word(std::string word) : secretWord(word) {}

std::string Word::getWord() const {
    return secretWord;
}

bool Word::checkGuess(std::string guess) {
    return secretWord == guess;
}

