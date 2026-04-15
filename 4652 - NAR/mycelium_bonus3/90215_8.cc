#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t i128;

ll fdiv(ll a, ll b) {
    ll q = a / b, r = a % b;
    if(r < 0) q--;
    return q;
}

ll cdiv(ll a, ll b) {
    ll q = a / b, r = a % b;
    if(r > 0) q++;
    return q;
}

i128 floor_sum_nonneg(ll n, ll m, ll a, ll b) {
    i128 res = 0;
    while(true) {
        if(a >= m) {
            res += (i128)(n - 1) * n * (a / m) / 2;
            a %= m;
        }
        if(b >= m) {
            res += (i128)n * (b / m);
            b %= m;
        }
        i128 y = (i128)a * n + b;
        if(y < m) break;
        n = (ll)(y / m);
        b = (ll)(y % m);
        swap(a, m);
    }
    return res;
}

i128 floor_sum_any(ll n, ll m, ll a, ll b) {
    i128 res = 0;
    if(a < 0) {
        ll q = fdiv(a, m);
        res += (i128)q * n * (n - 1) / 2;
        a -= q * m;
    }
    if(b < 0) {
        ll q = fdiv(b, m);
        res += (i128)q * n;
        b -= q * m;
    }
    res += floor_sum_nonneg(n, m, a, b);
    return res;
}

i128 sum_floor(ll l, ll r, ll a, ll b, ll m) {
    if(l > r) return 0;
    ll n = r - l + 1;
    return floor_sum_any(n, m, a, a * l + b);
}

ll calc(ll a, ll b) {
    ll d = a + b;
    ll e = a - b;

    ll h = max(b, cdiv(2 * e, 5));
    ll m = 2 * e + 4 * h;
    ll u = cdiv(m, 5);
    ll j = m + 4 * u;

    ll v = cdiv(2 * d, 5);
    ll k = 2 * d + 4 * v;

    ll p = fdiv(2 * d - 1, 9);

    auto nlen = [&](ll y) {
        ll r = fdiv(2 * d + 5 * y - 1, 9);
        ll l = max(fdiv(-j - 5 * y, 9), fdiv(-k - 9 * y, 5)) + 1;
        return r - l + 1;
    };

    auto plen = [&](ll y) {
        ll l = fdiv(9 * y - m, 5) + 1;
        ll r = (y <= b ? p - y : fdiv(2 * e - 5 * y - 1, 9));
        return r - l + 1;
    };

    auto dom = [&](ll y) {
        return fdiv(-j - 5 * y, 9) >= fdiv(-k - 9 * y, 5);
    };

    i128 ans = 0;

    ll l = -(d + 5), r = 0;
    while(l + 1 < r) {
        ll md = l + (r - l) / 2;
        if(nlen(md) > 0) r = md;
        else l = md;
    }
    ll yl = r;

    l = yl - 1, r = 0;
    while(l + 1 < r) {
        ll md = l + (r - l) / 2;
        if(dom(md)) r = md;
        else l = md;
    }
    ll ys = r;

    if(yl <= ys - 1) {
        ans += sum_floor(yl, ys - 1, 5, 2 * d - 1, 9);
        ans -= sum_floor(yl, ys - 1, -9, -k, 5);
    }
    if(ys <= 0) {
        ans += sum_floor(ys, 0, 5, 2 * d - 1, 9);
        ans -= sum_floor(ys, 0, -5, -j, 9);
    }

    if(plen(1) > 0) {
        l = 1, r = d + 5;
        while(l < r) {
            ll md = l + (r - l + 1) / 2;
            if(plen(md) > 0) l = md;
            else r = md - 1;
        }
        ll yr = l;

        ll r1 = min(b, yr);
        if(1 <= r1) {
            ans += (i128)r1 * p - (i128)(1 + r1) * r1 / 2;
            ans -= sum_floor(1, r1, 9, -m, 5);
        }

        ll l2 = max(1LL, b + 1);
        if(l2 <= yr) {
            ans += sum_floor(l2, yr, -5, 2 * e - 1, 9);
            ans -= sum_floor(l2, yr, 9, -m, 5);
        }
    }

    return (ll)ans;
}

void solve() {
    ll xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    ll dx = abs(xg - xm);
    ll dy = abs(yg - ym);
    ll a = max(dx, dy);
    ll b = min(dx, dy);

    cout << calc(a, b) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}