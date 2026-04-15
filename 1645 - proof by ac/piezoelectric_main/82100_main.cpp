#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1; cin >> t;
    while (t--) {
        int l,w,e,r;
        cin>>l>>w>>e>>r;
        int req = e/r + (e%r==0?0:1);
        int len = 2*l+2*w;
        cout<<req/len+(req%len==0?0:1)<<nl;
    }

    return 0;
}