#include <bits/stdc++.h>
#define int long long
using namespace std;
char grid[20][20];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m;
vector<pair<int,int>> ans;
pair<int,int> calc(char x) {
    if (x=='^') return {-1,0};
    else if (x=='v') return {1,0};
    else if (x=='<') return {0,-1};
    else return {0,1};
}
void floodfill(int r,int c,pair<int,int> val) {
    char curr=grid[r][c];
    if (curr=='X') return ;
    else if (curr=='S') {
        int cnt=0;
        for (int i=0;i<4;i++) {
            int nx=dx[i]+r,ny=dy[i]+c;
            if (nx<1 || nx>n || ny<1 || ny>m) continue;
            if (grid[nx][ny]=='.') continue;
            if (grid[nx][ny]=='X') {
                cnt++;
                continue;
            }
            if ((nx+calc(grid[nx][ny]).first)!=r || (ny+calc(grid[nx][ny]).second)!=c) cnt++;
        }
        for (int i=0;i<4;i++) {
            int nx=dx[i]+r,ny=dy[i]+c;
            if (nx<1 || nx>n || ny<1 || ny>m) continue;
            if (grid[nx][ny]=='.') continue;
            if ((nx+calc(grid[nx][ny]).first)!=r || (ny+calc(grid[nx][ny]).second)!=c) {
                floodfill(nx,ny,{val.first,val.second*cnt});
            }
        }
    }
    else {
        int nx=r+calc(grid[r][c]).first,ny=c+calc(grid[r][c]).second;
        if (nx<1 || nx>n || ny<1 || ny>m) {
            ans.push_back(val);
            return ;
        }
        floodfill(nx,ny,val);
    }
}
int gcd(int a,int b) {
    return (b==0?a:gcd(b,a%b));
}
void solve() {
    cin>>n>>m;
    ans.clear();
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>grid[i][j];
        }
    }
    floodfill(1,1,{1,1});
    if (ans.empty()) cout<<0<<" "<<1<<"\n";
    else {
        pair<int,int> op={0,1};
        for (auto &i:ans) {
            int tp=(op.first*i.second+op.second*i.first),bt=(i.second*op.second);
            op = {tp/gcd(tp,bt),bt/gcd(tp,bt)};
        }
        cout<<op.first<<" "<<op.second<<"\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}