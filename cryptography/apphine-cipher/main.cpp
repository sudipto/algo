#include <bits/stdc++.h>

using namespace std;

#define N 26

int decrypt( int cip, int a, int b, int g) {
	int a_inverse = calc_inverse(a);
	int p;

	return p;
}

int encrypt( string p, int a, int b, int g, int n) {
	int p_num = 0, i = 0, temp;
	int len = p.length();

	while (i < len) {
		temp = 0;
		for ( int j = 0; j < g; j++) {
			temp += (p[i + j] - 'a') * pow(N, g - 1 - j);
		}
		cout << temp;
		p_num += temp;
		i += g;
	}

	int res = (a * p_num + b) % n;

	return res;
}

string convert_to_text(int cip) {
	string cipher_text;

	while (cip > N) {
		int t = cip % N;
		cipher_text.push_back(char('a' + t));
		cip = cip / N;
	}

	cipher_text.push_back(char('a' + cip));

	reverse(cipher_text.begin(), cipher_text.end());

	return cipher_text;
}

int main() {
	string p;
	cout << "Enter string: ";
	cin >> p;

	/**
	 * c = (ap + b) mod n
	 * 
	 * g -> single, digraph, trigraph etc.
	 **/
	int a, b, g, n;
	cout << "Enter a, b, g: ";
	cin >> a >> b >> g;

	int l = p.length();
	n = pow(N, g);

	int c = encrypt( p, a, b, g, n);
	cout << "\nEncrypted cipher value: "<< c;
	cout << "\nEncrypted cipher text: " << convert_to_text(c);

	cout << "\n";

	return 0;
}