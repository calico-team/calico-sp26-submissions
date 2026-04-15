#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int l, w, e, r;
	cin >> l >> w >> e >> r;
	
	cout << e/((2*l + 2*w)*r) << endl;
}

int32_t main(){
	int t;
	cin >> t;
	
	for (int i= 0; i < t; i++){
		solve();
	}
}