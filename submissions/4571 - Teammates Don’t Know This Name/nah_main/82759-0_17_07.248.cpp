#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
const int INF = 3e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(all(v));
    int curr = p;
    for (int i = 0; i < n; i++)
    {
        curr -= v[i];
        if (curr < 0)
        {
            cout << "nah I'd lose\n";
            return;
        }
        if ((i + 1) % k == 0)
        {
            curr += r;
        }
    }
    if (curr < 0)
    {
        cout << "nah I'd lose\n";
        return;
    }
    cout << "nah I'd win\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}