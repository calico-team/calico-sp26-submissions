/*
*/

#include <bits/stdc++.h>
#define int long long
#define setmax(a, b) a = std::max(a,b);
#define setmin(a, b) a = std::min(a,b);
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = a; i >= (b); --i)
const int INF = std::numeric_limits<int>::max()/20;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n,m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        int s = 0;
        rep(i,0,n) {
            int x = s;
            rep(j,0,m) {
                a[i][j] = x++;
                x%= 5;
            }
            s += 2;
            s %= 5;
        }
        for (auto& v : a) {
            for (auto x : v) cout << x << " ";
            cout << '\n';
        }
    }   

    return 0;
}