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
                int n, m;
                cin >> n >> m;

                /*
                0 1 2 3 4
                2 3 4 0 1
                4 0 1 2 3
                */

                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                cout << (2 * i + j) % 5 << " ";
                        }
                        cout << '\n';
                }
        }
        
        return 0;
}