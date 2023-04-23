#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

// Function to find modular inverse of a
long long modInverse(long long a, long long m)
{
    a = a%m;
    for (long long x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

// Function to compute a^b mod m
long long modulo(long long a, long long b, long long m)
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

// Function to find gcd of two numbers
long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// RSA encryption function
void encrypt(long long& ciphertext, long long plaintext,
             long long e, long long n)
{
    ciphertext = modulo(plaintext, e, n);
}

// RSA decryption function
void decrypt(long long& plaintext, long long ciphertext,
             long long d, long long n)
{
    plaintext = modulo(ciphertext, d, n);
}

// Driver code
int main()
{
    long long p, q, n, phi, e, d, plaintext, ciphertext;
    cout << "Enter plaintext: ";
    cin >> plaintext;
    cout << "Enter p, q, e: ";
    cin >> p >> q >> e;

    n = p*q;
    phi = (p-1)*(q-1);

    // Choose an e such that e and phi(n) are coprime
    while (e < phi)
    {
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }

    // Choose a d such that d*e = 1 mod phi
    d = modInverse(e, phi);
    // cout << d << endl;

    encrypt(ciphertext, plaintext, e, n);
    decrypt(plaintext, ciphertext, d, n);

    cout << "Original plaintext: " << plaintext << endl;
    cout << "Encrypted ciphertext: " << ciphertext << endl;
    cout << "Decrypted plaintext: " << plaintext << endl;

    return 0;
}
