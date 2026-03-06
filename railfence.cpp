#include<iostream>
#include<string>
using namespace std;

string encrypt(string text, int rails) {
    string fence[10];
    int i;
    for(i = 0; i < rails; i++) fence[i] = "";
    int rail = 0;
    int direction = 1;
    for(i = 0; i < text.length(); i++) {
        fence[rail] += text[i];
        if(rail == 0) direction = 1;
        else if(rail == rails - 1) direction = -1;
        rail += direction;
    }
    string result = "";
    for(i = 0; i < rails; i++)
        result += fence[i];
    return result;
}

string decrypt(string text, int rails) {
    int len = text.length();
    int railLen[10];
    int i;
    for(i = 0; i < rails; i++) railLen[i] = 0;
    int rail = 0;
    int direction = 1;
    for(i = 0; i < len; i++) {
        railLen[rail]++;
        if(rail == 0) direction = 1;
        else if(rail == rails - 1) direction = -1;
        rail += direction;
    }
    string fence[10];
    int idx = 0;
    for(i = 0; i < rails; i++) {
        fence[i] = text.substr(idx, railLen[i]);
        idx += railLen[i];
    }
    string result = "";
    int railIdx[10];
    for(i = 0; i < rails; i++) railIdx[i] = 0;
    rail = 0;
    direction = 1;
    for(i = 0; i < len; i++) {
        result += fence[rail][railIdx[rail]++];
        if(rail == 0) direction = 1;
        else if(rail == rails - 1) direction = -1;
        rail += direction;
    }
    return result;
}

int main() {
    string plaintext;
    int rails;
    int n;
    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter plaintext: ";
        cin.ignore();
        getline(cin, plaintext);
        cout << "Enter number of rails: ";
        cin >> rails;
        string encrypted = encrypt(plaintext, rails);
        string decrypted = decrypt(encrypted, rails);
        cout << "Encrypted: " << encrypted << endl;
        cout << "Decrypted: " << decrypted << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 5" << endl;
    return 0;
}
