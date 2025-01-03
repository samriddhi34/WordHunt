from flask import Flask, request
from twilio.twiml.messaging_response import MessagingResponse
from wordle_game import load_words, choose_random_word, provide_feedback

app = Flask(__name__)

# Load words
words = load_words('words.txt')

# Track game state for each user
user_sessions = {}

@app.route("/webhook", methods=["POST"])
def whatsapp_webhook():
    incoming_msg = request.form.get("Body").strip().lower()
    from_number = request.form.get("From")
    response = MessagingResponse()

    # Start the game if the user sends "hello" or "hi"
    if incoming_msg in ["hello", "hi"]:
        secret_word = choose_random_word(words)
        user_sessions[from_number] = {
            "secret_word": secret_word,
            "attempts": 6
        }
        response.message("Welcome to WordHunt! Guess the 5-letter word. You have 6 attempts. Good luck!")
        return str(response)

    # If the user is in a game session
    if from_number in user_sessions:
        game_data = user_sessions[from_number]
        secret_word = game_data["secret_word"]

        # Validate user input
        if len(incoming_msg) == 5 and incoming_msg.isalpha():
            feedback = provide_feedback(secret_word, incoming_msg)
            game_data["attempts"] -= 1

            if incoming_msg == secret_word:
                response.message(f"🎉 You guessed it right! The word was '{secret_word}'.")
                del user_sessions[from_number]  # End the game
                return str(response)

            if game_data["attempts"] == 0:
                response.message(f"Sorry, you've run out of attempts. The word was '{secret_word}'.")
                del user_sessions[from_number]  # End the game
                return str(response)

            response.message(f"Feedback: {feedback}\nAttempts left: {game_data['attempts']}")
            return str(response)
        else:
            response.message("Invalid input! Please enter a valid 5-letter word.")
            return str(response)

    # If no game session, prompt the user to start
    response.message("Send 'Hello' or 'Hi' to start a game of WordHunt!")
    return str(response)

if __name__ == "__main__":
    app.run(debug=True)

