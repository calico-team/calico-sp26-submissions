#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n , m;
        cin >> n >> m;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0; j < m; j++) {
                int ans = (i + 2 * j) % 5;
                cout << ans << " ";
            }
            cout << '\n'; 
        }
    }
    return 0;
}
