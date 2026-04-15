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

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

pair<int, int> crt(int r1, int m1, int r2, int m2) {
    int x, y;
    int g = extended_gcd(m1, m2, x, y);
    if ((r2 - r1) % g != 0) return {-1, -1};
    
    int lcm = (m1 / g) * m2;
    int diff = r2 - r1;
    int mod = m2 / g;
    int val = ((x % mod) * (diff / g % mod)) % mod;
    if (val < 0) val += mod;
    
    int res = (r1 + val * m1) % lcm;
    if (res < 0) res += lcm;
    return {res, lcm};
}

pair<int, int> congru(int a, int b, int n) {
    int x, y;
    int g = extended_gcd(a, n, x, y);
    if (b % g != 0) return {-1, -1};
    
    int m = n / g;
    int res = ((x % m) * (b / g % m)) % m;
    if (res < 0) res += m;
    return {res, m};
}

signed main() {
    io();

    int t; cin >> t;
    while(t--) {
        int k, n, m, p, q; 
        cin >> k >> n >> m >> p >> q;

        vector<pair<int,int>> a(k);
        for(int i = 0; i < k; i++) {
            cin >> a[i].fi >> a[i].se;
        }

        int min_step = -1;
        int ans = -1;

        for(int i = 0; i < k; i++) {
            int x = (a[i].fi - a[0].fi+ n) % n;
            int y = (a[i].se - a[0].se + m) % m;

            pair<int, int> X = congru(q, x, n);
            pair<int, int> Y = congru(p, y, m);

            if(X.fi != -1 && Y.fi != -1) {
                pair<int, int> res = crt(X.fi, X.se, Y.fi, Y.se);
                
                if(res.fi != -1) {
                    int step = res.fi;
                    if (step == 0) step = res.se; 
                    
                    if(ans == -1 || step < min_step) {
                        min_step = step;
                        ans = i;
                    }
                }
            }
        }

        cout << ans << nl;
    }   

    return 0;
}