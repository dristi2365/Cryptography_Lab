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
    long long p, g, a, b;
    int n;
    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter prime number p: ";
        cin >> p;
        cout << "Enter primitive root g: ";
        cin >> g;
        cout << "Enter Alice's private key (a): ";
        cin >> a;
        cout << "Enter Bob's private key (b): ";
        cin >> b;

        long long A = power(g, a, p);
        long long B = power(g, b, p);

        cout << "\nAlice's public key A = g^a mod p = " << A << endl;
        cout << "Bob's public key   B = g^b mod p = " << B << endl;

        long long aliceSecret = power(B, a, p);
        long long bobSecret   = power(A, b, p);

        cout << "\nAlice's shared secret = B^a mod p = " << aliceSecret << endl;
        cout << "Bob's shared secret   = A^b mod p = " << bobSecret   << endl;

        if(aliceSecret == bobSecret)
            cout << "Shared Secret Key = " << aliceSecret << " (Match! Key Exchange Successful)" << endl;
        else
            cout << "Key Exchange Failed!" << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 13" << endl;
    return 0;
}
