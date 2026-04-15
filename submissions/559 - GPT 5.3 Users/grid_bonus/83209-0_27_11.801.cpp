#include <bits/stdc++.h>

using namespace std;
#define double long double
#define int long long
#define V vector

const int inf = numeric_limits<int>::max();
const double infd = numeric_limits<double>::infinity();
using pii = pair<int, int>;
using pil = pair<int, double>;
using pli = pair<double, int>;
using pll = pair<double, double>;

#define F first
#define S second
#define PB push_back
#define read(arr) for (auto &x : arr) cin >> x
#define show(arr) for (auto x : arr) cout << x << " "; cout << endl
#define FOR(v,l,h) for (int v = l; v < h; v ++)

signed main()
{
    int tst;
    cin >> tst;
    while (tst --)
    {
        int n;
        cin >> n;

        V<int> a(n);
        read(a);

        if (a.size() == 1)
        {
            cout << a[0] << endl;
            continue;
        }
        if (a.size() == 2)
        {
            cout << a[0] << " " << a[1] << endl;
            continue;
        }

        V<array<int, 3>> dp(n, {inf, inf, inf}), prev(n);
        dp[1][0] = abs(a[0] - a[1]), prev[1][0] = 1;
        dp[1][1] = abs(a[0] - a[1]), prev[1][1] = 1;
        dp[1][2] = abs(a[1] - a[2]) + abs(a[0] - a[2]), prev[1][2] = 1;
        for (int i = 2; i < n; i ++)
        {
            for (int j = -1; j <= 1; j ++)
                for (int k = -1; k <= 1; k ++)
                {
                    if (i == n - 1 && k == 1) continue;
                    int pv = a[i - 1 + j], cv = a[i + k];
                    int s = dp[i - 1][j + 1] + abs(pv - cv) + abs(a[i] - cv);
                    if (s < dp[i][k + 1])
                    {
                        dp[i][k+1] = s;
                        prev[i][k+1] = j + 1;
                    }
                }
        }
        int ci = dp[n-1][0] < dp[n-1][1] ? 0 : 1;
        V<int> b(n);
        for (int i = n - 1; i >= 0; i --)
        {
            b[i] = a[i+ci-1];
            ci = prev[i][ci];
        }
        show(b);
    }
}
