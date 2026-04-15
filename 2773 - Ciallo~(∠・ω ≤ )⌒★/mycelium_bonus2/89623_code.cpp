// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <vector>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
#define int ll
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i, l, r) for (int (i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (int (i) = (r); (i) >= (l); --(i))

constexpr int inf_int = 0x3fffffff;
constexpr ll inf_ll = 0x3fffffffffffffffLL;

constexpr int mod = 1000000007;
int fstpow(int base, int exp) {
    int rtn = 1;
    while (exp) {
        if (exp & 1)
            rtn = (ll)rtn * base % mod;
        base = (ll)base * base % mod, exp >>= 1;
    }
    return rtn;
}
int rev(int n) {
    return fstpow(n, mod - 2);
}
int supermod(int x) {
    return (x >= mod ? x % mod : x < 0 ? x % mod + mod : x);
}

signed main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif

    auto mabs = [](int x) {
        return x < 0 ? -x : x;
    };

    auto dist = [&mabs](int u, int v, int x, int y) {
        return mabs(u - x) + mabs(v - y);
    };

    auto div = [](ll a, ll b) {
        return a >= 0 ? a / b : (a - b + 1) / b;
    };

    constexpr int iters = 8000;

    int T; cin >> T;
    while (T--) {
        int Xg, Yg, Xm, Ym;
        cin >> Xg >> Yg >> Xm >> Ym;
        Xm -= Xg, Ym -= Yg;
        Xg = Yg = 0;
        Xm = abs(Xm), Ym = abs(Ym);

        const int x0 = Xm, y0 = Ym;

        ll ans = 0LL;

        int x1 = (7 * (x0 + y0)) / 9 - y0 + 1;
        int y1 = (7 * (x0 + y0)) / 9 - x0 + 1;

        const ll base_tri = (1 + x0 - x1 + 1) * ll(y0 - y1 + 1) / 2;
        ans += base_tri;

        --x1, --y1;

        const ll cx1 = mabs(x1) + y0;
        const ll cy1 = x0 + mabs(y1);

        int x2 = x0, y2 = y0;

        for (int y = y0 + 1; y <= y0 + iters; ++y) {
            const int low_x = div(5 * y - 2 * cx1 + 2 * x1 + 7 * x0 - 5 * y0, 9) + 1;
            if (low_x > x0)
                break;
            y2 = y;

            const ll cont = x0 - low_x + 1;
            ans += cont;
        }

        for (int x = x0 + 1; x <= x0 + iters; ++x) {
            const int low_y = div(5 * x - 2 * cy1 + 2 * y1 + 7 * y0 - 5 * x0, 9) + 1;
            if (low_y > y0)
                break;
            x2 = x;

            const ll cont = y0 - low_y + 1;
            ans += cont;
        }

        ++x2, ++y2;
        const int dist_y2 = cx1 + dist(Xm, y2, x1, Ym);
        const int dist_x2 = cy1 + dist(x2, Ym, Xm, y1);

        for (int x = Xm + 1; x <= Xm + iters; ++x) {
            for (int y = Ym + 1; y <= Ym + iters; ++y) {
                const bool cond1 = 2 * (dist_x2 + dist(x2, Ym, x, y)) > 7 * dist(Xm, Ym, x, y);
                const bool cond2 = 2 * (dist_y2 + dist(Xm, y2, x, y)) > 7 * dist(Xm, Ym, x, y);
                if (cond1 && cond2) {
                    ++ans;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}