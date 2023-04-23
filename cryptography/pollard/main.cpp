#include <iostream>

using namespace std;

typedef long long int ll;

// Function to find gcd of two numbers
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// Function to compute a^b mod m
ll modulo( ll a, ll b, ll m)
{
    long long res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b & 1)
            res = (res*a) % m;
        b = b>>1;
        a = (a*a) % m;
    }
    return res;
}

ll calcfunc( ll n) {
    return n*n + 1;
}

ll pollardrho(ll n) {
    ll x, y, t;
    
    int iter = 15;
    while (iter--) {
        x = modulo(calcfunc(x), 1, n);
        
        y = modulo(calcfunc(y), 1, n);
        y = modulo(calcfunc(y), 1, n);
        
        t = gcd(abs(x-y), n);
        
        if (t != n || t != 1) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    ll n;
    cout << "Enter n: ";
    cin >> n;
    
    int res = pollardrho(n);
    
    if (res) {
        cout << n << " is prime.\n";
    } else {
        cout << n << " is composite.\n";
    }
    
    return 0;
}