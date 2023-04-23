#include <bits/stdc++.h>
using namespace std;

int inv(int a,int n) {
	for(int i=0;;i++) {
		if((n*i+1)%a==0) {return (n*i+1)/a;}
	}
	return -1;
}

int pow(int a,int b,int n) {
	int ans=1;
	for(int i=0;i<b;i++) {
		ans=ans*a;
		ans=ans%n;
	}
	return ans;
}

int main() {
	int p,q;
	cin>>p;
	cin>>q;
	int n=p*q;
	int phi=(p-1)*(q-1);
	string in;
	cin>>in;
	int len=in.size();
	cout<<"Message: "<<in<<'\n';
	int e=17;
	int d=inv(e,phi);
	string cipher="",plain="";
	for(int i=0;i<len;i++){
		long c=(long)pow(in[i]-65,e,n)%n;
		cipher+=(char)(c+'A');
	}
	for(int i=0;i<len;i++){
		long pl=(long)pow(cipher[i]-'A',d,n)%n;
		plain+=(char)(pl+'A');
	}
	cout<<plain;

	return 0;
}
