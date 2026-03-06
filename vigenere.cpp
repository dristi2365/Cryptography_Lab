#include<iostream>
#include<string>
using namespace std;

string encrypt(string text, string key) {
    string result = "";
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char((text[i] - 'A' + toupper(key[j % key.length()]) - 'A') % 26 + 'A');
            j++;
        } else if (islower(text[i])) {
            result += char((text[i] - 'a' + tolower(key[j % key.length()]) - 'a') % 26 + 'a');
            j++;
        } else {
            result += text[i];
        }
    }
    return result;
}

string decrypt(string text, string key) {
    string result = "";
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char((text[i] - 'A' - (toupper(key[j % key.length()]) - 'A') + 26) % 26 + 'A');
            j++;
        } else if (islower(text[i])) {
            result += char((text[i] - 'a' - (tolower(key[j % key.length()]) - 'a') + 26) % 26 + 'a');
            j++;
        } else {
            result += text[i];
        }
    }
    return result;
}

int main() {
    string plaintext, key;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter keyword: ";
    cin >> key;
    string encrypted = encrypt(plaintext, key);
    string decrypted = decrypt(encrypted, key);
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 3" << endl;
    return 0;
}
