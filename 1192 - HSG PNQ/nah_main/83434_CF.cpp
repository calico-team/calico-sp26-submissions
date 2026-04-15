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
        int n, p, r, k; cin >> n >> p >> r >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int cnt = 0;
        bool ans = 1;
        for(int i = 0; i < n; i++) {
            if(p < a[i]) {
                ans = 0;
                break;
            }
            cnt++;
            p -= a[i];
            if(cnt == k) {
                p += r;
                cnt = 0;
            }
        }

        cout << (ans? "nah i’d win" : "nah i’d lose") << nl;
    }

    return 0;
}   