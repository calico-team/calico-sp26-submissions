#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAXN=1e5+5;

ll n, a[MAXN];

void solve()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i=0; i<n; i++)
    {
        cout << a[n/2] << " ";
    }
    cout << "\n";
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