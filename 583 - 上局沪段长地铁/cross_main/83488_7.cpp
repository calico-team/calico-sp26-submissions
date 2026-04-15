#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		ll n,m;
		cin>>n>>m;
		ll jc=0; 
		for(ll i=1;i<=n;i++){
			ll hs=jc;
			for(ll o=1;o<=m;o++){
				cout<<hs<<" ";
				hs++;
				hs%=5;
			}
			cout<<endl;
			jc+=2;
			jc%=5;
		}
	}
	return 0;
}
/*
0 1 2 3 4 0 1 2 3 4
2 3 4 0 1 2 3 4 0 1 
4 0 1 2 3 4 0 1 2 3
1 2 3
3 4 0
0 1 2
*/
