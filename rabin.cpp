#include<iostream>
#include<cstdlib>
#include<ctime>
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

bool millerRabin(long long n, long long a) {
    if(n % 2 == 0) return false;
    long long d = n - 1;
    int r = 0;
    while(d % 2 == 0) {
        d /= 2;
        r++;
    }
    long long x = power(a, d, n);
    if(x == 1 || x == n - 1)
        return true;
    int i;
    for(i = 0; i < r - 1; i++) {
        x = (x * x) % n;
        if(x == n - 1)
            return true;
    }
    return false;
}

bool isPrime(long long n, int k) {
    if(n < 2)  return false;
    if(n == 2) return true;
    if(n == 3) return true;
    if(n % 2 == 0) return false;
    srand(time(0));
    int i;
    for(i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 3);
        if(!millerRabin(n, a))
            return false;
    }
    return true;
}

int main() {
    long long n;
    int k;
    int loop;
    for(loop = 1; loop <= 3; loop++) {
        cout << "\n--- Input " << loop << " ---" << endl;
        cout << "Enter a positive integer: ";
        cin >> n;
        cout << "Enter number of iterations (k): ";
        cin >> k;
        if(isPrime(n, k))
            cout << n << " is probably Prime." << endl;
        else
            cout << n << " is NOT Prime (Composite)." << endl;
    }
    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 12" << endl;
    return 0;
}
