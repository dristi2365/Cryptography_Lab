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

int totient(int n) {
    int count = 0;
    int i;
    for(i = 1; i <= n; i++) {
        if(gcd(i, n) == 1)
            count++;
    }
    return count;
}

int main() {
    int n;
    int loop;
    for(loop = 1; loop <= 3; loop++) {
        cout << "\n--- Input " << loop << " ---" << endl;
        cout << "Enter a positive integer: ";
        cin >> n;
        cout << "Totient phi(" << n << ") = " << totient(n) << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 7" << endl;
    return 0;
}
