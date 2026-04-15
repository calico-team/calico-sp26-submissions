#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10100;
int arr[N];
int t, n, p, m, k;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> p >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        sort(arr + 1, arr + n + 1);
        string ans = "nah i’d win";
        int ck = k;
        for (int i = 1; i <= n; i++) {
            if (p < arr[i]) ans = "nah i’d lose";
            p -= arr[i];
            if (!--ck) {
                ck = k;
                p += m;
            }
        }
        cout << ans << endl;
    }
    return 0;
}