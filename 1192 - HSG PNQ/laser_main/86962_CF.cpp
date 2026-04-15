// soab

#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define nl '\n'
#define fi first
#define se second

void io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}   

signed main() {
    io();

    int t; cin >> t;
    while(t--) {
        int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> a(k);
        for(int i = 0; i < k; i++) {
            cin >> a[i].fi >> a[i].se;
        }

        int x = a[0].fi, y = a[0].se;
        int ans = -1;
        for(int i = 0; i < 1000000; i++) {
            x = (x + q) % n;
            y = (y + p) % m;
            // cout << x << ' ' << y << nl;
            for(int j = 0; j < k; j++) {
                // cout << a[j].fi << ' ' << a[j].se << nl;
                if(x == a[j].fi && y == a[j].se) {
                    ans = j;
                    break;
                }
            }
            if(x == a[0].fi && y == a[0].se) break;
            if(ans != -1) break;
            // cout << nl;
        }

        cout << ans << nl;

    }   

    return 0;
}   