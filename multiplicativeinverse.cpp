#include<iostream>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int extendedGCD(int a, int m, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return m;
    }
    int x1, y1;
    int g = extendedGCD(m % a, a, x1, y1);
    x = y1 - (m / a) * x1;
    y = x1;
    return g;
}

int multiplicativeInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, x, y);
    if(g != 1) {
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    int a, m;
    int n;
    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter integer a: ";
        cin >> a;
        cout << "Enter modulus m: ";
        cin >> m;
        int result = multiplicativeInverse(a, m);
        if(result == -1)
            cout << "Inverse of " << a << " mod " << m << " does not exist (not coprime)" << endl;
        else
            cout << "Multiplicative Inverse of " << a << " mod " << m << " = " << result << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 8" << endl;
    return 0;
}
