#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	string a,b;
	cin >> a >> b;
	
	int index = 0;
	for (char i : a){
		if (i == b[index]){
			cout << i;
			index++;
		}
		else{
			cout << "#";
		}
	}
	cout << endl;
}

int32_t main(){
	int t;
	cin >> t;
	
	for (int i= 0; i < t; i++){
		solve();
	}
}