#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vector <vector <int>> v (x, vector <int> (y));
		for (int j = 0; j < x; j++){
			for (int k = 0; k < y; k++){
				v[j][k] = (j + k) % 5;
				cout << v[j][k];
				if (k + 1 < y){
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}
