#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

struct Node { ll rem, mod; };

Node merge(Node a, Node b) {
    if (a.rem == -1 || b.rem == -1) return {-1, -1};
    ll x, y;
    ll g = exgcd(a.mod, b.mod, x, y);
    if ((b.rem - a.rem) % g) return {-1, -1};
    ll new_mod = a.mod / g * b.mod;
    ll step = b.mod / g;
    ll factor = (__int128)(b.rem - a.rem) / g * x % step;
    ll new_rem = (a.rem + (__int128)a.mod * factor) % new_mod;
    return {(ll)(new_rem + new_mod) % new_mod, new_mod};
}

Node solve_linear(ll a, ll b, ll m) {
    ll x, y;
    ll g = exgcd(a, m, x, y);
    if (b % g) return {-1, -1};
    ll md = m / g;
    return {(ll)((__int128)x * (b / g) % md + md) % md, md};
}

void solve() {
    int k, best_idx = -1;
    ll n, m, p, q, min_step = -1;
    if (scanf("%d %lld %lld %lld %lld", &k, &n, &m, &p, &q) == EOF) return;
    vector<pair<ll, ll>> pts(k);
    for (int i = 0; i < k; i++) scanf("%lld %lld", &pts[i].first, &pts[i].second);
    for (int i = 0; i < k; i++) {
        Node res = merge(solve_linear(q, (pts[i].first - pts[0].first + n) % n, n),
                         solve_linear(p, (pts[i].second - pts[0].second + m) % m, m));
        if (res.rem != -1) {
            ll cur = res.rem ? res.rem : res.mod;
            if (min_step == -1 || cur < min_step) {
                min_step = cur;
                best_idx = i;
            }
        }
    }
    printf("%d\n", best_idx);
}

int main() {
    int t;
    if (scanf("%d", &t) != EOF) {
        while (t--) solve();
    }
    return 0;
}