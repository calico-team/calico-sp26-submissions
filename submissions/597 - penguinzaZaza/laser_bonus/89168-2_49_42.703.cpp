#include <bits/stdc++.h>
using namespace std;

long long t, n, m, p, q, k;
long long x[1000005], y[1000005], stx, sty;
int xord[1000005], yord[1000005];
int anyord[1000005];

void solve()
{
    cin >> k >> n >> m >> q >> p;
    for (int i = 0; i < k; i++)
        cin >> x[i] >> y[i];
    stx = x[0];
    sty = y[0];
    // while(stx < n && sty < m) {stx += p; sty += q;}
    // stx %= n; sty %= m;
    for (int i = 0; i < k; i++)
    {
        x[i] = (x[i] - stx + n) % n;
        y[i] = (y[i] - sty + m) % m;
        // cout << x[i] << ' ' << y[i] << " at " << i << " naja\n";
    }
    long long rnd = 0, cyy = 0;
    memset(xord, -1, sizeof xord);
    for (int i = 0; i < n; i++)
        if (xord[i * p % n] == -1)
        {
            rnd++;
            xord[i * p % n] = i;
            yord[i * p % n] = cyy;
            cyy += q;
            cyy %= m;
        }
    // cout << cyy << '\n';
    memset(anyord, -1, sizeof anyord);
    for (int i = 0; i < m; i++)
        if (anyord[cyy * i % m] == -1)
            anyord[cyy * i % m] = i;
    long long incy = rnd * q % m;
    pair<pair<int, int>, int> mn(pair<int, int>(100000000, 100000000), 0);
    for (int i = 1; i < k; i++)
    {
        if (xord[x[i]] == -1)
            continue;
        y[i] = (y[i] - yord[x[i]] + m) % m;
        if (anyord[y[i]] == -1)
            continue;
        mn = min(mn, make_pair(make_pair(anyord[y[i]], xord[x[i]]), i));
    }
    cout << mn.second << '\n';
    // cout << "---\n";
    // cout << q << ' ' << p << " increment\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--)
        solve();
}