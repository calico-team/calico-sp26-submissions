#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int k;
        ll n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<ll> ax(k), ay(k);
        for (int i = 0; i < k; i++)
            cin >> ax[i] >> ay[i];

        ll x = ax[0], y = ay[0];
        int ans = -1;
        bool first_seg = true;
        for (int iter = 0; iter < 4000000 && ans == -1; iter++)
        {

            ll max_t = LLONG_MAX;
            if (q > 0)
                max_t = min(max_t, (n - 1 - x) / q);
            if (p > 0)
                max_t = min(max_t, (m - 1 - y) / p);

            ll best_steps = LLONG_MAX;
            for (int j = 0; j < k; j++)
            {
                ll dx = ax[j] - x;
                ll dy = ay[j] - y;
                // 小行星在射线前方
                if (dx < 0 || dy < 0)
                    continue;
                if (p * dx != q * dy)
                    continue;
                // 求步数 t
                ll steps;
                if (q > 0)
                {
                    if (dx % q != 0)
                        continue;
                    steps = dx / q;
                }
                else if (p > 0)
                {
                    if (dy % p != 0)
                        continue;
                    steps = dy / p;
                }
                else
                {
                    continue;
                }

                // 跳过
                if (steps == 0 && first_seg)
                    continue;
                // 不越过墙
                if (steps > max_t)
                    continue;
                if (steps < best_steps)
                {
                    best_steps = steps;
                    ans = j;
                }
            }
            if (ans != -1)
                break;
            ll jump = max_t + 1;
            x = (x + jump * q) % n;
            y = (y + jump * p) % m;
            first_seg = false; // 重检
        }

        cout << ans << endl;
    }
    return 0;
}