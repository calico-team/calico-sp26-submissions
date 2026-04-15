#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e18;
const ll MOD = 1e9 + 7;
bool testcases = true;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (3*i+j-4)%5 << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}