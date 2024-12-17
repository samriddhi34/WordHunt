from flask import Flask, request, jsonify
from twilio.rest import Client
from dotenv import load_dotenv
import os

# Load environment variables from .env file
load_dotenv()

# Get Twilio credentials from environment variables
account_sid = os.getenv('TWILIO_ACCOUNT_SID')
auth_token = os.getenv('TWILIO_AUTH_TOKEN')

# Initialize Twilio client
client = Client(account_sid, auth_token)

app = Flask(__name__)

# Your WhatsApp bot route to echo messages
@app.route('/whatsapp', methods=['POST'])
def whatsapp_reply():
    incoming_msg = request.values.get('Body', '').lower()
    from_number = request.values.get('From')

    # Create a Twilio response message
    response = MessagingResponse()
    response.message(f'You said: {incoming_msg}')

    return str(response)

if __name__ == "__main__":
    app.run(debug=True)

