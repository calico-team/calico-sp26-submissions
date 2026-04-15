#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll floor_div(ll a, ll b) {
    assert(b > 0);
    ll q = a / b, r = a % b;
    if (r < 0) q--;
    return q;
}

ll floor_sum(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    while (1) {
        if (a >= m) {
            ans += (n - 1) * n * (a / m) / 2;
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        ll y = a * n + b;
        if (y < m) break;

        n = y / m;
        b = y % m;
        swap(m, a);
    }
    return ans;
}

ll floor_sum_signed(ll n, ll m, ll a, ll b) {
    ll ans = 0;

    if (a < 0) {
        ll a2 = (a % m + m) % m;
        ans -= n * (n - 1) / 2 * ((a2 - a) / m);
        a = a2;
    }
    if (b < 0) {
        ll b2 = (b % m + m) % m;
        ans -= n * ((b2 - b) / m);
        b = b2;
    }

    return ans + floor_sum(n, m, a, b);
}

ll cnt_rect(ll lx, ll rx, ll ly, ll ry, ll A, ll B, ll C) {
    if (lx > rx || ly > ry) return 0;

    if (A < 0) {
        ll nl = -rx, nr = -lx;
        lx = nl;
        rx = nr;
        A = -A;
    }
    if (B < 0) {
        ll nl = -ry, nr = -ly;
        ly = nl;
        ry = nr;
        B = -B;
    }

    ll h = ry - ly + 1;
    ll full_r = min(rx, floor_div(C - 1 - B * ry, A));
    ll some_r = min(rx, floor_div(C - 1 - B * ly, A));

    if (some_r < lx) return 0;

    ll ans = 0;
    if (full_r >= lx) ans += (full_r - lx + 1) * h;

    ll l = max(lx, full_r + 1), r = some_r;
    if (l > r) return ans;

    ll n = r - l + 1;
    ll beta = C - 1 - A * r;
    ans += floor_sum_signed(n, B, A, beta) - n * ly + n;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        ll xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;

        ll a = xg - xm;
        ll b = yg - ym;
        ll d = llabs(a) + llabs(b);
        ll R = (2 * d - 1) / 5;

        vector<ll> xs = {-R, R + 1};
        vector<ll> ys = {-R, R + 1};
        if (-R < 0 && 0 <= R) xs.push_back(0);
        if (-R < a && a <= R) xs.push_back(a);
        if (-R < 0 && 0 <= R) ys.push_back(0);
        if (-R < b && b <= R) ys.push_back(b);

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        ll ans = 0;

        for (int i = 0; i + 1 < (int)xs.size(); i++) {
            ll lx = xs[i], rx = xs[i + 1] - 1;
            ll xx = lx;
            ll sx1 = (xx >= 0 ? 1 : -1);
            ll sx2 = (xx >= a ? 1 : -1);
            ll A = 7 * sx1 - 2 * sx2;
            ll Cx = 2 * (sx2 == 1 ? -a : a);

            for (int j = 0; j + 1 < (int)ys.size(); j++) {
                ll ly = ys[j], ry = ys[j + 1] - 1;
                ll yy = ly;
                ll sy1 = (yy >= 0 ? 1 : -1);
                ll sy2 = (yy >= b ? 1 : -1);
                ll B = 7 * sy1 - 2 * sy2;
                ll Cy = 2 * (sy2 == 1 ? -b : b);

                ans += cnt_rect(lx, rx, ly, ry, A, B, Cx + Cy);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
