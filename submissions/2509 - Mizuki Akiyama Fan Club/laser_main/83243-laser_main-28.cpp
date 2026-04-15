#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define endl "\n"

constexpr int mod = 998244353;

void solve() {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    pi first;
    vector<vector<int>> ind(1000, vector<int>(1000, -1));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        if (i == 0) {
            first = {x, y};
        }
        ind[x][y] = i;
    }
    int x = first.f;
    int y = first.s;
    while (true) {
        x += q;
        y += p;
        x %= n;
        y %= m;
        if (ind[x][y] != -1) {
            cout << ind[x][y] << endl;
            return;
        }
    }
}

int main() {
    cin.tie(0);     
    ios_base::sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
 
    for (int tc = 0; tc < t; tc++) {
        solve();
    }
 
    return 0;
}