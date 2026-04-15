#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) {
        string a,b; cin>>a>>b;
        int pt=0;
        for (int i=0;i<(int)a.size();i++) {
            if (pt==(int)b.size()) {
                a[i] = '#';
                continue;
            }
            if (a[i]!=b[pt]) a[i] = '#';
            else pt++;
        }
        cout<<a<<"\n";
    }
    return 0;
}