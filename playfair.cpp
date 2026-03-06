#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char matrix[5][5];
int rowArr[26], colArr[26];

void buildMatrix(string key) {
    bool used[26];
    int i;
    for(i = 0; i < 26; i++) used[i] = false;
    used['J' - 'A'] = true;
    string order = "";
    for(i = 0; i < key.length(); i++) {
        char c = toupper(key[i]);
        if(c == 'J') c = 'I';
        if(!used[c - 'A']) {
            used[c - 'A'] = true;
            order += c;
        }
    }
    for(char c = 'A'; c <= 'Z'; c++) {
        if(!used[c - 'A']) order += c;
    }
    int k = 0;
    for(int r = 0; r < 5; r++)
        for(int j = 0; j < 5; j++) {
            matrix[r][j] = order[k];
            rowArr[order[k] - 'A'] = r;
            colArr[order[k] - 'A'] = j;
            k++;
        }
}

string prepareText(string text) {
    string t = "";
    for(int i = 0; i < text.length(); i++) {
        char c = toupper(text[i]);
        if(c == 'J') c = 'I';
        if(isalpha(c)) t += c;
    }
    string result = "";
    int i = 0;
    while(i < t.length()) {
        result += t[i];
        if(i + 1 < t.length()) {
            if(t[i] == t[i+1]) {
                result += 'X';
            } else {
                result += t[i+1];
                i++;
            }
        }
        i++;
    }
    if(result.length() % 2 != 0) result += 'Z';
    return result;
}

string encrypt(string text) {
    string result = "";
    for(int i = 0; i < text.length(); i += 2) {
        int r1 = rowArr[text[i] - 'A'],   c1 = colArr[text[i] - 'A'];
        int r2 = rowArr[text[i+1] - 'A'], c2 = colArr[text[i+1] - 'A'];
        if(r1 == r2) {
            result += toupper(matrix[r1][(c1+1)%5]);
            result += toupper(matrix[r2][(c2+1)%5]);
        } else if(c1 == c2) {
            result += toupper(matrix[(r1+1)%5][c1]);
            result += toupper(matrix[(r2+1)%5][c2]);
        } else {
            result += toupper(matrix[r1][c2]);
            result += toupper(matrix[r2][c1]);
        }
    }
    return result;
}

string decrypt(string text) {
    string result = "";
    for(int i = 0; i < text.length(); i += 2) {
        int r1 = rowArr[text[i] - 'A'],   c1 = colArr[text[i] - 'A'];
        int r2 = rowArr[text[i+1] - 'A'], c2 = colArr[text[i+1] - 'A'];
        if(r1 == r2) {
            result += tolower(matrix[r1][(c1+4)%5]);
            result += tolower(matrix[r2][(c2+4)%5]);
        } else if(c1 == c2) {
            result += tolower(matrix[(r1+4)%5][c1]);
            result += tolower(matrix[(r2+4)%5][c2]);
        } else {
            result += tolower(matrix[r1][c2]);
            result += tolower(matrix[r2][c1]);
        }
    }
    return result;
}

int main() {
    string plaintext, key;
    cout << "Enter keyword: ";
    cin >> key;
    cin.ignore();
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    buildMatrix(key);
    string prepared = prepareText(plaintext);
    string encrypted = encrypt(prepared);
    string decrypted = decrypt(encrypted);
    cout << "Prepared Text: " << prepared << endl;
    cout << "Encrypted: "     << encrypted << endl;
    cout << "Decrypted: "     << decrypted << endl;
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 4" << endl;
    return 0;
}
