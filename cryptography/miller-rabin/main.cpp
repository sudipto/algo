#include <iostream>

using namespace std;

typedef long long int ll;

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

void breaknum( ll n, ll &m, ll &k) {
    while (n%2 == 0) {
        k++;
        n = n >> 1;
    }
    
    m = n;
    
    //cout << m << " " << k << "\n";
}

ll millerrabintest( ll n, ll m, ll k) {
    ll t = modulo( 2, m, n);
    
    if (t == 1 || t == -1 || t == n-1) {
        return 1;
    }
    
    k--;
    //cout << k;
    while (k--) {
        t = modulo(t, 2, n);
        
        if (t == -1 || t == n-1) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    ll n;
    cout << "Enter n: ";
    cin >> n;
    
    ll m, k;
    m = k = 0;
    breaknum( n-1, m, k);
    
    int res = millerrabintest( n, m, k);
    
    if (res) {
        cout << n << " is prime.\n";
    } else {
        cout << n << " is composite.\n";
    }
    
    return 0;
}