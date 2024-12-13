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
    feedback = ["🟥"] * len(secret_word)  # Default to "⬜" for incorrect letters
    secret_word_list = list(secret_word)  # Convert to list for mutable operations
    
    # First pass: Mark correct positions
    for i in range(len(secret_word)):
        if guess[i] == secret_word[i]:
            feedback[i] = "🟩"  # Correct position
            secret_word_list[i] = None  # Mark as used

    # Second pass: Mark correct letters in wrong positions
    for i in range(len(secret_word)):
        if feedback[i] == "🟩":
            continue  # Skip already matched positions
        if guess[i] in secret_word_list:
            feedback[i] = "🟨"  # Correct letter, wrong position
            secret_word_list[secret_word_list.index(guess[i])] = None  # Mark as used

    return ''.join(feedback)




def play_game(words):
    secret_word = choose_random_word(words)
    print("Welcome to Wordle!")
    attempts = 6
    for _ in range(attempts):
        guess = get_player_guess()
        feedback = provide_feedback(secret_word, guess)
        print(f"Feedback: {feedback}")
        if guess == secret_word:
            print("🎉 You guessed it right! 🎉")
            return
    print(f"Sorry, you've run out of attempts. The word was: {secret_word}")

if __name__ == "__main__":
    words = load_words('words.txt')
    play_game(words)




