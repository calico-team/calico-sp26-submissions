#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll a[100000];
void solve() {
    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    if (n == 1) {
        cout<<a[0]<<'\n';
        return;
    }

    if (n == 2) {
        cout<< a[0] << " " << a[1] <<'\n';
        return;
    }

    int h = max(a[0], a[2]), l = min(a[0], a[2]);
    if (a[1] > h) {
        a[1] = h;
    } else if (a[1] < l) {
        a[1] = l;
    }
    cout << a[0] << " " << a[1] << " " << a[2] <<'\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    
    return 0;
}