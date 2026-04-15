// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long int ll;

int main() {
    ll T;
    cin>>T;
    while(T--){
        ll k,n,m,p,q;
        cin>>k>>n>>m>>p>>q;
        vector<pair<ll,ll>> ast;
        vector<vector<ll>> grid(m,vector<ll> (n,-1));
        

        for(ll i = 0;i<k;++i){
            ll a,b;
            cin>>a>>b;
            ast.push_back({a,b});
            grid[b][a] = i;
        }
        ll xpos = (ast[0].f+q)%m;
        ll ypos = (ast[0].s+p)%n;

        while(grid[ypos][xpos] == -1){
            xpos+=q;
            ypos+=p;
            xpos%=n;
            ypos%=m;
        }
        cout<<grid[ypos][xpos]<<endl;
    }
}
