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

char g[MM][MM];
int psa[3*MM][3*MM];
int n, m, k;

int qry(int i1, int j1, int i2, int j2)
{
    return psa[i2][j2] - psa[i2][j1-1] - psa[i1-1][j2] + psa[i1-1][j1-1];
}

bool check(int mid)
{
    for (int i = 1; i+mid <= n+m+5; i++)
    {
        for (int j = 1; j+mid <= n+m+m+5; j++)
        {
            if (qry(i, j, i+mid, j+mid) >= k)
                return 1;
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n+m+5; i++)
    {
        for (int j = 1; j <= n+m+m+5; j++)
            psa[i][j] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            int r=i-j, c=i+j;
            psa[r+m+1][c+m+1] += g[i][j] == '-';
        }
    }
    for (int i = 1; i <= n+m+5; i++)
    {
        for (int j = 1; j <= n+m+m+5; j++)
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    }
    int lo=0, hi=n+m, mn=hi;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (check(mid))
        {
            mn = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    for (int i = 1; i+mn <= n+m+5; i++)
    {
        for (int j = 1; j+mn <= n+m+m+5; j++)
        {
            if (qry(i, j, i+mn, j+mn) >= k)
            {
                for (int r = i; r <= i+mn; r++)
                {
                    for (int c = j; c <= j+mn; c++)
                    {
                        if ((r+c-m-1-m-1)%2 != 0) continue;
                        int i2 = (r+c-m-1-m-1)/2, j2 = c-m-1-i2;
                        if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m &&
                            g[i2][j2] == '-' && k > 0)
                        {
                            cout << i2 << " " << j2 << "\n";
                            k--;
                        }
                    }
                }
                return;
            }
        }
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