#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int inf = 0x3F3F3F3F;
const ll infll = 0x3F3F3F3F3F3F3F3FLL;

void solve()
{
    int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
    vector<pi> pt(k);
    for (int i = 0; i < k; i++) cin >> pt[i].first >> pt[i].second;
    auto [x, y] = pt[0];
    bool first = 1;
    while (1)
    {
        for (int i = first; i < k; i++)
        {
            if (make_pair(x, y) == pt[i])
            {
                cout << i << "\n";
                return;
            }
        }
        x = (x+q)%n; y = (y+p)%m; first = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T-- > 0)
        solve();

    return 0;
}