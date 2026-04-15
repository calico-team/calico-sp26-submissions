#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define si set<int>
#define vvi vector<vector<int>>

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        int p = 2 * (l + w);
        cout << e / p / r << endl;
    }
}
