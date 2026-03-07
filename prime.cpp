#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    int i;
    for(i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    int loop;
    for(loop = 1; loop <= 3; loop++) {
        cout << "\n--- Input " << loop << " ---" << endl;
        cout << "Enter a positive integer: ";
        cin >> n;
        if(isPrime(n))
            cout << n << " is a Prime number." << endl;
        else
            cout << n << " is NOT a Prime number." << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 11" << endl;
    return 0;
}
