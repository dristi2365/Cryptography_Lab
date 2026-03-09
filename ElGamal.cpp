#include<iostream>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while(exp > 0) {
        if(exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p, g, x, k, message;
    int n;
    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter prime number p: ";
        cin >> p;
        cout << "Enter primitive root g: ";
        cin >> g;
        cout << "Enter receiver's private key x: ";
        cin >> x;
        cout << "Enter random secret key k (for encryption): ";
        cin >> k;
        cout << "Enter message M (number less than " << p << "): ";
        cin >> message;

        // Key Generation
        long long y = power(g, x, p);

        cout << "\n--- Key Generation ---" << endl;
        cout << "Public Key  (p, g, y) = (" << p << ", " << g << ", " << y << ")" << endl;
        cout << "Private Key x = " << x << endl;

        // Encryption
        long long C1 = power(g, k, p);
        long long C2 = (message * power(y, k, p)) % p;

        cout << "\n--- Encryption ---" << endl;
        cout << "C1 = g^k mod p = " << C1 << endl;
        cout << "C2 = M * y^k mod p = " << C2 << endl;
        cout << "Ciphertext (C1, C2) = (" << C1 << ", " << C2 << ")" << endl;

        // Decryption
        long long S         = power(C1, x, p);
        long long S_inverse = power(S, p - 2, p);
        long long decrypted = (C2 * S_inverse) % p;

        cout << "\n--- Decryption ---" << endl;
        cout << "S = C1^x mod p = " << S << endl;
        cout << "S_inverse = S^(p-2) mod p = " << S_inverse << endl;
        cout << "Decrypted Message M = C2 * S_inverse mod p = " << decrypted << endl;

        if(message == decrypted)
            cout << "ElGamal Encryption-Decryption Successful!" << endl;
        else
            cout << "ElGamal Encryption-Decryption Failed!" << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 15" << endl;
    return 0;
}
