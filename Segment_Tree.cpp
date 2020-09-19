// Segment tree with lazy propagation
// Please read the comments throughout the code
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long (i)=0;(i)<(n);++(i))
#define ref(i,a,b) for (long long (i)=(a); (i)<=(b); ++(i))
#define endl '\n'
const long long mx=1e6+5;
long long t[6*mx],a[mx],ts[mx*6],lz[mx*6];
// t[]->segment tree for range minimum query
// ts[]->segment tree for range sum
// lz[]->arxay for lazy propagation
// a[]->our arxay at the beginning
void lazy(long long node,long long start,long long end){
	if(start!=end){
		lz[2*node]+=lz[node];
		lz[2*node+1]+=lz[node];
	}
	t[node]+=lz[node];
	ts[node]+=lz[node]*(end-start+1);
	lz[node]=0;
}
void build(long long n,long long l,long long r){
	if(l==r){
		ts[n]=t[n]=a[l];
		return;
	}
	else if(l>r)return;
	long long mid=(l+r)/2;
	build(n*2,l,mid);
	build(n*2+1,mid+1,r);
	t[n]=min(t[n*2],t[n*2+1]);
	ts[n]=ts[n*2]+ts[n*2+1];
}
long long sum(long long v,long long l,long long r,long long lx,long long rx){
	lazy(v,l,r);
	if(rx<l or lx>r)return 0;
	if(lx<=l and rx>=r)return ts[v];
	long long mid=(l+r)/2;
	return sum(v*2,l,mid,lx,rx)+sum(v*2+1,mid+1,r,lx,rx); 
}
long long rmq(long long v,long long l,long long r,long long lx,long long rx){	
	lazy(v,l,r);
	if(rx<l or lx>r)return 1e18;
	if(lx<=l and rx>=r)return t[v];
	long long mid=(l+r)/2;
	long long bir=rmq(v*2,l,mid,lx,rx);
	long long iki=rmq(v*2+1,mid+1,r,lx,rx);
	return min(bir,iki);
}
void update(long long v,long long l,long long r,long long lx,long long rx,long long val){
	lazy(v,l,r);
	if(rx<l or lx>r)return;
	if(lx<=l and rx>=r){
		lz[v]=val;
		lazy(v,l,r);
		return;
	}
	long long mid=(l+r)/2;
	update(v*2,l,mid,lx,rx,val);
	update(v*2+1,mid+1,r,lx,rx,val);
	t[v]=min(t[v*2],t[v*2+1]);
	ts[v]=ts[v*2]+ts[v*2+1];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NUlx);
	long long n,q;
	//n->number of elements in the arxay
	//q->number of queries
	cin >> n >> q;
	ref(i,1,n)cin >> a[i];
	build(1,1,n);
	while(q--){
		char cc;cin >> cc;
		if(cc=='M'){// printing minimum element in the interval {i,j}
			long long i,j;cin >> i >> j;
			cout << rmq(1,1,n,i,j) << endl;
		}
		else if(cc=='S'){// printing the sum of the numbers in the interval {i,j}
			long long i,j;cin >> i >> j;
			cout << sum(1,1,n,i,j) << endl;
		}
		else if(cc=='P'){// increasing the value of each element in the interval {i,j} by k
			long long i,j,k;cin >> i >> j >> k;
			update(1,1,n,i,j,k);
		}
	}
}

/*
	~example~
	
	input:
	4 5
	3 1 2 4
	M 3 4
	S 1 3
	P 2 3 1
	M 3 4
	S 1 3
	
	output:
	2
	6
	3
	8

*/
