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

int main() {
    int a, b;
    int n;
    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter first integer: ";
        cin >> a;
        cout << "Enter second integer: ";
        cin >> b;
        cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 6" << endl;
    return 0;
}
