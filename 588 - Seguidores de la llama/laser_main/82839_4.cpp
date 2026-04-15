#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define dforn(i, n) dforsn(i, 0, n)
 
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vb = vector<bool>;
using pll = pair<ll, ll>;
using bint = __int128;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
#define pb push_back
#define eb emplace_back
 
#define fst first
#define snd second

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool solve(ll a, ll b, ll m, ll &t, ll &mod) {
    ll x, y;
    ll g = extgcd(a, m, x, y);
    if (b % g) return false;
    ll m2 = m / g;
    t = (bint) x * (b / g) % m2;
    if (t < 0) t += m2;
    mod = m2;
    return true;
}

bool crt(ll a1, ll m1, ll a2, ll m2, ll &res, ll &lcm) {
    ll x, y;
    ll g = extgcd(m1, m2, x, y);
    if ((a2 - a1) % g != 0) return false;
    ll l = m1 / g * m2;
    ll t = (bint) (a2 - a1) / g * x % (m2 / g);
    res = (a1 + m1 * t) % l;
    if (res < 0) res += l;
    lcm = l;
    return true;
}
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    forn(_, tc) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vll x(k), y(k);
        forn(i, k) cin >> x[i] >> y[i];
        ll x0 = x[0], y0 = y[0];
        ll best_t = -1, best_idx = 0;
        forn(i, k) {
            ll dx = ((x[i] - x0) % n + n) % n;
            ll dy = ((y[i] - y0) % m + m) % m;
            
            ll t1, mod1;
            if (!solve(q, dx, n, t1, mod1)) continue;
            
            ll t2, mod2;
            if (!solve(p, dy, m, t2, mod2)) continue;
            
            ll t, mod;
            if (!crt(t1, mod1, t2, mod2, t, mod)) continue;
            
            if (t == 0) t = mod;
            
            if (best_t == -1 || t < best_t) {
                best_t = t;
                best_idx = i;
            }
        }
        
        assert(best_t != -1);
        cout << best_idx << "\n";
    }
    
    return 0;
}
