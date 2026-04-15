#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int w,l,e,r;
		cin >> w >> l >> e >> r;
		cout << (e/(r*2*(w+l)));
		cout << "\n";
	}
}
