#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int b_index = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (b_index < b.size() && a[i] == b[b_index])
            b_index++;
        else
            a[i] = '#';
    }
    cout << a << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
