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
        int g = gcd(a, b);
        cout << "GCD(" << a << ", " << b << ") = " << g << endl;
        if(g == 1)
            cout << a << " and " << b << " are Coprime." << endl;
        else
            cout << a << " and " << b << " are NOT Coprime." << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 9" << endl;
    return 0;
}
