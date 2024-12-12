

#include <iostream>
#include <string>

using namespace std;
bool onlyletterchecker(string letter) {
    char c;

    for (int i = 0; i < letter.length(); i++) {
        c = letter[i];
       
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c == ' ') || c == '!')) {
            return false; 
        }
    }
    return true; 
}
bool validateint(string number){
        int N = number.length();

        if (N == 0)
        {
            return false;
        }
    if (!(number[0]>= 48 && number[0]<= 57)){
        return false;
    }
    for (int i = 1; i < N; i++){
         if (number[i]< '0' && number[0]> '9'){
        return false;
              }
    }

    return true;
}

char shiftChar(char letter, int shift_value) {
    if (letter >= 'a' && letter <= 'z') {
        shift_value %= 26; 
        while (shift_value < 0) {
            shift_value += 26; 
        }
        letter = ((letter - 'a' + shift_value) % 26) + 'a';
    } else if (letter >= 'A' && letter <= 'Z') {
        shift_value %= 26; 
        while (shift_value < 0) {
            shift_value += 26; 
        }
        letter = ((letter - 'A' + shift_value) % 26) + 'A';
    }
    return letter;
}

int getDoubleKeyShiftValue(string key1, string key2){
       
        int match = 0;

        for (int i = 0; i < key1.length(); i++)
        {
            
            for (int j = 0; j < key2.length(); j++){

                
                if (key1[i] == key2[j]){

                    match++;
                    
                }
            }
            
        }
        
          int shift =  match % 26;
        return shift;
}
string getLayer1MessageEncryption(string message, int method_choice, string key1, string key2){

    int shift_value = getDoubleKeyShiftValue(key1, key2); 


    if(method_choice == 1) {
       
        for (int i = 0; i < message.length(); i++) {
             message[i] = shiftChar(message[i], 13);
        }
    }
    else if (method_choice == 2){

    for (int i = 0; i < message.length(); i++) {
             message[i] = shiftChar(message[i], shift_value);
        }
    }
    return message;
}
string getLayer1MessageDecryption(string message, int method_choice, string key1, string key2){
int shift_value = getDoubleKeyShiftValue(key1, key2); 


    if(method_choice == 1) {
       
        for (int i = 0; i < message.length(); i++) {
             message[i] = shiftChar(message[i], -13);
        }
    }
    else if (method_choice == 2){

    for (int i = 0; i < message.length(); i++) {
             message[i] = shiftChar(message[i], - shift_value);
        }
    }
    return message;
}
string getLayer2MessageEncryption(string encrypted_message, string key_phrase) {
    string decoded_key="";
    int key1 = key_phrase.length();

    
    for (int i = 0; i < key1; i++) {
        if (i == 0 || key_phrase[i - 1] == ' ') {
            decoded_key += key_phrase[i];

        }
    }
 
   

    string decrypted_message = encrypted_message;

    int decrypted_message1 = decrypted_message.length();
  
    int key_position = 0;
    int shift = decoded_key.length();
     
    
    for (int i = 0; i < decrypted_message1; i++) {
        
        if (!(decrypted_message[i] >= 'a' && decrypted_message[i] <= 'z') && !(decrypted_message[i] >= 'A' && decrypted_message[i] <= 'Z'))
     {
        continue;
     }
        

        if (decoded_key[key_position] >= 'A' && decoded_key[key_position] <= 'Z' ) {
            decrypted_message[i] = shiftChar(decrypted_message[i], decoded_key[key_position] - 'A');
            key_position = (key_position + 1) % shift; 
        } else if (decoded_key[key_position] >= 'a' && decoded_key[key_position] <= 'z' ) {
            decrypted_message[i] = shiftChar(decrypted_message[i], decoded_key[key_position] - 'a');
            key_position = (key_position + 1) % shift; 
        }
    }

    return decrypted_message;
}
string getLayer2MessageDecryption(string encrypted_message, string key_phrase) {
    string decoded_key="";
    int key1 = key_phrase.length();

    
    for (int i = 0; i < key1; i++) {
        if (i == 0 || key_phrase[i - 1] == ' ') {
            decoded_key += key_phrase[i];

        }
    }
 
   

    string decrypted_message = encrypted_message;

    int decrypted_message1 = decrypted_message.length();
  
    int key_position = 0;
    int shift = decoded_key.length();
     
    
    for (int i = 0; i < decrypted_message1; i++) {
        
        if (!(decrypted_message[i] >= 'a' && decrypted_message[i] <= 'z') && !(decrypted_message[i] >= 'A' && decrypted_message[i] <= 'Z'))
     {
        continue;
     }
        

        if (decoded_key[key_position] >= 'A' && decoded_key[key_position] <= 'Z' ) {
            decrypted_message[i] = shiftChar(decrypted_message[i], -(decoded_key[key_position] - 'A'));
            key_position = (key_position + 1) % shift; 
        } else if (decoded_key[key_position] >= 'a' && decoded_key[key_position] <= 'z' ) {
            decrypted_message[i] = shiftChar(decrypted_message[i], - (decoded_key[key_position] - 'a'));
            key_position = (key_position + 1) % shift; 
        }
    }

    return decrypted_message;
}
string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase){
    
    if (message.empty()) {
        return "";
    }
    
    
    if (method_choice != 1 && method_choice != 2) {
        return message;
    }

    
    if (method_choice == 2 && (key1.empty() || key2.empty())) {
        return message;
    }

    
    if (key_phrase.empty()) {
        return message;
    }

   
    for (int i = 0; i < key_phrase.length(); ++i) {
    char ch = key_phrase[i];
    if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' ' || (ch >= 48 && ch <= 57) )) {
        return message;
    }
}


   
    message = getLayer1MessageEncryption(message, method_choice, key1, key2);

    
    message = getLayer2MessageEncryption(message, key_phrase);

    return message;
}

string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase){
    
    if (message.empty()) {
        return "";
    }
    
    
    if (method_choice != 1 && method_choice != 2) {
        return message;
    }

    
    if (method_choice == 2 && (key1.empty() || key2.empty())) {
        return message;
    }

    
    if (key_phrase.empty()) {
        return message;
    }

   
    for (int i = 0; i < key_phrase.length(); ++i) {
    char ch = key_phrase[i];
    if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' ' || (ch >= 48 && ch <= 57) )) {
        return message;
    }
}


   
    message = getLayer1MessageDecryption(message, method_choice, key1, key2);

    
    message = getLayer2MessageDecryption(message, key_phrase);

    return message;
}

// Main function of the program
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare variables for user choices and input
    int choice = 0;                 // Main menu choice
    int methode_choice = 0;        // Encryption method choice
    int choice4 = 0;                // Layer selection for chain encryption
    string key1, key2, key_phrase, message, decrypt, message_4, choice1, methode_choice1; // Variables for keys, message, and choices
  
    // Start a loop to display the menu and handle user input
    do {
        // Display menu options
        cout << "Please input 1-7 followed by enter to navigate the menu:" << endl
             << "1. Set Encryption Key 1" << endl
             << "2. Set Encryption Key 2" << endl
             << "3. Set Key Phrase" << endl
             << "4. Select Encryption Method" << endl
             << "5. Encrypt Message" << endl
             << "6. Decrypt Message" << endl
             << "7. Exit Program" << endl;
        
        // Read user input for menu choice
        getline(cin, choice1);
        
        // Validate and convert the user input to an integer
        if (!validateint(choice1)) {
            // Handle invalid input
        } else {
            choice = stoi(choice1);
        }

        // Check if the choice is within valid range
        if (!(choice >= 1 && choice <= 7)) {
            cout << "Invalid input" << endl;
        }

        // If-else statements to handle different menu choices
        if (choice == 1) {
            // Set Encryption Key 1
            // Prompt user to enter the first key
            do {
                cout << "Enter First key: " << endl;
                getline(cin, key1);

                // Check if the key is empty
                if (key1.empty()) {
                    cout << "Invalid key" << endl;
                }
            } while (key1.empty());

            cout << "Successfully set first encryption key to " << key1 << endl;
        } else if (choice == 2) {
            // Set Encryption Key 2
            // Prompt user to enter the second key
            do {
                cout << "Enter Second key: " << endl;
                getline(cin, key2);

                // Check if the key is empty
                if (key2.empty()) {
                    cout << "Invalid key" << endl;
                }
            } while (key2.empty());

            cout << "Successfully set second encryption key to " << key2 << endl;
        } else if (choice == 3) {
            // Set Key Phrase
            // Prompt user to enter the key phrase
            do {
                cout << "Enter keyphrase:" << endl;
                getline(cin, key_phrase);

                // Validate the key phrase
                if (key_phrase.empty() || !onlyletterchecker(key_phrase)) {
                    cout << "Invalid keyphrase" << endl;
                }
            } while (key_phrase.empty() || !onlyletterchecker(key_phrase));

            cout << "Successfully set encryption keyphrase to " << key_phrase << endl;
        } else if (choice == 4) {
            // Select Encryption Method
            // Prompt user to choose encryption technique
            do {
                cout << "Please input 1-3 to decide encryption technique." << endl
                     << "1. Layer 1 Message Encryption" << endl
                     << "2. Layer 2 Message Encryption" << endl
                     << "3. Chain Encryption" << endl;

                // Read user input for encryption technique choice
                getline(cin, message_4);

                // Validate and convert the user input to an integer
                if (!validateint(message_4)) {
                    cout << "Invalid encryption choice " << endl;
                    continue;
                } else {
                    choice4 = stoi(message_4);
                }

                // Check if the choice is within valid range
                if (!(choice4 == 1 || choice4 == 2 || choice4 == 3)) {
                    cout << "Invalid encryption choice " << endl;
                }
            } while ((!validateint(message_4))||!(choice4 == 1 || choice4 == 2 || choice4 == 3));

            cout << "Successfully set encryption type to " << choice4 << endl;

            // If the chosen encryption method requires further selection
            if (choice4 == 1 || choice4 == 3) {
                // Prompt user to choose Layer-1 encryption technique
                do {
                    cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl
                         << "1. Shift by 13" << endl
                         << "2. Shift by mixed keys" << endl;

                    // Read user input for Layer-1 encryption technique choice
                    getline(cin, methode_choice1);

                    // Validate and convert the user input to an integer
                    if (!validateint(methode_choice1)) {
                        cout << "Invalid encryption choice " << endl;
                        continue;
                    } else {
                        methode_choice = stoi(methode_choice1);
                    }

                    // Check if the choice is within valid range
                    if (!(methode_choice == 1 || methode_choice == 2)) {
                        cout << "Invalid encryption choice " << endl;
                    }
                } while (!(methode_choice == 1 || methode_choice == 2));
            }
        } else if (choice == 5) {
            // Encrypt Message
            // Check if all required parameters are set
            if (key1.empty() || key2.empty() || key_phrase.empty() || !(choice4 == 1 || choice4 == 2 || choice4 == 3)) {
                cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;
                break;
            }

            // Prompt user to enter the message to encrypt
            cout << "Enter your message to encrypt:" << endl;
            getline(cin, message);

            // Perform encryption based on the chosen method
            if (choice4 == 1) {
                if (methode_choice == 1) {
                    cout << getLayer1MessageEncryption(message, methode_choice, key1, key2) << endl;
                } else if (methode_choice == 2) {
                    cout << getLayer1MessageEncryption(message, methode_choice, key1, key2) << endl;
                }
            } else if (choice4 == 2) {
                cout << getLayer2MessageEncryption(message, key_phrase) << endl;
            } else if (choice4 == 3) {
                cout << getChainEncryption(message, methode_choice, key1, key2, key_phrase) << endl;
            }
        } else if (choice == 6) {
            // Decrypt Message
            // Check if all required parameters are set
            if (key1.empty() || key2.empty() || key_phrase.empty() || !(choice4 == 1 || choice4 == 2 || choice4 == 3)) {
                cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;
                break;
            }

            // Prompt user to enter the message to decrypt
            cout << "Enter your message to decrypt:" << endl;
            getline(cin, decrypt);

            // Perform decryption based on the chosen method
            if (choice4 == 1) {
                if (methode_choice == 1) {
                    cout << getLayer1MessageDecryption(decrypt, methode_choice, key1, key2) << endl;
                } else if (methode_choice == 2) {
                    cout << getLayer1MessageDecryption(decrypt, methode_choice, key1, key2) << endl;
                }
            } else if (choice4 == 2) {
                cout << getLayer2MessageDecryption(decrypt, key_phrase) << endl;
            } else if (choice4 == 3) {
                cout << getChainDecryption(decrypt, methode_choice, key1, key2, key_phrase) << endl;
            }
        }
        
        // Continue looping until the user chooses to exit the program
    } while (choice != 7);

    // Exit message
    cout <<"Goodbye.\n";

    return 0; 
}

