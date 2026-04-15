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
    string a, b;
    cin >> a >> b;
    int j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (j < b.size() && a[i] == b[j])
        {
            j++;
            cout << a[i];
        }
        else
        {
            cout << '#';
        }
    }
    cout << '\n';
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