#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    vector<ll> b(n);
    b[0] = a[0];
    
    for (int i=1; i<n; i++) {
        ll op1 = b[i-1];               // 选择1：保持不变
        ll op2 = a[i];                 // 选择2：变成a[i]
        ll cost1 = abs(op1 - a[i]);    // 代价1
        ll cost2 = abs(op2 - a[i]);    // 代价2
        
        if (cost1 <= cost2) {
            b[i] = op1;
        } else {
            b[i] = op2;
        }
    }
    
    for (auto x : b) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}