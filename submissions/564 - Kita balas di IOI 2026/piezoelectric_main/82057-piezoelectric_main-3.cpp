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
                int l, w, e, r;
                cin >> l >> w >> e >> r;

                cout << e / ((2 * (l + w)) * r) << '\n';
        }
        
        return 0;
}