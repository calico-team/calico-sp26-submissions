
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;


void solve() {
    int n; cin >> n;
    int mn = 0;
    int mx = 0;

    vector<vector<char>> s1(n, vector<char>(n, '!'));
    vector<vector<char>> s2(n, vector<char>(n, '!'));

    for (int i = 0; i < n; i++) {
        string r; cin >> r;
        for (int j = 0; j < n; j++) s1[i][j] = r[j];
    }

    for (int i = 0; i < n; i++) {
        string r; cin >> r;
        for (int j = 0; j < n; j++) s2[i][j] = r[j];
    }

    for (int z = 0; z < n; z++) {
        int a = 0;
        int b = 0;
        for (int j = 0; j < n; j++) a += s1[z][j] == '#';
        for (int j = 0; j < n; j++) b += s2[z][j] == '#';

        mn += max(a, b);
        mx += a * b;
    }

    cout << mx << " " << mn << "\n";
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();


    return 0;

}