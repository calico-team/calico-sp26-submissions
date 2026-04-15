#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll floor_sum(ll n, ll m, ll a, ll b) {
    ll res = 0;
    while (true) {
        if (a >= m) { res += (n - 1) * n * (a / m) / 2; a %= m; }
        if (b >= m) { res += n * (b / m); b %= m; }
        ll y_max = a * n + b;
        if (y_max < m) break;
        n = y_max / m;
        b = y_max % m;
        swap(m, a);
    }
    return res;
}

ll count_linear(ll xl, ll xr, ll a, ll b, ll c, ll yl, ll yr) {
    if (xl > xr || yl > yr) return 0;
    if (b == 0) {
        if (a == 0) return (c > 0) ? (xr - xl + 1) * (yr - yl + 1) : 0;
        if (a > 0) {
            ll lim = (c - 1) / a;
            if (lim < xl) return 0;
            xr = min(xr, lim);
            return (xr - xl + 1) * (yr - yl + 1);
        } else {
            ll lim = (c + 1) / a;
            if (lim > xr) return 0;
            xl = max(xl, lim);
            return (xr - xl + 1) * (yr - yl + 1);
        }
    }
    if (b < 0) {
        return count_linear(xl, xr, -a, -b, -c, -yr, -yl);
    }
    // b > 0
    ll L = xl, R = xr;
    if (a > 0) {
        ll lim = (c - 1 - b * yl) / a;
        if (lim < L) return 0;
        R = min(R, lim);
    } else if (a < 0) {
        ll lim = (c - 1 - b * yl + a + 1) / a;
        if (lim > R) return 0;
        L = max(L, lim);
    } else {
        if (c - 1 - b * yl < 0) return 0;
    }
    if (L > R) return 0;
    ll L1 = L, R1 = R;
    if (a > 0) {
        ll lim = (c - 1 - b * yr + a - 1) / a;
        if (lim > R) R1 = R;
        else R1 = min(R, lim - 1);
    } else if (a < 0) {
        ll lim = (c - 1 - b * yr) / a;
        if (lim < L) R1 = R;
        else L1 = max(L, lim + 1);
    } else {
        ll ymax = (c - 1) / b;
        if (ymax <= yr) R1 = R;
        else R1 = L - 1;
    }
    ll ans = 0;
    if (L <= R1) {
        ll cnt = R1 - L + 1;
        ll sum_x = (L + R1) * cnt / 2;
        ll C = c - 1;
        ll sum_rem = 0;
        for (ll r = 0; r < b; ++r) {
            ll first = L + ((r - L % b + b) % b);
            if (first > R1) continue;
            ll last = first + ((R1 - first) / b) * b;
            ll k = (last - first) / b + 1;
            ll rem = ((C - a * first) % b + b) % b;
            sum_rem += k * rem;
        }
        ll sum_y = (cnt * C - a * sum_x - sum_rem) / b;
        ans += sum_y - (yl - 1) * cnt;
    }
    if (R1 < R) {
        ll cnt2 = R - max(L, R1 + 1) + 1;
        ans += cnt2 * (yr - yl + 1);
    }
    return ans;
}

ll solve(ll dx, ll dy) {
    vector<ll> xs = {0, dx, dx + (dx >= 0 ? 1 : -1)};
    vector<ll> ys = {0, dy, dy + (dy >= 0 ? 1 : -1)};
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    ll ans = 0;
    for (size_t i = 0; i + 1 < xs.size(); ++i) {
        for (size_t j = 0; j + 1 < ys.size(); ++j) {
            ll xl = xs[i], xr = xs[i + 1] - 1;
            ll yl = ys[j], yr = ys[j + 1] - 1;
            if (xl > xr || yl > yr) continue;
            int sx = (xl >= 0) ? 1 : -1;
            int sxd = (xl >= dx) ? 1 : -1;
            int sy = (yl >= 0) ? 1 : -1;
            int syd = (yl >= dy) ? 1 : -1;
            ll a = 7 * sxd - 2 * sx;
            ll b = 7 * syd - 2 * sy;
            ll c = 7 * (sxd * dx + syd * dy);
            ans += count_linear(xl, xr, a, b, c, yl, yr);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll XG, YG, XM, YM; cin >> XG >> YG >> XM >> YM;
        ll dx = XM - XG, dy = YM - YG;
        cout << solve(dx, dy) << '\n';
    }
    return 0;
}