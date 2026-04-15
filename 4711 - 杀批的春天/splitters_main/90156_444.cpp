#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> factory;
vector<pair<ll,ll>> fract;
void travel(int x, int y, ll numer, ll denom, int prevx, int prevy)
{
    if (x < 0 || x >= factory.size() || y < 0 || y >= factory[0].size())
    {
        fract.push_back({numer,denom}); return;
    }
    if (factory[x][y] == '^') travel(x-1,y,numer,denom,x,y);
    else if (factory[x][y] == 'v') travel(x+1,y,numer,denom,x,y);
    else if (factory[x][y] == '<') travel(x,y-1,numer,denom,x,y);
    else if (factory[x][y] == '>') travel(x,y+1,numer,denom,x,y);
    else if (factory[x][y] == 'S')
    {
        vector<bool> poss(4,true);
        if (prevy == y - 1) poss[0] = false;
        if (prevx == x - 1) poss[1] = false;
        if (prevy == y + 1) poss[2] = false;
        if (prevx == x + 1) poss[3] = false;
        if (factory[x][y-1] == '>' || factory[x][y-1] == '.') poss[0] = false;
        if (factory[x-1][y] == 'v' || factory[x-1][y] == '.') poss[1] = false;
        if (factory[x][y+1] == '<' || factory[x][y+1] == '.') poss[2] = false;
        if (factory[x+1][y] == '^' || factory[x+1][y] == '.') poss[3] = false;
        int cnt = 0;
        for (int i = 0; i < 4; i++) cnt += poss[i];
        if (poss[0]) travel(x,y-1,numer,denom*cnt,x,y);
        if (poss[1]) travel(x-1,y,numer,denom*cnt,x,y);
        if (poss[2]) travel(x,y+1,numer,denom*cnt,x,y);
        if (poss[3]) travel(x+1,y,numer,denom*cnt,x,y);
    }else
    {
        return;
    }
}

int gcd(ll x, ll y)
{
    if (y == 0) return x;
    return gcd(y,x % y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        factory.clear(); factory.resize(n); fract.clear();
        for (int i = 0; i < n; i++) cin >> factory[i];
        travel(0,0,1,1,-1,-1);
        ll denom = 1, numer = 0;
        for (pair<ll,ll> p1 : fract)
        {
            if (denom % p1.second != 0)
            {
                numer *= p1.second;
                numer += p1.first * denom;
                denom *= p1.second;
            }else
            {
                numer += p1.first * (denom / p1.second);
            }
        }
        int Gcd = gcd(numer,denom);
        cout << numer / Gcd << " " << denom / Gcd << endl;
    }
} 