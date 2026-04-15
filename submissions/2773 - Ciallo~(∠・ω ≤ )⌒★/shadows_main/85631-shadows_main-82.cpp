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

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> L(n + 1, ""), R(n + 1, "");
        rep(i, 1, n) {
            cin >> L[i];
            L[i] = " " + L[i];
        }
        rep(i, 1, n) {
            cin >> R[i];
            R[i] = " " + R[i];
        }

        int ans_mx = 0, ans_mn = 0;
        rep(h, 1, n) {
            int cnt1 = 0, cnt2 = 0;
            rep(j, 1, n)
                cnt1 += (L[h][j] == '#');
            rep(j, 1, n)
                cnt2 += (R[h][j] == '#');
            ans_mx += cnt1 * cnt2;
            ans_mn += max(cnt1, cnt2);
        }

        cout << ans_mx << ' ' << ans_mn << '\n';
    }

    return 0;
}