#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>

using namespace std;
#define int long long

int powMod(int base, int exp, int mod) {
    if (exp == 1) return base;
    else if (exp == 0) return 1;
    else if (base < 2) return base;

    int ans = 1;

    while (exp > 0) {
        if (exp % 2) {
            ans *= base;
        }

        base = base * base % mod;
        exp /= 2;
        ans %= mod;
    }
    return ans;
}

string solve() {
    int n, p, r, k; cin >> n >> p >> r >> k;

    int curse = 0;
    bool c = true;
    while (n--) {
        int e; cin >> e;
        p -= e;
        curse++;

        if (p < 0) {
            c = false;
        }
        
        if (curse == k) {
            curse = 0; p += r;
        }
    }

    if (!c) return "nah i'd lose";
    return "nah i'd win";
}


signed main() {
    int t; cin >> t;
    while(t--) {
        cout << solve();
        if (t != 0) cout << endl;
    }

    return 0;
}