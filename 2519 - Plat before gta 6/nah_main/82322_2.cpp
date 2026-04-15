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
    int n, p, r, k;
    cin >> n >> p >> r >> k;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int cur = 0;
    for (auto &x : a) {
        p -= x;
        if (p < 0) {
            cout << "nah i'd lose";
            return;
        }
        cur++;
        if (cur == k) {
            p += r;
            cur = 0;
        }
    }
    cout << "nah i'd win";
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