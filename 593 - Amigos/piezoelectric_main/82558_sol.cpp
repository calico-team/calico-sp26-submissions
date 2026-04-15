#include <bits/stdc++.h>

using namespace std;
void solve() {
    int L,W,E,R;
    cin >> L >> W >> E >> R;
    int eachlap = (2*L + 2*W)*R;
    int nooflaps = E/eachlap;
    cout<<nooflaps<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}