#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int start[5] = {0, 2, 4, 1, 3};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << (start[i % 5] + j) % 5 << ' ';
        }
        cout << endl;
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
