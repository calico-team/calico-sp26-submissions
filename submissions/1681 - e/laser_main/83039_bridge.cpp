#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

void solve()
{
    int k , n, m , p, q; cin>>k>>n>>m>>p>>q;
    vector<pair<int,int>>v(k);
    for(int i =0;i<k;i++)cin>>v[i].first >> v[i].second;
    map<pair<int,int>,int>vis;
    for(int i =0;i<k;i++)vis[v[i]] = i;
    int val = lcm(n /__gcd(q, n), m / __gcd(p, m));
    for(int i=1;i<=val;i++){
        int x = (v[0].first + i * q) % n;
        int y = (v[0].second + i * p) % m;
        if(vis.count({x, y})) {
            cout << vis[{x, y}] << "\n";
            return;
        }
    }
    cout <<-1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}