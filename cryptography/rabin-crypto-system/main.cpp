#include <iostream>

using namespace std;

typedef long long ll;

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

ll findMinX(ll num[], ll rem[], ll k)
{
    ll x = 1; 
  
    while (true)
    {
        
        int j;
        for (j=0; j<k; j++ )
            if (x%num[j] != rem[j])
               break;
  
        
        if (j == k)
            return x;
  
        x++;
    }
  
    return x;
}

int main()
{
    ll p, q;
        cout << "Enter p and q (should be prime): ";
        cin >> p >> q;

    ll n = p * q;    
    ll x;
    do {
        cout << "Enter plain text (1 < plain text < " << n << ") : ";
        cin >> x;
    } while (x <= 1 && x >= n);
    
    // cipher text
    ll C = modulo(x, 2, n);
    
    // decryption
    ll a1 = modulo(C, (p+1)/4, p);
    ll a2 = p - a1;
    ll b1 = modulo(C, (q+1)/4, q);
    ll b2 = q - a2;
    
    cout << "Cipher Text: " << C << endl;
    
    ll num[]={p,q};
    ll rem[]={a1,b1};
    ll e=2;
    
    cout << "Plain text is: " << findMinX(num, rem, e)<<endl;
    
    rem[0]=a1;
    rem[1]=b2;
    cout << "Plain text is: " << findMinX(num, rem, e)<<endl;
    
    rem[0]=a2;
    rem[1]=b1;
    cout << "Plain text is: " << findMinX(num, rem, e)<<endl;
    
    rem[0]=a2;
    rem[1]=b2;
    cout << "Plain text is: " << findMinX(num, rem, e)<<endl;
    
    return 0;
}
