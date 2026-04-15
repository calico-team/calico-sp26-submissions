#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, p, r, k;
    cin>>n>>p>>r>>k;
    int c = 0;
    bool lose = false;
    for (int i = 0; i < n; i++) {
        int e;
        cin>>e;
        p -= e;
        if (p < 0) {
            lose = true;
        }
        c++;
        if (c == k) {
            c = 0;
            p += r;
        }
    }
    if (lose) {
        cout << "nah i'd lose\n";
    } else {
        cout << "nah i'd win\n";
    }

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