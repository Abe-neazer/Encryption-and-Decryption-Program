#include <iostream>

using namespace std;


int getDoubleKeyShiftValue(string key1, string key2){
    int match = 0;
    
    // Iterate over characters in both keys.
    for (int i = 0; i < key1.length(); i++) {
        for (int j = 0; j < key2.length(); j++) {
            // adds to match count if characters match.
            if (key1[i] == key2[j]) {
                match++;
            }
        }
    }
    
    // Calculate shift value as modulo of matching count to 26.
    int shift = match % 26;
    
    // Return the calculated shift value.
    return shift;
}



int main() {
    string key1; 
    string key2;
    cout <<"Enter the first key:"<<endl;
    getline(cin,key1);

    cout << "Enter the second key:"<< endl;
    getline(cin,key2);

    int shift_distance = getDoubleKeyShiftValue(key1, key2);
    cout << "The shift distance : " << shift_distance << endl;
    return 0;
}