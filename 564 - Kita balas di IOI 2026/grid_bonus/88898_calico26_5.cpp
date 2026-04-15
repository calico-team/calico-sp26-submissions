#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int inff = 1e18;

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t;
        cin >> t;

        while (t --> 0) {
                int n;
                cin >> n;

                vector<int> a(n + 1);
                for (int i = 1; i <= n; i++) cin >> a[i];

                vector<vector<int>> dp(n + 1, vector<int>(2, inff));
                dp[1][0] = 0;
                for (int i = 2; i <= n; i++) {
                        dp[i][0] = min(dp[i][0], dp[i - 1][0] + abs(a[i] - a[i - 1]));
                        dp[i][0] = min(dp[i][0], dp[i - 1][1]);

                        if (i + 1 <= n) {       
                                int b = a[i];
                                if (max(a[i - 1], a[i + 1]) < a[i]) {
                                        b = max(a[i - 1], a[i + 1]);
                                } else if (min(a[i - 1], a[i + 1]) > a[i]) {
                                        b = min(a[i - 1], a[i + 1]);
                                }

                                dp[i][1] = min(dp[i][1], dp[i - 1][0] + abs(b - a[i - 1]) + abs(b - a[i + 1]) + abs(b - a[i]));
                        }
                }

                int x = 0;
                vector<int> b(n + 1);
                for (int i = n; i >= 1; i--) {
                        if (x == 1) {
                                b[i] = a[i];
                                if (max(a[i - 1], a[i + 1]) < a[i]) {
                                        b[i] = max(a[i - 1], a[i + 1]);
                                } else if (min(a[i - 1], a[i + 1]) > a[i]) {
                                        b[i] = min(a[i - 1], a[i + 1]);
                                }
                        } else if (x == 0) {
                                b[i] = a[i];
                        }

                        if (x == 0) {
                                if (dp[i][0] == dp[i - 1][1]) {
                                        x = 1;
                                } else {
                                        x = 0;
                                }
                        } else if (x == 1) {
                                x = 0;
                        }
                }

                for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
        }
        
        return 0;
}