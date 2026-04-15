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
    int n, p, r, k; 
    cin >> n >> p >> r >> k;
    vector<int> s(n);  
    int sum = 0; 

    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a; 
        sum += a; 
        s[i] = a; 
    }

    if (p > sum) {
        cout << "nah i'd win\n";
        return; 
    }

    bool flag = true; 

    for (int i = 0; i < n; i++) {
        if (s[i] > p) {
            flag = false; 
            break; 
        }
        else {
            p -= s[i]; 
        }
        if ((i + 1) % k == 0) p += r; 
    }

    if (flag) {
        cout << "nah i'd win\n";
    }
    else {
        cout << "nah i'd lose\n";
    }
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