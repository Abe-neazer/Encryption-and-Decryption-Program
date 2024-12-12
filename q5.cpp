
#include <iostream>
#include <string>

using namespace std;

char shiftChar(char letter, int shift_value) {
    if (letter >= 'a' && letter <= 'z') {
        shift_value %= 26;
        while (shift_value < 0) {
            shift_value += 26;
        }
        letter = ((letter - 'a' + shift_value) % 26) + 'a';
    } 
    else if (letter >= 'A' && letter <= 'Z') {
        shift_value %= 26;
        while (shift_value < 0) {
            shift_value += 26;
        }
        letter = ((letter - 'A' + shift_value) % 26) + 'A';
    }
    return letter;
}

string getLayer2MessageEncryption(string encrypted_message, string key_phrase) {
    // Decode the key phrase to extract the decryption key
    string decoded_key="";
    int key1 = key_phrase.length();

    // Extract the decryption key by taking the first letter of each word in the key phrase
    for (int i = 0; i < key1; i++) {
        if (i == 0 || key_phrase[i - 1] == ' ') {
            decoded_key += key_phrase[i];
        }
    }

    // Initialize variables for decryption process
    string decrypted_message = encrypted_message;
    int decrypted_message1 = decrypted_message.length();
    int key_position = 0;
    int shift = decoded_key.length();

    // Decrypt each character of the encrypted message
    for (int i = 0; i < decrypted_message1; i++) {
        // Skip non-alphabetic characters
        if (!(decrypted_message[i] >= 'a' && decrypted_message[i] <= 'z') && !(decrypted_message[i] >= 'A' && decrypted_message[i] <= 'Z')) {
            continue;
        }
        
        // Determine the shift amount based on the key character's case
        if (decoded_key[key_position] >= 'A' && decoded_key[key_position] <= 'Z' ) {
            // Shift uppercase letters
            decrypted_message[i] = shiftChar(decrypted_message[i], decoded_key[key_position] - 'A');
            key_position = (key_position + 1) % shift; 
        } else if (decoded_key[key_position] >= 'a' && decoded_key[key_position] <= 'z' ) {
            // Shift lowercase letters
            decrypted_message[i] = shiftChar(decrypted_message[i], decoded_key[key_position] - 'a');
            key_position = (key_position + 1) % shift; 
        }
    }

    // Return the decrypted message
    return decrypted_message;
}


int main() {
    string message;
    getline(cin, message);
    string key_phrase;
    getline(cin, key_phrase);
    string encrypted_message = getLayer2MessageEncryption(message, key_phrase);
    cout << "The encrypted message: " << encrypted_message << endl;
   

    return 0;
}
