#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N(1e3+9),MOD(1e9+7),inf(1e18);

int n;
int v1[N],v2[N];

void solve(){
	int mn=0,mx=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		v1[i]=0;
		for(int j=1;j<=n;j++){
			char x;cin >> x;
			if(x=='#')v1[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		v2[i]=0;
		for(int j=1;j<=n;j++){
			char x;cin >> x;
			if(x=='#')v2[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		// cout << v1[i] << " " << v2[i] << "\n";
		mx += v1[i]*v2[i];
		mn += max(v1[i],v2[i]);
	}
	cout << mx << " " << mn << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int q=1;
	cin >> q;
	while(q--)solve();
	return 0;
}