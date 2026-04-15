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

                if (max(a[0], a[2]) < a[1]) {
                        a[1] = max(a[0], a[2]);
                } else if (min(a[0], a[2]) > a[1]) {
                        a[1] = min(a[0], a[2]);
                }

                for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
        }
        
        return 0;
}