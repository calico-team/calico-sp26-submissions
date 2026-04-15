#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

void solve()
{
    ll n, i, j, mi=0, ma=0;
    cin >> n;
    vector<string> s1(n), s2(n);
    vector<ll> c(2, 0), cant(n,0);
    for (i = 0; i < n; i++)
        cin >> s1[i];
    for (i = 0; i < n; i++)
    {
        cin >> s2[i];
        for(j=0; j<n; j++)
            if(s2[i][j]=='#')
                cant[i]++;
    }
    
    for (i = 0; i < n; i++)
    {
        c[0] = c[1] = 0;
        for (j = 0; j < n; j++)
        {
            if(s1[i][j]=='#')
            {
                c[0]++;
                ma+=cant[i];
            }
            if(s2[i][j]=='#')
                c[1]++;
        }
        mi+=max(c[0],c[1]);
    }
    cout << ma << ' ' << mi <<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
