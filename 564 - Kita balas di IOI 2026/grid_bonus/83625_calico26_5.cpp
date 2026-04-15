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

                for (int i = 1; i < n - 1; i += 2) {
                        if (max(a[i - 1], a[i + 1]) < a[i]) {
                                a[i] = max(a[i - 1], a[i + 1]);
                        } else if (min(a[i - 1], a[i + 1]) > a[i]) {
                                a[i] = min(a[i - 1], a[i + 1]);
                        }
                }

                for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
        }
        
        return 0;
}