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
        int x;
        cin >> x;
        int mx = 0;
        int mn = 0;
        vector <string> v (x);
        vector <string> v2 (x);
        for (int j = 0; j < x; j++){
			cin >> v[j];
		}
        for (int j = 0; j < x; j++){
			cin >> v2[j];
		}
        for (int j = 0; j < x; j++){
            int a = 0;
            int b = 0;
            for (int k = 0; k < x; k++){
                if (v[j][k] == '#'){
					a += 1;
				}
                if (v2[j][k] == '#'){
					b += 1;
				}
            }
            mx += a * b;
            mn += max(a, b);
        }
        cout << mx << " " << mn << endl;
    }
}
