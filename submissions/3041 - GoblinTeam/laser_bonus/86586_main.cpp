/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll inv(ll a, ll m) {
    ll x, y;
    ll d = exgcd(a, m, x, y);
    if (d != 1) return -1;
    return (x % m + m) % m;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        
        vector<int> x(k), y(k);
        for (int i = 0; i < k; i++) {
            cin >> x[i] >> y[i];
        }
        
        int x0 = x[0], y0 = y[0];
        map<pair<int, int>, int> mp;
        for (int i = 1; i < k; i++) {
            int dx = (x[i] - x0 + n) % n;
            int dy = (y[i] - y0 + m) % m;
            if (!mp.count({dx, dy})) {
                mp[{dx, dy}] = i;
            }
        }
        
        ll best = 1e18;
        int ans = 0;
        ll g1 = __gcd(q, n);
        ll g2 = __gcd(p, m);
        
        ll n1 = n / g1;
        ll m1 = m / g2;
        
        ll inv_q = inv(q / g1, n1);
        ll inv_p = inv(p / g2, m1);
        for (auto &[pos, idx] : mp) {
            int dx = pos.first, dy = pos.second;
            
            if (dx % g1 != 0 || dy % g2 != 0) continue;
            
            ll t1 = (dx / g1) * inv_q % n1;
            ll t2 = (dy / g2) * inv_p % m1;
            
            // 解 t ≡ t1 (mod n1), t ≡ t2 (mod m1)
            ll g = __gcd(n1, m1);
            if ((t2 - t1) % g != 0) continue;
            
            ll lcm = n1 / g * m1;
            ll k0 = ((t2 - t1) / g) % (m1 / g);
            ll t = (t1 + n1 * k0) % lcm;
            if (t == 0) t = lcm;
            
            if (t < best) {
                best = t;
                ans = idx;
            }
        }
        
        if (best == 1e18) ans = 0;
        cout << ans << '\n';
    }
    
    return 0;
}