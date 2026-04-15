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
    cout<<a[1]<<" ";
    int v=a[3];
    sort(begin(a)+1,end(a));
    cout<<a[2]<<" "<<v<<"\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}