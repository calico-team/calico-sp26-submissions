#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) {
        int n,p,r,k; cin>>n>>p>>r>>k;
        vector<int> a(n);
        for (auto &i:a) cin>>i;
        int curr=p,g=1,cnt=0;
        for (int i=0;i<n;i++) {
            if (cnt==k) {
                cnt = 0;
                curr+=r;
            }
            curr-=a[i];
            if (curr<0) {
                g = 0;
                break;
            }
            cnt++;
        }
        if (g) cout<<"nah i'd win\n";
        else cout<<"nah i'd lose\n";
    }
    return 0;
}