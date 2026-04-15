#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[]={2,3,4,0,1};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m,0));
        for (int i=0;i<m;i++) {
            a[0][i] = h[i%5];
            a[1][i] = i%5;
        }
        for (int i=2;i<n;i++) {
            vector<bool> w(5,true);
            for (int j=0;j<3;j++) w[a[i-1][j]] = false;
            w[a[i-2][1]] = false;
            int pt=0;
            for (int j=0;j<5;j++) {
                if (w[h[j]]) pt = j;
            }
            a[i][0] = h[(pt+4)%5];
            for (int j=1;j<m;j++) {
                a[i][j] = h[pt%5];
                pt++;
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) cout<<a[i][j]<<(j==(m-1)?"\n":" ");
        }
    }
    return 0;
}