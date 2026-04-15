#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAXN=20, MAXM=20;

/*
bfs from the start
we keep going and when we hit X dont go no more
if we hit splitter, count how many adj it goes to, and then multiply denominator by this count (or divide numerator)
*/

ll n, m, indeg[MAXN][MAXM];
string s[MAXN];
pair<ll, ll> ans;
pair<ll, ll> am[MAXN][MAXM];
queue<ll> q1, q2;
bool vis[MAXN][MAXM];

pair<ll, ll> reduceFrac(pair<ll, ll> p)
{
    ll g=__gcd(p.first, p.second);
    return {p.first/g, p.second/g};
}

pair<ll, ll> addFrac(pair<ll, ll> p, pair<ll, ll> q)
{
    ll a=p.second, b=q.second;
    ll denom=(a*b)/(__gcd(a, b));
    return reduceFrac({p.first*(denom/a)+q.first*(denom/b), denom});
}

void solve()
{
    cin >> n >> m;
    ans={0, 1};
    for (int i=0; i<n; i++)
    {
        cin >> s[i];
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            am[i][j]={0, 1};
            vis[i][j]=0;
            indeg[i][j]=0;
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (s[i][j]=='>' && j+1<m)
            {
                indeg[i][j+1]++;
            }
            if (s[i][j]=='<' && j-1>=0)
            {
                indeg[i][j-1]++;
            }
            if (s[i][j]=='^' && i-1>=0)
            {
                indeg[i-1][j]++;
            }
            if (s[i][j]=='v' && i+1<n)
            {
                indeg[i+1][j]++;
            }
            if (s[i][j]=='S')
            {
                if (s[i-1][j]!='v')
                {
                    indeg[i-1][j]++;
                }
                if (s[i+1][j]!='^')
                {
                    indeg[i+1][j]++;
                }
                if (s[i][j-1]!='>')
                {
                    indeg[i][j-1]++;
                }
                if (s[i][j+1]!='<')
                {
                    indeg[i][j+1]++;
                }
            }
        }
    }
    am[0][0]={1, 1};
    q1.push(0);
    q2.push(0);
    while (!q1.empty())
    {
        ll x=q1.front(), y=q2.front();
        q1.pop();
        q2.pop();
        if (vis[x][y])
        {
            continue;
        }
        vis[x][y]=1;
        if (s[x][y]=='X')
        {
            continue;
        }
        if (s[x][y]=='<')
        {
            if (y>0)
            {
                am[x][y-1]=addFrac(am[x][y-1], am[x][y]);
                indeg[x][y-1]--;
                if (indeg[x][y-1]==0)
                {
                    q1.push(x);
                    q2.push(y-1);
                }
            }
            else
            {
                ans=addFrac(ans, am[x][y]);
            }
        }
        if (s[x][y]=='^')
        {
            if (x>0)
            {
                am[x-1][y]=addFrac(am[x-1][y], am[x][y]);
                indeg[x-1][y]--;
                if (indeg[x-1][y]==0)
                {
                    q1.push(x-1);
                    q2.push(y);
                }
            }
            else
            {
                ans=addFrac(ans, am[x][y]);
            }
        }
        if (s[x][y]=='v')
        {
            if (x<n-1)
            {
                am[x+1][y]=addFrac(am[x+1][y], am[x][y]);
                indeg[x+1][y]--;
                if (indeg[x+1][y]==0)
                {
                    q1.push(x+1);
                    q2.push(y);
                }
            }
            else
            {
                ans=addFrac(ans, am[x][y]);
            }
        }
        if (s[x][y]=='>')
        {
            if (y<m-1)
            {
                am[x][y+1]=addFrac(am[x][y+1], am[x][y]);
                indeg[x][y+1]--;
                if (indeg[x][y+1]==0)
                {
                    q1.push(x);
                    q2.push(y+1);
                }
            }
            else
            {
                ans=addFrac(ans, am[x][y]);
            }
        }
        if (s[x][y]=='S')
        {
            ll sp=0;
            if (s[x-1][y]!='v' && s[x-1][y]!='.')
            {
                sp++;
            }
            if (s[x+1][y]!='^' && s[x+1][y]!='.')
            {
                sp++;
            }
            if (s[x][y-1]!='>' && s[x][y-1]!='.')
            {
                sp++;
            }
            if (s[x][y+1]!='<' && s[x][y+1]!='.')
            {
                sp++;
            }
            pair<ll, ll> added=am[x][y];
            if (added.first%sp==0)
            {
                added.first/=sp;
            }
            else
            {
                added.second*=sp;
            }
            if (s[x-1][y]!='v' && s[x-1][y]!='.')
            {
                am[x-1][y]=addFrac(am[x-1][y], added);
                indeg[x-1][y]--;
                if (indeg[x-1][y]==0)
                {
                    q1.push(x-1);
                    q2.push(y);
                }
            }
            if (s[x+1][y]!='^' && s[x+1][y]!='.')
            {
                am[x+1][y]=addFrac(am[x+1][y], added);
                indeg[x+1][y]--;
                if (indeg[x+1][y]==0)
                {
                    q1.push(x+1);
                    q2.push(y);
                }
            }
            if (s[x][y-1]!='>' && s[x][y-1]!='.')
            {
                am[x][y-1]=addFrac(am[x][y-1], added);
                indeg[x][y-1]--;
                if (indeg[x][y-1]==0)
                {
                    q1.push(x);
                    q2.push(y-1);
                }
            }
            if (s[x][y+1]!='<' && s[x][y+1]!='.')
            {
                am[x][y+1]=addFrac(am[x][y+1], added);
                indeg[x][y+1]--;
                if (indeg[x][y+1]==0)
                {
                    q1.push(x);
                    q2.push(y+1);
                }
            }
        }
    }
    cout << ans.first << " " << ans.second << "\n";
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