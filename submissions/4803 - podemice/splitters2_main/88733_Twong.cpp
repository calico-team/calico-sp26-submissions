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
    int p, a, b;
    cin >> p >> a >> b;
    vi base(a+b, 0);
    rep(i, 0, a) {
        base[i] = p % 2;
        p /= 2;
    }
    rep(j, 0, b) {
        base[a+j] = p % 3;
        p /= 3;
    }

    vc<vc<char>> out(300, vc<char>(3, '.'));
    out[0][0] = '>'; out[0][1] = 'v';
    int r = 1;
    for (int i=a+b-1; i>=a; i--) {
        out[r][1] = 'S';
        if (base[i]) out[r][0] = '<';
        else out[r][0] = 'X';
        if (base[i] == 2) out[r][2] = '>';
        else out[r][2] = 'X';
        out[r+1][1] = 'v';
        r += 2;
    }

    for (int i=a-1; i>=0; i--) {
        out[r][1] = 'S';
        if (base[i]) out[r][0] = '<';
        else out[r][0] = 'X';
        out[r+1][1] = 'v';
        r += 2;
    }
    out[r-1][1] = 'X';

    cout << "300 3\n";
    rep(i, 0, 300) {
        rep(j, 0, 3) {
            cout << out[i][j];
        } cout << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) solve();
}