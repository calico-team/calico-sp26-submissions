#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()  {
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    int p = (l+w)*2*r;
    if (e%p == 0)  {
        cout << e/p << endl;
    } else  {
        cout << e/p+1 << endl;
    }
}

signed main()   {
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}