# wordle_game.py
import random 

def load_words(file_path):
    with open(file_path, 'r') as file:
        return [line.strip().lower() for line in file.readlines()]

def choose_random_word(words):
    return random.choice(words)

words = load_words('words.txt')
secret_word = choose_random_word(words)
print(f"Secret word is: {secret_word}")  # For testing


