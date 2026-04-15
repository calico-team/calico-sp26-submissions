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
// #define int ll
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
ll supermod(ll x) {
    return (x >= mod ? x % mod : x < 0LL ? x % mod + mod : x);
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

    constexpr int min_iter = 500, max_iter = 500;

    int T; cin >> T;
    while (T--) {
        int Xg, Yg, Xm, Ym;
        cin >> Xg >> Yg >> Xm >> Ym;
        Xm -= Xg, Ym -= Yg;
        Xg = Yg = 0;

        Xm = abs(Xm), Ym = abs(Ym);

        int ans = 0;
        int min_x = Xm, min_y = Ym;
        int max_x = Xm, max_y = Ym;
        for (int x = Xm - min_iter; x <= Xm + max_iter; ++x) {
            for (int y = Ym - min_iter; y <= Ym + max_iter; ++y) {
                if (2 * (abs(x - Xg) + abs(y - Yg)) > 7 * (abs(x - Xm) + abs(y - Ym))) {
                    ++ans;
                    min_x = min(min_x, x);
                    min_y = min(min_y, y);
                    max_x = max(max_x, x);
                    max_y = max(max_y, y);
                }
            }
        }

        --min_x, --min_y;
        const int dist_min_y = abs(Xm) + abs(min_y), dist_min_x = abs(min_x) + abs(Ym);

        for (int x = Xm - min_iter; x <= Xm + max_iter; ++x) {
            for (int y = Ym - min_iter; y <= Ym + max_iter; ++y) {
                if (2 * (abs(x - Xg) + abs(y - Yg)) > 7 * (abs(x - Xm) + abs(y - Ym)))
                    continue;
                else if (x >= min_x && x <= Xm && y >= Ym) {
                    const bool cond2 = 2 * (dist_min_x + dist(min_x, Ym, x, y)) > 7 * dist(Xm, Ym, x, y);
                    if (cond2) {
                        ++ans;
                        max_x = max(max_x, x);
                        max_y = max(max_y, y);
                    }
                } else if (y >= min_y && y <= Ym && x >= Xm) {
                    const bool cond1 = 2 * (dist_min_y + dist(Xm, min_y, x, y)) > 7 * dist(Xm, Ym, x, y);
                    if (cond1) {
                        ++ans;
                        max_x = max(max_x, x);
                        max_y = max(max_y, y);
                    }
                }
            }
        }

        ++max_x, ++max_y;
        const int dist_max_y = dist_min_x + dist(Xm, max_y, min_x, Ym);
        const int dist_max_x = dist_min_y + dist(max_x, Ym, Xm, min_y);

        for (int x = Xm - min_iter; x <= Xm + max_iter; ++x) {
            for (int y = Ym - min_iter; y <= Ym + max_iter; ++y) {
                if (2 * (abs(x - Xg) + abs(y - Yg)) > 7 * (abs(x - Xm) + abs(y - Ym)))
                    continue;
                else if (x > Xm && y > Ym) {
                    const bool cond1 = 2 * (dist_max_x + dist(max_x, Ym, x, y)) > 7 * dist(Xm, Ym, x, y);
                    const bool cond2 = 2 * (dist_max_y + dist(Xm, max_y, x, y)) > 7 * dist(Xm, Ym, x, y);
                    if (cond1 && cond2) {
                        ++ans;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}