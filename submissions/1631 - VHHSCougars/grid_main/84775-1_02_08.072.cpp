#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> b(n);
    b = a;
    if (n == 1)
    {
        cout << a[0];
        return;
    }
    if (n == 2)
    {
        cout << a[0] << " " << a[1];
        return;
    }
    for (long long i = 1; i < n - 1; i++)
    {
        if (b[i - 1] > b[i] && b[i] < b[i + 1])
        {
            b[i] = min(b[i - 1], b[i + 1]);
        }
        else if (b[i - 1] < b[i] && b[i] > b[i + 1])
        {
            b[i] = max(b[i - 1], b[i + 1]);
        }
    }
    for (long long i = 0; i < n; i++)
    {
        cout << b[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}