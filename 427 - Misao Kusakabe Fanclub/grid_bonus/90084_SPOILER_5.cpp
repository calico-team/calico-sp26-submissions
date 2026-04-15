// 11:30:11AM 12 Apr 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastIO cin.tie(0); ios::sync_with_stdio(false)

ll calc(int n, vector<ll> a, vector<ll> b) {
    ll pen = 0;
    for(int i = 1; i < n; i++) pen += abs(a[i] - a[i-1]) + abs(b[i] - b[i-1]);
    for(int i = 0; i < n; i++) pen += abs(a[i] - b[i]);

    return pen;
}

int main() {
    fastIO;
    
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<ll> a(n); for(auto &i : a) cin >> i;

        vector<ll> b(n), c(n);
        b[0] = c[0] = a[0];
        for(int i = 1; i < n; i++) {
            b[i] = min(b[i-1], a[i]);
            c[i] = max(c[i-1], a[i]);
        }

        if(calc(n, a, b) <= calc(n, a, c)) for(auto i : b) cout << i << ' ';
        else for(auto i : c) cout << i << ' ';
        
        cout << endl;
    }
    
    return 0;
}