// it gives the number of unique substrings of length k
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=1e5+5;
unsigned ll p[mx];
int main(){
	p[0]=1;
	for(ll i=1;i<mx;++i){
		p[i]=(p[i-1]*53);
	}
	
	ll n,k;cin >> n >> k;
	string s;cin >> s;
	set <long long> st;
	unsigned ll sum=0;
	for(ll i=0;i<k;++i){
		sum+=(p[k-i-1]*(s[i]));
	}
	st.insert(sum);
	for(ll i=k;i<n;++i){
		sum=(sum-(p[k-1]*(s[i-k])));
		sum=(sum*53);
		sum=(sum+s[i]);
		st.insert(sum);
	}
	cout << st.size() << endl;
}

/*
	~example~

	input:
	7 3
	dogodog

	output:
	4

*/
