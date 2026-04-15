#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, p, r, k;
    bool possible = true;
    
    if (cin >> n >> p >> r >> k) {
        vector<ll> e(n);
        for (int i = 0; i < n; i++) {
            cin >> e[i];
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            p -= e[i];
            
            if (p < 0) {
                possible = false;
                break;
            }

            count++;

            if (count == k) {
                p += r;
                count = 0;
            }
        }
        
        if (possible) {
            cout << "nah i'd win" << endl;
        } else {
            cout << "nah i'd lose" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}