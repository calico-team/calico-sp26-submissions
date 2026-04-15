#include <bits/stdc++.h>
using namespace std;

/**
 * E: Name of event
 * Y: Year of event
 * M: Month of event
 * D: Day of event
 y m d 
 NOV 19 2026 = 2026 11 19 
 */ 
//  void solve() {
//     int l, w, e, r; 
//     cin >> l >> w >> e >> r; 
//     int p = 2 * l + 2 * w; 
//     int x = p * r; 

//     cout << e / x << "\n"; 
//  }

void solve() {
    int k, n, m , p, q; 
    cin >> k >> n >> m >> p >> q;
    int x0, y0; 
    unordered_map<string, int> mp;

    for (int i = 0; i < k; i++) {
        int x, y; 
        cin >> x >> y; 
        if (i == 0) {
            x0 = x; 
            y0 = y; 
        }
        string s = to_string(x) + "," + to_string(y); 
        mp[s] = i; 
    }

    int x = (x0 + q) % n; 
    int y = (y0 + p) % m; 
    int count = 0; 

    while (x != 0 && y != 0) {
        string s = to_string(x) + "," + to_string(y); 
        if (mp.count(s) > 0) {
            cout << mp[s] << "\n";
            return; 
        } 
        x = (x + q) % n; 
        y = (y + p) % m; 
    }
    cout << 0 << "\n"; 
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    cin.ignore();
    while(T--) {
        solve(); 
    }
}