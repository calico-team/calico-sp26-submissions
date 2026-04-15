#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10100;
int arr[N];
int t, n, p, m, k, x;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> p >> m >> k;
        string ans = "nah i'd win";
        int ck = k;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (p < x) ans = "nah i'd lose";
            p -= x;
            if (!--ck) {
                ck = k;
                p += m;
            }
        }
        cout << ans << endl;
    }
    return 0;
}