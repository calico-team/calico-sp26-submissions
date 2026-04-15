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
 void solve() {
    int l, w, e, r; 
    cin >> l >> w >> e >> r; 
    int p = 2 * l + 2 * w; 
    int x = p * r; 

    cout << e / x << "\n"; 
 }

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

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