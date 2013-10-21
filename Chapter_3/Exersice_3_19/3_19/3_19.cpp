/*
 * File: 3_19.cpp
 * -------------
 * Building on 3_18 this program includes a function that takes 
 * the encripted message and decrypts it using the original encription.  
 * Input still must be caps.
 *
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string encodeLetterSubCipher(string str, string key);
string invertKey(string key);

/* main */
int main() {
    string key = getLine("Enter 26-letter key: ");
    while (true) {
        string str = getLine("Enter a message: ");
            if (str == "") break;
        string encryptedStr = encodeLetterSubCipher(str, key);
        string decryptedStr = encodeLetterSubCipher(encryptedStr, invertKey(key));
        cout << "Encoded message: " << encryptedStr << endl;
        cout << "Decrypted message: " << decryptedStr << endl;

        
    }
    cout << "Program End.";
    
    return 0;
}

string encodeLetterSubCipher(string str, string key) {
    string encoded;
    for (int i = 0; i < str.length(); i++) {
        int strPosToEncode = str.at(i) - 'A';
        if (isupper(str.at(i))) encoded += key.at(strPosToEncode);
        else encoded += str.at(i);
    }
    return encoded;
}

string invertKey(string key) {
    string decryptionKey;
    for (int i = 0; i < key.length(); i++) {
        int keyPos = key.find('A' + i, 1);
        if (keyPos == -1)
            decryptionKey += 'A';
        else decryptionKey += keyPos + 'A';
        
    }
    
    
    return decryptionKey;
}
