# WordHunt - A WhatsApp-based Word Guessing Game

**WordHunt** is an interactive word guessing game built on the WhatsApp platform. Players can engage in real-time gameplay by sending messages to a WhatsApp bot, where they have to guess a 5-letter word within 6 attempts. It features instant feedback and easy-to-follow game mechanics for an engaging experience.

## Technologies Used

- **Flask**: Python-based micro web framework for building the backend.
- **Twilio API**: For sending and receiving WhatsApp messages.
- **Python**: Primary programming language for game logic and backend.
- **Render**: Cloud platform for deploying the Flask app.
- **Git**: For version control and collaboration.
- **Ngrok** (for development): Used to expose the local server to the internet during development.

## Features

- **WhatsApp Integration**: Players interact with the game through WhatsApp.
- **Real-time Feedback**: Players receive feedback after every guess.
- **Game Logic**: Players must guess a 5-letter word within 6 attempts.
- **Dynamic User Sessions**: Each player's game is tracked individually.

## Setup Instructions

### Local Development

To run the project locally, follow the steps below:

1. Clone the repository:
   ```bash
   git clone <repo-url>
   cd wordhunt
2. Install dependencies
   ```bash
   pip install -r requirements.txt
3. Create a .env file and add your Twilio credentials:
   ```bash
   TWILIO_ACCOUNT_SID=your_account_sid
   TWILIO_AUTH_TOKEN=your_auth_token
4. Run the Flask app:
   ```bash
   python app.py
5. Use ngrok to expose your local server to the internet during development.

## Deploying on Render
To deploy on Render
1. Push the project on github
2. Create a new web service on Render and link your GitHub repository.
3. Choose the Python environment and set up a build script (python3 -m pip install -r requirements.txt).
4. Set the port to 5000 and deploy.
5. After deployment, use the provided URL for webhook integration in Twilio

## How to Play
1. Add the Twilio sandbox WhatsApp number (+14155238886) to your contacts.
2. Send a message "join <your-sandbox-name>" to the Twilio sandbox number.
3. Go to Twilio console, under the Business-Initiated Message section, there is a dropdown in the "To" field, manually change the "To" number to your phone number or the test number you're using to interact with the bot.
4. Start the game by sending "Hi" or "Hello" to begin the WordHunt game
5. Guess the 5-letter word within 6 attempts and receive real-time feedback.
   
   
   
