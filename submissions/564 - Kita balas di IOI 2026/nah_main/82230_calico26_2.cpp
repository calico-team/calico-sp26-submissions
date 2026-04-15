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
                int n, p, r, k;
                cin >> n >> p >> r >> k;

                int ok = 1, cnt = 0;
                for (int i = 0; i < n; i++) {
                        int x;
                        cin >> x;

                        if (p < x) {
                                ok = 0;
                        }

                        p -= x;
                        cnt += 1;
                        if (cnt == k) {
                                p += r;
                                cnt = 0;
                        }
                }

                cout << (ok ? "nah i'd win" : "nah i'd lose") << '\n';
        }
        
        return 0;
}