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

long long gcd(long long a, long long b) {
    while(b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long extendedGCD(long long a, long long m, long long &x, long long &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return m;
    }
    long long x1, y1;
    long long g = extendedGCD(m % a, a, x1, y1);
    x = y1 - (m / a) * x1;
    y = x1;
    return g;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extendedGCD(a, m, x, y);
    if(g != 1)
        return -1;
    return (x % m + m) % m;
}

int main() {
    long long p, q, e, message;
    int n;
    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter prime numbers p and q: ";
        cin >> p >> q;

        long long mod = p * q;
        long long phi = (p - 1) * (q - 1);

        cout << "n = p * q = " << mod << endl;
        cout << "phi(n) = (p-1)*(q-1) = " << phi << endl;

        cout << "Enter public key e (must be coprime to " << phi << "): ";
        cin >> e;

        if(gcd(e, phi) != 1) {
            cout << "Invalid! e is not coprime to phi(n). Try again." << endl;
            n--;
            continue;
        }

        long long d = modInverse(e, phi);

        cout << "\nPublic Key  (e, n) = (" << e << ", " << mod << ")" << endl;
        cout << "Private Key (d, n) = (" << d << ", " << mod << ")" << endl;

        cout << "Enter message (number less than " << mod << "): ";
        cin >> message;

        long long encrypted = power(message, e, mod);
        long long decrypted = power(encrypted, d, mod);

        cout << "\nOriginal Message : " << message  << endl;
        cout << "Encrypted Message: " << encrypted << endl;
        cout << "Decrypted Message: " << decrypted << endl;

        if(message == decrypted)
            cout << "RSA Encryption-Decryption Successful!" << endl;
        else
            cout << "RSA Encryption-Decryption Failed!" << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 14" << endl;
    return 0;
}
