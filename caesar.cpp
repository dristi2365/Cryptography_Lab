#include<iostream>
#include<string>
using namespace std;

string encrypt(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char((text[i] - 'A' + 3) % 26 + 'A');
        else if (islower(text[i]))
            result += char((text[i] - 'a' + 3) % 26 + 'a');
        else
            result += text[i];
    }
    return result;
}

string decrypt(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char((text[i] - 'A' + 23) % 26 + 'A');
        else if (islower(text[i]))
            result += char((text[i] - 'a' + 23) % 26 + 'a');
        else
            result += text[i];
    }
    return result;
}

int main() {
    string plaintext;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    string encrypted = encrypt(plaintext);
    string decrypted = decrypt(encrypted);
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 2" << endl;
    return 0;
}

