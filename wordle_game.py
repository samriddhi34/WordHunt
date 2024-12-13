# wordle_game.py
import random 

def load_words(file_path):
    with open(file_path, 'r') as file:
        return [line.strip().lower() for line in file.readlines()]

def choose_random_word(words):
    return random.choice(words)


def get_player_guess():
    guess = input("Enter a 5-letter word: ").strip().lower()
    while len(guess) != 5 or not guess.isalpha():
        print("Invalid input! Please enter a valid 5-letter word.")
        guess = input("Enter a 5-letter word: ").strip().lower()
    return guess


words = load_words('words.txt')
secret_word = choose_random_word(words)
print(f"Secret word is: {secret_word}")  # For testing

guess = get_player_guess()
print(f"Your guess: {guess}")



