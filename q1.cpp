#include <iostream>
#include <cassert> 

using namespace std;

char shiftChar(char letter, int shift_value) {
 
    if (letter >= 'a' && letter <= 'z') {
        // Ensure shift_value is within the range 0 to 25.
        shift_value %= 26; 
        // Adjust negative shift_value to positive equivalent.
        while (shift_value < 0) {
            shift_value += 26; 
        }
        // Apply Caesar cipher encryption for lowercase letters.
        letter = ((letter - 'a' + shift_value) % 26) + 'a';
    } 
   
    else if (letter >= 'A' && letter <= 'Z') {
        // Ensure shift_value is within the range 0 to 25.
        shift_value %= 26; 
        // Adjust negative shift_value to positive.
        while (shift_value < 0) {
            shift_value += 26; 
        }
        // Apply encryption for uppercase letters.
        letter = ((letter - 'A' + shift_value) % 26) + 'A';
    }
  
    return letter;
}

int main() {
    char letter;
    int shift_value;
    cout << "Enter a letter to shift" << endl;
    cin >> letter;
    if (!((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))){

            cout << "invlid input" << endl;

        return 0;
    }
    cout << "Enter an integer to shift the letter by:" << endl;
    cin >> shift_value;

    char shifted_letter = shiftChar(letter, shift_value);

    cout << "Letter " << letter << " was encrypted to " << shifted_letter << endl;

    
    return 0;

}