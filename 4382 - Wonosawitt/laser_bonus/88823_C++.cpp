#include<bits/stdc++.h>
using namespace std;

void FREOPEN(const string &prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

#define debug(c) cout << #c << " = " << c << endl
#define debugc() cout << "PASS" << endl

#define nl "\n"
#define fl flush
#define int long long

#define ll long long
#define str string
#define ld long double

#define Pb push_back
#define pB pop_back
#define ub upper_bound
#define lb lower_bound
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ft first
#define sc second

int fpb(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1, d = fpb(b, a % b, x1, y1);
    x = y1, y = x1 - y1 * (a / b);
    return d;
}

int mdinv(int a, int m) {
    int x, y;
    fpb(a, m, x, y);
    return (x % m + m) % m;
}

void solve() {
    int k, n, m, p, q; cin >> k >> n >> m >> p >> q;

    vector<pii> a(k);
    for(int i=0;i<k;i++) cin >> a[i].ft >> a[i].sc;

    int x0 = a[0].ft, y0 = a[0].sc, res = -1, ans = -1;
    for(int i=0;i<k;i++) {
        int dx = (a[i].ft - x0) % n;
        if (dx < 0) dx += n;

        int dy = (a[i].sc - y0) % m;
        if (dy < 0) dy += m;

        int gx = gcd(q, n);
        if (dx % gx != 0) continue;

        int nx = n / gx, qx = q / gx, dxr = dx / gx;
        int tx = (dxr * mdinv(qx, nx)) % nx;
        int gy = gcd(p, m);

        if (dy % gy != 0) continue;

        int my = m / gy, py = p / gy, dyr = dy / gy;
        int ty = (dyr * mdinv(py, my)) % my;

        int diff = (ty - tx) % my;
        if (diff < 0) diff += my;

        int g = gcd(nx, my);
        if (diff % g != 0) continue;

        int mx = my / g, nxr = nx / g, dr = diff / g;

        int crt = (dr * mdinv(nxr, mx)) % mx;
        int t = tx + crt * nx;

        if (t == 0) t = nx * my / g;
        if (res == -1 || t < res) res = t, ans = i;
    }

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0); 
    // FREOPEN("");
    
    int T = 1; cin >> T;
    while(T--) solve();
}
