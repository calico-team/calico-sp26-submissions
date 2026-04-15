// soab

#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define nl '\n'

void io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}   

signed main() {
    io();

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        
        int m;
        if(n % 2 == 0) {
            m = (a[n / 2] + a[n / 2 + 1]) / 2;
        } else {
            m = a[n / 2];
        }

        for(int i = 0; i < n; i++) {
            cout << m << ' ';
        }

        cout << nl;

    }   

    return 0;
}   