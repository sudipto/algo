#include <iostream>

using namespace std;

typedef long long ll;

// Function to compute a^b mod m
ll modulo(ll a, ll b, ll m)
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

int main()
{
    ll p, g;
    cout << "Enter p and q: ";
    cin >> p >> g;
    
    ll a, b;
    // choose private keys
    a = rand();
    b = rand();
    
    ll A, B;
    // compute public key for A
    A = modulo(g, a, p);
    // compute public key for B
    B = modulo(g, b, p);
    
    ll sa, sb;
    // compute the shared private key
    sa = modulo(B, a, p);
    sb = modulo(A, b, p);
    
    cout << "The public key for A: " << A << endl;
    cout << "The public key for B: " << B << endl;
    cout << "The shared private key for A: " << sa << endl;
    cout << "The shared private key for B: " << sb << endl;
    
    return 0;
}
