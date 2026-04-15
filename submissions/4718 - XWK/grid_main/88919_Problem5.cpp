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
    ans[n] = min(a[n],a[n-1]);
    for (int i=(n-1);i>=1;i--) ans[i] = min(ans[i+1],a[i]);
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