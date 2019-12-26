#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mx=1e6+5;

int segment_tree[4*mx],height[mx],first_time_occuring_in_the_array[mx],has_root[mx],visited[mx];
vector <int> v[mx],euler;
int n,root;

void dfs(int node,int h){//dfs for the euler tour
	visited[node]=1;
	height[node]=h;
	first_time_occuring_in_the_array[node]=euler.size();
	euler.push_back(node);
	for(int i=0;i<v[node].size();++i){
		if(visited[v[node][i]]==0){
			dfs(v[node][i],h+1);
			euler.push_back(node);
		}
	}
}

void build(int x,int l,int r){//building a segment tree for the range minimum query
	if(l==r)segment_tree[x]=euler[l];
	else{
		int mid=(l+r)/2;
		build(2*x,l,mid);
		build(2*x+1,mid+1,r);
		if(height[segment_tree[2*x]]<height[segment_tree[2*x+1]])segment_tree[x]=segment_tree[2*x];
		else segment_tree[x]=segment_tree[2*x+1];
	}
}

int query(int x,int l,int r,int ql,int qr){//range minimum query
	if(ql<=l and qr>=r)return segment_tree[x];
	else if(l>qr or r<ql)return -1;
	int mid=(l+r)/2;
	int left=query(2*x,l,mid,ql,qr);
	int right=query(2*x+1,mid+1,r,ql,qr);
	if(left==-1)return right;
	if(right==-1)return left;
	if(height[left]<height[right])return left;
	else return right;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n;//number of nodes
	for(int i=1;i<=n;++i){
		int q;cin >> q;//number of descendants of the i-th node
		for(int j=0;j<q;++j){
			int num;cin >> num;//taking the descendants of the i-th node 
			v[i].push_back(num);
			v[num].push_back(i);
			has_root[num]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(has_root[i]!=1)root=i;//finding the root of the tree
	}
	euler.push_back(0);//in order to start from the index 1
	dfs(root,1);
	int m=euler.size();
	build(1,1,m);
	int qq;cin>>qq;//queries
	for(int i=0;i<qq;++i){
		int x,y;cin >> x >> y;
		if(first_time_occuring_in_the_array[x]>first_time_occuring_in_the_array[y])swap(x,y);
		cout << query(1,1,m,first_time_occuring_in_the_array[x],first_time_occuring_in_the_array[y]) << endl;//printing the lowest common ancestor of x-th and  y-th node
	}
}

/*
	input:
	7
	3 2 3 4
	0
	3 5 6 7
	0
	0
	0
	0
	2
	5 7
	2 7

	output:
	3
	1

*/
