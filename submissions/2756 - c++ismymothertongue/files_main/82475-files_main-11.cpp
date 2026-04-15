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
		string a, b;
		cin >> a >> b;
		int x = 0;
		for (int i = 0; i < a.size(); i++){
			if (x < b.size() && a[i] == b[x]){
				x += 1;
			}
			else {
				a[i] = '#';
			}
		}
		cout << a << endl;
	}
}
