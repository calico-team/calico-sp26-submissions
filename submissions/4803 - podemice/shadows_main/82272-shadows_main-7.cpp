#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define vc vector
#define fs first
#define sd second

typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;
    vi r1(n, 0), r2(n, 0);
    rep(i, 0, n) rep(j, 0, n) {
        char c;
        cin >> c;
        if (c == '#') r1[i]++;
    }
    rep(i, 0, n) rep(j, 0, n) {
        char c;
        cin >> c;
        if (c == '#') r2[i]++;
    }

    int mi = 0, ma = 0;
    rep(i, 0, n) {
        mi += max(r1[i], r2[i]);
        ma += r1[i] * r2[i];
    }

    cout << ma << " " << mi << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) solve();
}