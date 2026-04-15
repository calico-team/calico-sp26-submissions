#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;

void solve()
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << (i+2*j)%5 << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}