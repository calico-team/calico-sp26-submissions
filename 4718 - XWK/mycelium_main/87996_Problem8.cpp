#include <bits/stdc++.h>
#define int long long
using namespace std;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void solve() {
    int a,b,c,d; cin>>a>>b>>c>>d;
    vector<vector<int>> grid(300,vector<int>(300,0));
    vector<pair<int,int>> g,m;
    a+=150; b+=150; c+=150; d+=150;
    grid[a][b] = 1;
    grid[c][d] = 2;
    g.push_back({a,b});
    m.push_back({c,d});
    int st=0;
    while (true) {
        st++;
        vector<pair<int,int>> tem;
        if (st%2==0) {
            for (auto i:g) {
                for (int j=0;j<4;j++) {
                    int nx=i.first+dx[j],ny=i.second+dy[j];
                    if (grid[nx][ny]==0) {
                        grid[nx][ny]++;
                        tem.push_back({nx,ny});
                    }
                }
            }
            for (auto i:tem) g.push_back(i);
            tem.clear();
        }
        if (st%7==0) {
            for (auto i:m) {
                for (int j=0;j<4;j++) {
                    int nx=i.first+dx[j],ny=i.second+dy[j];
                    if (grid[nx][ny]==0) {
                        grid[nx][ny]+=2;
                        tem.push_back({nx,ny});
                    }
                }
            }
            if (tem.empty()) break;
            for (auto i:tem) m.push_back(i);
        }
    }
    cout<<m.size()<<"\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}