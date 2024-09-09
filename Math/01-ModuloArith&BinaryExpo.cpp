#include<bits/stdc++.h>
using namespace std;

/* Modular Arithmetic

(a + b) % m = ( (a%m) + (b%m)) % m;

(a * b) % m = ( (a%m) * (b%m)) % m;

(a - b) % m = ( (a%m) - (b%m) + m) % m;

(a ^ b) best is leetcod pow(x,n) question, striver video soluiton; go & check;

(a ^ b) % m :- Binary exponentiation , (log b)

*/

// ----------------------------------------------------------------------------------------------------------------------------------

const long long MOD = 1e9 + 7;

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    
    if (n % 2 == 0) {
        long long t = power(x, n / 2);
        return (t * t);
    } else {
        long long t = power(x, n / 2);
        t = (t * t);
        return (x * t);
    }
}

// ----------------------------------------------------------------------------------------------------------------------------------


long long binPow(long long a, long long b, long long m) {
    if (b == 0) {
        return 1 % m;
    }

    if (b % 2 == 0) {
        long long t = binPow(a, b / 2, m);
        return (t * t) % m;
    } else {
        long long t = binPow(a, b / 2, m);
        t = (t * t) % m;
        return (a * t) % m;
    }
}

// ----------------------------------------------------------------------------------------------------------------------------------


long long powerI(long long x, long long n) {
    long long result = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }

        x *= x;
        n /= 2;
    }
    
    return result;
}

// ----------------------------------------------------------------------------------------------------------------------------------


long long binPowI(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m; 

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    
    return result;
}


int main() {
    long long a = 4, b = 15, m = 15;
    cout << binPow(a, b, m) << endl; 
    return 0;
}

