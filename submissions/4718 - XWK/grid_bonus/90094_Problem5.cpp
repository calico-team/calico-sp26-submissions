#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n; cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int> ans(n+1);
    if (n==1) {
        cout<<a[1]<<"\n";
        return ;
    }
    else if (n==2) {
        cout<<a[1]<<" "<<a[2]<<"\n";
        return ;
    }
    ans[1] = a[1];
    for (int i=2;i<n;i++) {
        int v1=ans[i-1],v2=a[i];
        if (v1>v2) swap(v1,v2);
        if (a[i+1]>=v1 && a[i+1]<=v2) ans[i] = a[i+1];
        else if (a[i+1]<v1) ans[i] = v1;
        else ans[i] = v2;
    }
    ans[n] = a[n];
    for (int i=1;i<=n;i++) cout<<ans[i]<<(i==n?"\n":" ");
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}