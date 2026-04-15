#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using i64 = long long;
using i128 = __int128;
i64 xgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 x0 = 1, y0 = 0, x1 = 0, y1 = 1;
    while (b) {
        i64 q = a / b;
        i64 t = b; b = a % b; a = t;
        t = x1; x1 = x0 - q * x1; x0 = t;
        t = y1; y1 = y0 - q * y1; y0 = t;
    }
    x = x0; y = y0;
    return a;
}

i64 get_inv(i64 v, i64 m) {
    if (m == 1) return 0;
    i64 x, y;
    xgcd(v, m, x, y);
    return (x % m + m) % m;
}

i64 check(i64 r1, i64 m1, i64 r2, i64 m2) {
    i64 u, v;
    i64 d = xgcd(m1, m2, u, v);
    if ((r2 - r1) % d) return -1;
    i64 stp = m2 / d;
    i64 mul = (i64)((i128)(r2 - r1) / d * ((u % stp + stp) % stp) % stp);
    i64 lc = m1 / d * m2;
    i64 res = (i64)(((i128)m1 * mul + r1) % lc);
    return res < 0 ? res + lc : res;
}

void solve() {
    int k;
    i64 n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    
    vector<pair<i64, i64>> pt(k);
    for (int i = 0; i < k; ++i) cin >> pt[i].first >> pt[i].second;

    i64 sx = pt[0].first, sy = pt[0].second;
    i64 dn = std::gcd(q, n), dm = std::gcd(p, m);
    i64 rn = n / dn, rm = m / dm;
    i64 iq = get_inv(q / dn, rn), ip = get_inv(p / dm, rm);
    i64 cyc = rn / std::gcd(rn, rm) * rm;
    
    i64 mn_t = -1;
    int id = -1;

    for (int i = 0; i < k; ++i) {
        i64 dx = (pt[i].first - sx + n) % n;
        i64 dy = (pt[i].second - sy + m) % m;
        i64 cur = -1;
        if (!dx && !dy) {
            cur = cyc;
        } else if (dx % dn == 0 && dy % dm == 0) {
            i64 ra = 0, rb = 0;
            if (rn > 1) ra = (i64)((i128)(dx / dn) * iq % rn);
            if (rm > 1) rb = (i64)((i128)(dy / dm) * ip % rm);
            cur = check(ra, rn, rb, rm);
            if (cur == 0) cur = cyc;
        }
        if (cur != -1) {
            if (mn_t == -1 || cur < mn_t || (cur == mn_t && i < id)) {
                mn_t = cur;
                id = i;
            }
        }
    }
    cout << id << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}