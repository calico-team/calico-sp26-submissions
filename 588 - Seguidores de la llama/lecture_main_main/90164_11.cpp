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

const ll INF = 1e10;

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

struct FT2 {
    vector<vi> ys; vector<FT> ft;
    FT2(int limx) : ys(limx) {}
    void fakeUpdate(int x, int y) {
        for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
    }
    void init() {
        for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
    }
    int ind(int x, int y) {
        return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
    void update(int x, int y, ll dif) {
        for (; x < sz(ys); x |= x + 1)
            ft[x].update(ind(x, y), dif);
    }
    ll query(int x, int y) {
        ll sum = 0;
        for (; x; x &= x - 1)
            sum += ft[x-1].query(ind(x-1, y));
        return sum;
    }
    ll query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1, y2) - query(x2, y1) + query(x1, y1);
    }
};
 
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
        
        auto bs = [&]() {
            int lo = 0, hi = n + m;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (check(mid)) hi = mid;
                else lo = mid;
            }
            return hi;
        };
        
        int d = bs();
        
        vector<vi> occupiedLeft(n, vi(m, 0));
        forn(i, n) forsn(j, 1, m) {
            occupiedLeft[i][j] = occupiedLeft[i][j - 1] + (s[i][j - 1] == '#');
        }
        vector<vi> occupiedRight(n, vi(m, 0));
        forn(i, n) forn(j, m - 1) {
            occupiedRight[i][j] = occupiedRight[i][j + 1] + (s[i][j + 1] == '#');
        }
        
        vector<vii> where(m + 1);
        forn(x, n) forn(y, m) {
            if (s[x][y] == '-') {
                int aura = min(occupiedLeft[x][y], occupiedRight[x][y]);
                assert(aura < m);
                where[aura].eb(x - y + m, x + y);
            }
        }
        
        vector<vi> lo(n + m - d + 1, vi(n + m - d + 1, 0));
        vector<vi> hi(n + m - d + 1, vi(n + m - d + 1, m + 1));
        vector<vll> sumRet(n + m - d + 1, vll(n + m - d + 1, INF));
        
        forn(iter, 10) {
            vector<vii> queries(m + 1);
            forn(x, n + m - d + 1) forn(y, n + m - d + 1) {
                int mid = (lo[x][y] + hi[x][y]) / 2;
                queries[mid].eb(x, y);
            }
            FT2 sum(n + m), cnt(n + m);
            forn(aura, m) for (auto [x, y] : where[aura]) sum.fakeUpdate(x, y), cnt.fakeUpdate(x, y);
            sum.init(), cnt.init();
            forn(aura, m + 1) {
                for (auto [x, y] : queries[aura]) {
                    ll currSum = sum.query(x, y, x + d, y + d);
                    ll currCnt = cnt.query(x, y, x + d, y + d);
                    if (currCnt >= k) {
                        hi[x][y] = aura;
                        sumRet[x][y] = currSum - aura * (currCnt - k);
                    } else {
                        lo[x][y] = aura;
                    }
                }
                for (auto [x, y] : where[aura]) {
                    sum.update(x, y, aura);
                    cnt.update(x, y, 1);
                }
            }
        }
        
        int x = 0, y = 0;
        forn(i, n + m - d + 1) forn(j, n + m - d + 1) {
            if (sumRet[x][y] > sumRet[i][j]) x = i, y = j;
        }
        
        vector<pair<int, ii>> ret;
        forn(i, n) forn(j, m) if (s[i][j] == '-') {
            if (x <= i - j + m && i - j + m < x + d &&
                y <= i + j && i + j < y + d) {
                int aura = min(occupiedLeft[i][j], occupiedRight[i][j]);
                ret.eb(aura, make_pair(i, j));
            }
        }
        
        sort(all(ret));
        assert(sz(ret) >= k);
        ret.resize(k);
        for (auto [a, p] : ret) cout << p.fst << " " << p.snd << "\n";
    }
    
    return 0;
}
