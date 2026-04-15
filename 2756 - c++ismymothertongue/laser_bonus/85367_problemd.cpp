#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, a, b, c;
        cin >> x >> y >> a >> b >> c;
        vector <pair <int, int>> v(x);
        for (int j = 0; j < x; j++) {
            cin >> v[j].fi >> v[j].se;
        }
        int x2 = v[0].fi;
        int y2 = v[0].se;
        int cnt = -1;
        int ans = -1;
        for (int j = 0; j < x; j++) {
            int dx = (v[j].fi - x2) % y;
            if (dx < 0){
				dx += y;
			}
            int dy = (v[j].se - y2) % a;
            if (dy < 0){
				dy += a;
			}
            int t = -1;
            for (int k = 0; k < y * a; k++) {
                if ((c * k) % y == dx && (b * k) % a == dy) {

                    if (j == 0 && k == 0) continue;

                    t = k;
                    break;
                }
            }
            if (j == 0 && t == -1) {
                for (int step = 1; step < y * a; step++) {
                    if ((c * step) % y == 0 && (b * step) % a == 0) {
                        t = step;
                        break;
                    }
                }
            }
            if (t != -1 && (cnt == -1 || t < cnt)) {
                cnt = t;
                ans = j;   
            }
        }
        cout << ans << endl;
    }
}
