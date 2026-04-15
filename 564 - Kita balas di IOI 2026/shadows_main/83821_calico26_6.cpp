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

                vector<int> cnt(n);
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                char c;
                                cin >> c;

                                cnt[i] += (c == '#');
                        }
                }

                int mx = 0, mn = 0;
                for (int i = 0; i < n; i++) {
                        int cnt2 = 0;
                        for (int j = 0; j < n; j++) {
                                char c;
                                cin >> c;

                                cnt2 += (c == '#');
                        }

                        mx += cnt2 * cnt[i];
                        mn += max(cnt2, cnt[i]);
                }

                cout << mx << " " << mn << '\n';
        }
        
        return 0;
}