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
    ll n, m, i, j;
    cin >> n >> m;
    vector<vector<ll>>v(n,vector<ll>(m,0));
    if(n>0&&m>0)
        v[1][1]=1;
    for(i=1; i<n-1; i++)
    {
        for(j=1; j<m-1; j++)
        {
            if(v[i][j]==0)
            {
                v[i-1][j]=3;
                v[i+1][j]=1;
                v[i][j-1]=4;
                v[i][j+1]=2;
            }
            else if(v[i][j]==1)
            {
                v[i-1][j]=0;
                v[i][j+1]=3;
                v[i][j-1]=2;
                v[i+1][j]=4;
            }
            else if(v[i][j]==2)
            {
                v[i-1][j]=4;
                v[i+1][j]=3;
                v[i][j-1]=0;
                v[i][j+1]=1;
            }
            else if(v[i][j]==3)
            {
                v[i-1][j]=2;
                v[i+1][j]=0;
                v[i][j-1]=1;
                v[i][j+1]=4;
            }
            else if(v[i][j]==4)
            {
                v[i-1][j]=1;
                v[i+1][j]=2;
                v[i][j-1]=3;
                v[i][j+1]=0;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cout << v[i][j];
            if(j+1<m)
                cout << ' ';
        }
        cout << '\n';
    }
    
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
