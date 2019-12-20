#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(long long (i)=0;(i)<(n);++(i))
#define ref(i,a,b) for (long long (i)=(a); (i)<=(b); ++(i))
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define mp make_pair
const int mx=1e6+5;
struct pt{
    double x,y;
};
bool cmp(pt ak,pt al){
    if(ak.x==al.x)return ak.y<al.y;
    return ak.x<al.x;
}
bool cw(pt a,pt b,pt c){
    return (b.y-a.y)/(b.x-a.x)>(c.y-a.y)/(c.x-a.x);//slope formula
}
bool ccw(pt a,pt b,pt c){
    return (b.y-a.y)/(b.x-a.x)<(c.y-a.y)/(c.x-a.x);//slope formula
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin >> n;
    vector <pt> a;
    a.resize(n);
    for(int i=0;i<n;++i){
        double ax,ay;cin >> ax >> ay;
        a[i].x=ax;
    	a[i].y=ay;
    } 
    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i=1;i<(int)a.size();++i){
    if(i==a.size()-1 or cw(p1,a[i],p2)){
   		 while(up.size()>=2 and !cw(up[up.size()-2],up[up.size()-1],a[i]))
        	up.pop_back();
        up.push_back(a[i]);
    }
    if(i==a.size()-1 or ccw(p1,a[i],p2)){
        while(down.size()>=2 and !ccw(down[down.size()-2],down[down.size()-1],a[i]))
       		down.pop_back();
       	down.push_back(a[i]);		
        	}
    }
    a.clear();
    for(int i=0;i<(int)up.size();++i)
        a.pb(up[i]);
    for(int i=(int)down.size()-2;i>0;--i)
        a.pb(down[i]);
    cout << (int)a.size() << endl;//number of elements
    for(int i=0;i<a.size();++i)
        cout << a[i].x << " " << a[i].y << endl;
}


/*
	~example~
	
	input:
	5
	41 -6
	-24 -74
	-51 -6
	73 17
	-30 -34

	output:
	3
	-24 -74
	73 17
	-51 -6
	
*/


