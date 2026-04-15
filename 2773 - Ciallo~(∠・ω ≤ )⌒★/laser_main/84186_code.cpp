// #include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
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
// #define mp make_pair
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
int supermod(int x, int mod) {
    return (x >= mod ? x % mod : x < 0 ? x % mod + mod : x);
}
// ll supermod(ll x) {
//     return (x >= mod ? x % mod : x < 0LL ? x % mod + mod : x);
// }

bool flag = false;
ll solve(ll a, ll b, ll d, ll& x, ll& y) {
    if (b == 0) {
        // assert(d % a == 0);
        if (d % a != 0)
            flag = true;
        x = d / a;
        y = 0;
        return a;
    } else {
        const ll rtn = solve(b, a % b, d, y, x);
        x = x;
        y -= (a / b) * x;
        return rtn;
    }
}

signed main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif

    int T; cin >> T;
    while (T--) {
        ll k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;

        ll x1, y1;
        cin >> x1 >> y1;

        int ans_val = inf_int, ans_id = 0;
        for (int i = 1; i < k; ++i) {
            ll x2, y2;
            cin >> x2 >> y2;

            flag = false;

            ll kx, kn;
            const ll gcd_x = solve(q, n, x2 - x1, kx, kn);

            ll ky, km;
            const ll gcd_y = solve(p, m, y2 - y1, ky, km);

            const ll lcm_x = q / gcd_x * n;
            const ll step_x = lcm_x / q;

            const ll lcm_y = p / gcd_y * m;
            const ll step_y = lcm_y / p;

            ll xf, yf;
            const ll gcd_f = solve(step_x, step_y, ky - kx, xf, yf);
            yf = -yf;
            const ll lcm_f = step_x / gcd_f * step_y;

            const ll step_f = lcm_f;

            if (flag)
                continue;

            const ll final_x = kx + xf * step_x, final_y = ky + yf * step_y;
            assert(final_x == final_y);
            // cerr << "Log " << final_x << ' ' << final_y << '\n';

            const int cont = (final_x % step_f + step_f) % step_f;
            if (cont < ans_val)
                ans_val = cont, ans_id = i;;
        }

        cout << ans_id << '\n';
    }

    return 0;
}