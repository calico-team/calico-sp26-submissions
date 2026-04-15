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
                int k, n, m, p, q;
                cin >> k >> n >> m >> p >> q;

                int sx, sy;
                vector<vector<int>> id(n, vector<int>(m, -1));
                for (int i = 0; i < k; i++) {
                        int x, y;
                        cin >> x >> y;

                        id[x][y] = i;
                        if (i == 0) {
                                sx = x;
                                sy = y;
                        }
                }

                for (int i = 0; i < n * m; i++) {
                        sx = (sx + q) % n;
                        sy = (sy + p) % m;

                        if (id[sx][sy] != -1) {
                                cout << id[sx][sy] << '\n';
                                break;
                        }
                }
        }
        
        return 0;
}