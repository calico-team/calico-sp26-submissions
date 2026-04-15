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
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cout << (i + 3 * j) % 5;
            if (j < m - 1) cout << ' ';
        }
        cout << endl;
    }
}

signed main() {
    baseIO();

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}