#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) {
        int k,n,m,p,q; cin>>k>>n>>m>>p>>q;
        vector<vector<int>> a(n,vector<int>(m,-1));
        int sx,sy;
        for (int i=0;i<k;i++) {
            int x,y; cin>>x>>y;
            a[x][y] = i;
            if (i==0) {
                sx = x;
                sy = y;
            }
        }
        while (true) {
            sx = (sx+q)%n;
            sy = (sy+p)%m;
            if (a[sx][sy]>=0) {
                cout<<a[sx][sy]<<"\n";
                break;
            }
        }
    }
    return 0;
}