#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N] , b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1 ; i <= n ; i++){
			int cnt = 0;
			for(int j = 1 ; j <= n ; j++){
				char x;
				cin >> x;
				if(x == '#')
					cnt++;
			}
			a[i] = cnt;
		}
		for(int i = 1 ; i <= n ; i++){
			int cnt = 0;
			for(int j = 1 ; j <= n ; j++){
				char x;
				cin >> x;
				if(x == '#')
					cnt++;
			}
			b[i] = cnt;
		}
		int maxx = 0 , minn = 0;
		for(int i = 1 ; i <= n ; i++){
			maxx += a[i] * b[i];
			minn += max(a[i] , b[i]); 
		}
		cout << maxx << " " << minn << "\n";
	}
	return 0;
}
