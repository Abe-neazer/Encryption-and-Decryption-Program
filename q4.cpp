
#include <iostream>
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

string getLayer1MessageDecryption(string message, int method_choice, string key1, string key2) {
    // Calculate shift value based on keys
    int shift_value = getDoubleKeyShiftValue(key1, key2); 

    // Apply decryption based on the chosen method
    if (method_choice == 1) {
        // Decrypt using Caesar cipher with a shift of 13
        for (int i = 0; i < message.length(); i++) {
             message[i] = shiftChar(message[i], -13);
        }
    } else if (method_choice == 2) {
        // Decrypt using custom shift value
        for (int i = 0; i < message.length(); i++) {
             message[i] = shiftChar(message[i], -shift_value);
        }
    }

    // Return the decrypted message
    return message;
}


int main() {
    string encrypted_message;
    string key1;
    string key2;
    int method_choice;
    cout << "Enter the mesage to "<< endl;
    getline(cin,encrypted_message);
    cout << "Enter the methode choice (1 or 2) :"<< endl;
    cin >> method_choice;
    cout << "Enter the first key :"<< endl;
    cin.ignore();
    getline(cin,key1);
    cout << "Enter the second key :"<< endl;
    getline(cin,key2);
    string decrypted_message = getLayer1MessageDecryption(encrypted_message, method_choice, key1, key2);
    cout << "The decrypted message : " << decrypted_message << endl;
    return 0;
}