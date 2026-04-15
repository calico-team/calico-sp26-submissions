#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int cnts[N];
string str;
int t, n, ans, ans2;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> str;
            cnts[i] = 0;
            for (char j : str) {
                cnts[i] += '#' == j;
            }
        }
        ans = 0;
        ans2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> str;
            int cnt = 0;
            for (char j : str) {
                cnt += '#' == j;
            }
            ans += cnts[i] * cnt;
            ans2 += max(cnts[i], cnt);
        }
        cout << ans << ' ' << ans2 << '\n';
    }
    return 0;
}