#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t;
        cin >> t;

        while (t --> 0) {
                int n;
                cin >> n;

                vector<int> a(n);
                for (int i = 0; i < n; i++) cin >> a[i];

                vector<int> b = a, c = a;
                for (int i = 1; i < n - 1; i += 2) {
                        if (max(a[i - 1], a[i + 1]) < a[i]) {
                                a[i] = max(a[i - 1], a[i + 1]);
                        } else if (min(a[i - 1], a[i + 1]) > a[i]) {
                                a[i] = min(a[i - 1], a[i + 1]);
                        }
                }

                for (int i = n - 2; i >= 1; i -= 2) {
                        if (max(b[i - 1], b[i + 1]) < b[i]) {
                                b[i] = max(b[i - 1], b[i + 1]);
                        } else if (min(b[i - 1], b[i + 1]) > b[i]) {
                                b[i] = min(b[i - 1], b[i + 1]);
                        }
                }

                int ca = 0;
                for (int i = 0; i < n; i++) {
                        ca += abs(a[i] - c[i]);
                        if (i + 1 < n) ca += abs(a[i] - a[i + 1]);
                }

                int cb = 0;
                for (int i = 0; i < n; i++) {
                        cb += abs(b[i] - c[i]);
                        if (i + 1 < n) cb += abs(b[i] - b[i + 1]);
                }

                if (ca < cb) {
                        for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
                } else {
                        for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
                }
        }
        
        return 0;
}