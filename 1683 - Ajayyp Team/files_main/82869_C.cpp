#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define N 24
#define maxn 200005
#define INF (int)1e9

void solve(){
	string a,b;
	cin>>a>>b;
	int id=0;
	for(int i=0; i<a.size(); i++){
		if(id==b.size()){
			a[i]='#';
			continue;
		}
		if(a[i]==b[id])id++;
		else a[i]='#';
	}
	cout<<a<<'\n';
}
 
int main(){
	// freopen("in.txt","w",stdout);
	// freopen("out.txt","r",stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t=1;
	cin>>t;
	while(t--) solve();
}