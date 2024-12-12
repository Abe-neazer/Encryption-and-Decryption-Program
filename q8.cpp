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


string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase){
    // Check if the message is empty
    if (message.empty()) {
        return "";
    }
    
    // Check if the method_choice is valid
    if (method_choice != 1 && method_choice != 2) {
        return message;
    }

    // Check if method_choice is 2 and key1 or key2 is empty
    if (method_choice == 2 && (key1.empty() || key2.empty())) {
        return message;
    }

    // Check if the key_phrase is empty
    if (key_phrase.empty()) {
        return message;
    }

    // Validate characters in the key_phrase
    for (int i = 0; i < key_phrase.length(); ++i) {
        char ch = key_phrase[i];
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' ' || (ch >= 48 && ch <= 57) )) {
            return message;
        }
    }

    // Apply layer 1 decryption
    message = getLayer1MessageDecryption(message, method_choice, key1, key2);

    // Apply layer 2 decryption
    message = getLayer2MessageDecryption(message, key_phrase);

    // Return the decrypted message
    return message;
}





int main() {
    string message;
    string key1;
    string key2;
    string key_phrase;
    int method_choice;;
    cout << "Enter the mesage to encrpt"<< endl;
    getline(cin,message);
    cout << "Enter the methode choice (1 or 2) :"<< endl;
    cin >> method_choice;
    cout << "Enter the first key :"<< endl;
    cin.ignore();
    getline(cin,key1);
    cout << "Enter the second key :"<< endl;
    getline(cin,key2);
    cout << "Enter the second key phase:"<< endl;
    getline(cin, key_phrase);



    string encrypted_message = getChainDecryption(message, method_choice, key1, key2, key_phrase);
    cout << "The encrypted message : " << encrypted_message << endl;
    return 0;
}