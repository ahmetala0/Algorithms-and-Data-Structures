//it gives the summation of edges weights in the Minimum Spanning Tree
//Kruskal with dsu

#include <bits/stdc++.h>
using namespace std;
#define nd second
#define st first
#define mp make_pair
#define pb push_back
const int mx=1e5+5;
int n,m;
pair <int,int> d[mx];
vector <pair <int,int> > v;
int par[mx],ans=0;
int fnd(int x){
	while(par[x]!=x){
		par[x]=par[par[x]];
		x=par[x];
	}
	return x;
}
void unt(int x,int y){
	int px=fnd(x);
	int py=fnd(y);
	par[px]=par[py];
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<=n+2;++i){
		par[i]=i;
		ans=0;
	}
	for(int i=0;i<m;++i){
		int x,y,z;cin >> x >> y >> z;
		d[i].first=z;
		d[i].second=i;
		v.pb(mp(x,y));
	}
	v.clear();
	sort(d,d+m);
	for(int i=0;i<m;++i){
		int e=d[i].second;
		int bir=v[e].first;
		int iki=v[e].second;
		int pb=fnd(bir);
		int pi=fnd(iki);
		if(pb!=pi){
			unt(bir,iki);
			ans+=d[i].st;
		}
	}	
	cout << ans << endl;
}


/*
	~example~

	input:
	4 5
	1 2 7
	1 4 6
	4 2 9
	4 3 8
	2 3 6

	output:
	19
	
*/