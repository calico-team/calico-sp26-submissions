#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

void solve()
{
    ll n, p, r, k, i, cant=0;
    cin >> n >> p >> r >> k;
    vector<ll>e(n);
    for(i=0; i<n; i++)
        cin >> e[i];
    for(i=0; i<n; i++)
    {
        p-=e[i];
        cant++;
        if(p<0)
        {
            cout << "nah i'd lose\n";
            return;
        }
        if(cant==k)
        {
            cant=0;
            p+=r;
        }
    }
    cout << "nah i'd win\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
