#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ast_x[100005], ast_y[100005];

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        
        for (int i = 0; i < k; i++) {
            cin >> ast_x[i] >> ast_y[i];
        }
        
        ll x0 = ast_x[0], y0 = ast_y[0];
        ll min_t = -1, ans = -1;
        
        for (int i = 0; i < k; i++) {
            ll dx = (ast_x[i] - x0 + n) % n;
            ll dy = (ast_y[i] - y0 + m) % m;
            
            ll x, dummy_y;

            ll g_x = ext_gcd(q, n, x, dummy_y);
            if (dx % g_x != 0) continue;
            ll mx = n / g_x;
            ll rx = ((dx / g_x) * ((x % mx + mx) % mx)) % mx;
            
            ll g_y = ext_gcd(p, m, x, dummy_y);
            if (dy % g_y != 0) continue;
            ll my = m / g_y;
            ll ry = ((dy / g_y) * ((x % my + my) % my)) % my;
            
            ll g_xy = ext_gcd(mx, my, x, dummy_y);
            ll diff = ry - rx;
            if (diff % g_xy != 0) continue;
            
            ll my_g = my / g_xy;
            diff = (diff / g_xy) % my_g;
            diff = (diff + my_g) % my_g;
            x = (x % my_g + my_g) % my_g;
            
            ll kt = (diff * x) % my_g;
            ll cur = rx + kt * mx;
            ll period = mx * my_g;
            
            if (cur == 0) cur += period;
            
            if (min_t == -1 || cur < min_t) {
                min_t = cur;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}