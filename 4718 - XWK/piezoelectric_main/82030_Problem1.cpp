#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) {
        int a,b,c,d; cin>>a>>b>>c>>d;
        cout<<c/((a*2+b*2)*d)<<"\n";
    }
    return 0;
}