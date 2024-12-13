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


def provide_feedback(secret_word, guess):
    feedback = []
    for i in range(len(secret_word)):
        if guess[i] == secret_word[i]:
            feedback.append("🟩")  # Correct position
        elif guess[i] in secret_word:
            feedback.append("🟨")  # Correct letter, wrong position
        else:
            feedback.append("⬜")  # Wrong letter
    return ''.join(feedback)






secret_word = "apple"  # For testing
guess = "algae"
feedback = provide_feedback(secret_word, guess)
print(f"Feedback: {feedback}")



