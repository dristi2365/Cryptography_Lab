#include<iostream>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int g = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

int main() {
    int a, b;
    int n;
    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter value of a: ";
        cin >> a;
        cout << "Enter value of b: ";
        cin >> b;
        int x, y;
        int g = extendedGCD(a, b, x, y);
        cout << "GCD(" << a << ", " << b << ") = " << g << endl;
        cout << "Coefficients: x = " << x << ", y = " << y << endl;
        cout << a << " * (" << x << ") + " << b << " * (" << y << ") = " << g << endl;
        cout << "Verification: " << a*x + b*y << " = " << g << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 10" << endl;
    return 0;
}

