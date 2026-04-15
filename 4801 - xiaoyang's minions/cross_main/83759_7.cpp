#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){cout<<((i*2)+j)%5<<" ";}
		cout<<'\n';
	}	
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	while(t--)solve();
}
