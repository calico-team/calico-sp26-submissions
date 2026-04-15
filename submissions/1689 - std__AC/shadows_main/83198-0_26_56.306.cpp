#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1100;
int cnts[N];
int t, n, ans, ans2;
char chr;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cnts[i] = 0;
            for (int j = 1; j <= n; j++) {
                cin >> chr;
                cnts[i] += '#' == chr;
            }
        }
        ans = 0;
        ans2 = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                cin >> chr;
                cnt += '#' == chr;
            }
            ans += cnts[i] * cnt;
            ans2 += max(cnts[i], cnt);
        }
        cout << ans << ' ' << ans2 << endl;
    }
    return 0;
}