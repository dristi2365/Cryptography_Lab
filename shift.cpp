#include<iostream>
#include<string>
using namespace std;

string encrypt(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char((text[i] - 'A' + shift) % 26 + 'A');
        else if (islower(text[i]))
            result += char((text[i] - 'a' + shift) % 26 + 'a');
        else
            result += text[i];
    }
    return result;
}

string decrypt(string text, int shift) {
    return encrypt(text, (26 - shift) % 26);
}

int main() {
    string plaintext;
    int shift;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter shift key: ";
    cin >> shift;
    string encrypted = encrypt(plaintext, shift);
    string decrypted = decrypt(encrypted, shift);
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 1" << endl;
    return 0;
}
