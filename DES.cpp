#include<iostream>
#include<string>
#include<bitset>
using namespace std;

// Initial Permutation Table
int IP[] = {58,50,42,34,26,18,10,2,
            60,52,44,36,28,20,12,4,
            62,54,46,38,30,22,14,6,
            64,56,48,40,32,24,16,8,
            57,49,41,33,25,17,9,1,
            59,51,43,35,27,19,11,3,
            61,53,45,37,29,21,13,5,
            63,55,47,39,31,23,15,7};

// Final Permutation Table
int FP[] = {40,8,48,16,56,24,64,32,
            39,7,47,15,55,23,63,31,
            38,6,46,14,54,22,62,30,
            37,5,45,13,53,21,61,29,
            36,4,44,12,52,20,60,28,
            35,3,43,11,51,19,59,27,
            34,2,42,10,50,18,58,26,
            33,1,41,9,49,17,57,25};

// Expansion Table
int E[] = {32,1,2,3,4,5,4,5,6,7,8,9,
           8,9,10,11,12,13,12,13,14,15,16,17,
           16,17,18,19,20,21,20,21,22,23,24,25,
           24,25,26,27,28,29,28,29,30,31,32,1};

// Permutation Table
int P[] = {16,7,20,21,29,12,28,17,
           1,15,23,26,5,18,31,10,
           2,8,24,14,32,27,3,9,
           19,13,30,6,22,11,4,25};

// PC1 Table
int PC1[] = {57,49,41,33,25,17,9,1,
             58,50,42,34,26,18,10,2,
             59,51,43,35,27,19,11,3,
             60,52,44,36,63,55,47,39,
             31,23,15,7,62,54,46,38,
             30,22,14,6,61,53,45,37,
             29,21,13,5,28,20,12,4};

// PC2 Table
int PC2[] = {14,17,11,24,1,5,3,28,
             15,6,21,10,23,19,12,4,
             26,8,16,7,27,20,13,2,
             41,52,31,37,47,55,30,40,
             51,45,33,48,44,49,39,56,
             34,53,46,42,50,36,29,32};

// S-Boxes
int SBOX[8][4][16] = {
    {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
     {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
     {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
     {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
    {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
     {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
     {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
     {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
    {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
     {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
     {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
     {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
    {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
     {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
     {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
     {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
    {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
     {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
     {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
     {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
    {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
     {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
     {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
     {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
    {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
     {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
     {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
     {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
    {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
     {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
     {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
     {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
};

// Left shift schedule
int shifts[] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

string permute(string s, int* table, int n) {
    string result = "";
    for(int i = 0; i < n; i++)
        result += s[table[i] - 1];
    return result;
}

string leftShift(string s, int n) {
    return s.substr(n) + s.substr(0, n);
}

string xorStr(string a, string b) {
    string result = "";
    for(int i = 0; i < a.size(); i++)
        result += ((a[i] - '0') ^ (b[i] - '0')) ? "1" : "0";
    return result;
}

string sboxSub(string s) {
    string result = "";
    for(int i = 0; i < 8; i++) {
        string block = s.substr(i * 6, 6);
        int row = (block[0] - '0') * 2 + (block[5] - '0');
        int col = (block[1]-'0')*8 + (block[2]-'0')*4 +
                  (block[3]-'0')*2 + (block[4]-'0');
        result += bitset<4>(SBOX[i][row][col]).to_string();
    }
    return result;
}

void generateKeys(string key, string subkeys[]) {
    string k = permute(key, PC1, 56);
    string C = k.substr(0, 28);
    string D = k.substr(28, 28);
    for(int i = 0; i < 16; i++) {
        C = leftShift(C, shifts[i]);
        D = leftShift(D, shifts[i]);
        subkeys[i] = permute(C + D, PC2, 48);
    }
}

string feistel(string R, string key) {
    string expanded = permute(R, E, 48);
    string xored    = xorStr(expanded, key);
    string subbed   = sboxSub(xored);
    return permute(subbed, P, 32);
}

string desEncrypt(string plaintext, string subkeys[]) {
    string ip  = permute(plaintext, IP, 64);
    string L   = ip.substr(0, 32);
    string R   = ip.substr(32, 32);
    for(int i = 0; i < 16; i++) {
        string newR = xorStr(L, feistel(R, subkeys[i]));
        L = R;
        R = newR;
    }
    return permute(R + L, FP, 64);
}

string desDecrypt(string ciphertext, string subkeys[]) {
    string reversedKeys[16];
    for(int i = 0; i < 16; i++)
        reversedKeys[i] = subkeys[15 - i];
    return desEncrypt(ciphertext, reversedKeys);
}

string strToBin(string s) {
    string result = "";
    for(int i = 0; i < s.size(); i++)
        result += bitset<8>(s[i]).to_string();
    return result;
}

string binToStr(string b) {
    string result = "";
    for(int i = 0; i < b.size(); i += 8)
        result += char(bitset<8>(b.substr(i, 8)).to_ulong());
    return result;
}

int main() {
    string plaintext, key;
    int n;
    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter plaintext (exactly 8 characters): ";
        cin >> plaintext;
        cout << "Enter key (exactly 8 characters): ";
        cin >> key;

        if(plaintext.size() != 8 || key.size() != 8) {
            cout << "Error! Plaintext and key must be exactly 8 characters." << endl;
            n--;
            continue;
        }

        string binPlain = strToBin(plaintext);
        string binKey   = strToBin(key);

        string subkeys[16];
        generateKeys(binKey, subkeys);

        string binCipher    = desEncrypt(binPlain, subkeys);
        string binDecrypted = desDecrypt(binCipher, subkeys);

        cout << "\nPlaintext  : " << plaintext << endl;
        cout << "Key        : " << key << endl;
        cout << "Encrypted  (binary): " << binCipher << endl;
        cout << "Decrypted  : " << binToStr(binDecrypted) << endl;

        if(plaintext == binToStr(binDecrypted))
            cout << "DES Encryption-Decryption Successful!" << endl;
        else
            cout << "DES Encryption-Decryption Failed!" << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 17" << endl;
    return 0;
}

