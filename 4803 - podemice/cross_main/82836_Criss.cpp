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
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (j % 2 == 0) {
                cout << (i+(j/2))%5;
            } else {
                cout << (i+(j/2)+3)%5;
            }

            if (j != m-1) cout << ' ';
        } cout << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) solve();
}