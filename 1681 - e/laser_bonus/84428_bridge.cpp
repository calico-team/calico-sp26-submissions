#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

pair<ll, ll>solve_linear(ll q, ll d, ll n) {
    d = (d % n + n) % n;
    ll x, y;
    ll g = exgcd(q, n, x, y);
    if (d % g != 0) return {-1, -1};
    ll mod = n / g;
    ll t = (__int128)x * (d / g) % mod;
    if (t < 0) t += mod;
    return {t, mod};
}

ll merge(ll a1, ll m1, ll a2, ll m2) {
    if (a1 == -1 || a2 == -1) return -1;
    ll x, y;
    ll g = exgcd(m1, m2, x, y);
    if ((a2 - a1) % g != 0) return -1;
    ll mod = m2 / g;
    ll lcm = m1 / g * m2; 
    ll t = (__int128)((a2 - a1) / g) * x % mod;
    if (t < 0) t += mod;
    ll res = (a1 + (__int128)m1 * t) % lcm;
    return res;
}

void solve()
{
    int k , n, m , p, q; cin>>k>>n>>m>>p>>q;
    vector<pair<ll,ll>>v(k);
    for(int i =0;i<k;i++)cin>>v[i].first >> v[i].second;
    ll best = 4e18;
    int ans = 0;
    for(int i=1;i<k;i++){
        ll dx = v[i].first - v[0].first;
        ll dy = v[i].second - v[0].second;
        auto r1 = solve_linear(q, dx, n);
        auto r2 = solve_linear(p, dy, m);
        int xx = merge(r1.first, r1.second, r2.first, r2.second);
        if (xx != -1 && xx < best) {
            best = xx;
            ans = i;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}