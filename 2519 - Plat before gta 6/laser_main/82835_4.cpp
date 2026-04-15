#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <iomanip>
#include <array>
#include <functional>
#include <bitset>
using namespace std;

void baseIO(string s = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (s.size()){
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

// #define int long long
#define all(x) (x).begin(), (x).end()

void solve(){
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;

    vector<vector<int>> pts(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> pts[i][0] >> pts[i][1];
    }

    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        mp[1001 * pts[i][0] + pts[i][1]] = i + 1;
    }

    int x = pts[0][0], y = pts[0][1];
    while (true) {
        x = (x + q) % n;
        y = (y + p) % m;

        if (mp[1001 * x + y] == 0) continue;

        cout << mp[1001 * x + y] - 1;
        break;
    }
}

signed main() {
    baseIO();

    int t;
    cin >> t;
    while (t--){
        solve(), cout << '\n';
    }

    return 0;
}