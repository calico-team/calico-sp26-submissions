#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector <string> g (n);
        for (int i = 0; i < n; i++){
			cin >> g[i];
		}
        vector<tuple<int,int,int,int>> pts; // (u, v, r, c)
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (g[r][c] == '-') {
                    int u = r + c;
                    int v = r - c;
                    pts.push_back({u, v, r, c});
                }
            }
        }
        auto ok = [&](int D, int &bu, int &bv) -> bool {
            for (int i = 0; i < n; i++) {
                int u1 = get<0>(pts[i]);
                int v1 = get<1>(pts[i]);
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    int u = get<0>(pts[j]);
                    int v = get<1>(pts[j]);
                    if (u >= u1 && u <= u1 + D &&
                        v >= v1 && v <= v1 + D) {
                        cnt++;
                        if (cnt >= k) {
                            bu = u1;
                            bv = v1;
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        int lo = 0, hi = n + m;
        int bu = 0, bv = 0;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int tu, tv;
            if (ok(mid, tu, tv)) hi = mid;
            else lo = mid + 1;
        }
        ok(lo, bu, bv);
        vector<pair<int,int>> ans;
        for (auto &[u, v, r, c] : pts) {
            if (u >= bu && u <= bu + lo &&
                v >= bv && v <= bv + lo) {
                ans.push_back({r, c});
                if ((int)ans.size() == k){
					break;
				}
            }
        }
        for (auto &[r, c] : ans) {
            cout << r << " " << c << endl;
        }
    }
}
