#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (auto&i:v) cin >> i;

    for (int i=0; i<n; i++) {
        char x;
        
        cout << v[0] << (i == n-1 ? "":" ");
    }
    cout << endl;
}

int32_t main() {
	int t;
    cin >> t;
    while (t--) solve();
}
