#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) { ll t = b; b = a % b; a = t; }
    return a;
}

struct Frac {
    ll a, b;
    Frac(ll x = 0, ll y = 1) {
        ll g = gcd(abs(x), abs(y));
        a = x / g;
        b = y / g;
        if (b < 0) { a = -a; b = -b; }
    }
    Frac operator+(const Frac& t) const {
        return Frac(a*t.b + t.a*b, b*t.b);
    }
    Frac operator*(const Frac& t) const {
        return Frac(a*t.a, b*t.b);
    }
};

int n, m;
string g[105];
bool vis[105][105];

Frac dfs(int x, int y) {
    if (x<0||x>=n||y<0||y>=m) return {0,1};
    if (g[x][y] == 'X' || g[x][y] == '.') return {0,1};
    if (vis[x][y]) return {0,1};
    vis[x][y] = 1;

    char c = g[x][y];
    if (c == '^') return x-1<0 ? Frac(1,1) : dfs(x-1,y);
    if (c == 'v') return x+1>=n ? Frac(1,1) : dfs(x+1,y);
    if (c == '<') return y-1<0 ? Frac(1,1) : dfs(x,y-1);
    if (c == '>') return y+1>=m ? Frac(1,1) : dfs(x,y+1);

    vis[x][y] = 0;
    return Frac(1,4);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--) {
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>g[i];
        memset(vis,0,sizeof(vis));
        Frac ans = dfs(0,0);
        cout<<ans.a<<" "<<ans.b<<"\n";
    }
    return 0;
}
