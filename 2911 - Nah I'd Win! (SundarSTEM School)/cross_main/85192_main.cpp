#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define ll long long



void solve() {
    int n, m; cin >> n >> m;
    int mtx[n + 1][m + 1];
    for (int i = 1; i <= m; i++)
        mtx[1][i] = (i - 1) % 5;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mtx[i][j] = (mtx[i-1][j] + 2) % 5;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mtx[i][j] << ' ';
        }
        cout << endl;
    }
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) solve();
    return 0;
}
