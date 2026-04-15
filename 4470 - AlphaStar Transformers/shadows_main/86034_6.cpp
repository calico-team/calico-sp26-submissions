#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAXN=1e3+5;

ll n, s1[MAXN], s2[MAXN], mx, mn;

void solve()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        s1[i]=0;
        for (int j=0; j<n; j++)
        {
            char c;
            cin >> c;
            s1[i]+=(c=='#' ? 1:0);
        }
    }
    for (int i=0; i<n; i++)
    {
        s2[i]=0;
        for (int j=0; j<n; j++)
        {
            char c;
            cin >> c;
            s2[i]+=(c=='#' ? 1:0);
        }
    }
    mx=0;
    mn=0;
    for (int i=0; i<n; i++)
    {
        mx+=s1[i]*s2[i];
        mn+=max(s1[i], s2[i]);
    }
    cout << mx << " " << mn << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}