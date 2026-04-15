#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define dforn(i, n) dforsn(i, 0, n)
 
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vb = vector<bool>;
using pll = pair<ll, ll>;
using bint = __int128;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
#define pb push_back
#define eb emplace_back
 
#define fst first
#define snd second
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    forn(_, t) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> s(n);
        forn(i, n) cin >> s[i];
        vector<vi> points(n + m);
        forn(x, n) forn(y, m) {
            if (s[x][y] == '-') points[x - y + m].pb(x + y);
        }
        
        auto check = [&](int d) {
            vi cnt(n + m, 0);
            forn(x, n + m) {
                for (int y : points[x]) cnt[y]++;
                if (x - d >= 0) for (int y : points[x - d]) cnt[y]--;
                int sum = 0;
                forn(y, n + m) {
                    sum += cnt[y];
                    if (y - d >= 0) sum -= cnt[y - d];
                    if (sum >= k) return true;
                }
            }
            return false;
        };
        
        int lo = 0, hi = n + m;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid;
        }
        
        int d = hi;
        vi cnt(n + m, 0);
        forn(x, n + m) {
            for (int y : points[x]) cnt[y]++;
            if (x - d >= 0) for (int y : points[x - d]) cnt[y]--;
            int sum = 0;
            forn(y, n + m) {
                sum += cnt[y];
                if (y - d >= 0) sum -= cnt[y - d];
                if (sum >= k) {
                    vii ret;
                    forn(i, n) forn(j, m) if (s[i][j] == '-') {
                        if (i - j + m > x - d && i - j + m <= x && 
                            i + j > y - d && i + j <= y && sz(ret) < k) {
                            ret.eb(i, j);
                        }
                    }
                    assert(sz(ret) == k);
                    forn(i, k) cout << ret[i].fst << " " << ret[i].snd << "\n";
                    goto nextTestcase;
                }
            }
        }
        
        assert(false);
        nextTestcase:;
    }
    
    return 0;
}
