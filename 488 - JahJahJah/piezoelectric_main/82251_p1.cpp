#include <iostream>
#include <cstdint>
using namespace std;
#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    int per = 2 * (l + w);
    int lap = per * r;
    cout << e / lap << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}