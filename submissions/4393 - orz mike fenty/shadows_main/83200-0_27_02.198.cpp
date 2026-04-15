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

const int MM = 1e3+5;

char a[MM][MM], b[MM][MM];
int cnt[MM];

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        cnt[i] = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
            cnt[i] += (b[i][j] == '#');
        }
    }
    ll mn = 0;
    for (int i = 0; i < n; i++)
    {
        int c1=0, c2=0;
        for (int j = 0; j < n; j++)
        {
            c1 += a[i][j] == '#';
            c2 += b[i][j] == '#';
        }
        mn += max(c1, c2);
    }
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mx += (a[i][j] == '#')*cnt[i];
    }
    cout << mx << " " << mn << "\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T-- > 0)
        solve();

    return 0;
}