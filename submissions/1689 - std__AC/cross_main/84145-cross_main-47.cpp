#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (2 * i + j) % 5 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}