
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;


void solve() {
    string a, b; cin >> a >> b;
    vector<char> ans;
    int lst = 0;

    for (int i = 0; i < a.size(); i++) {
        if (lst < b.size() and a[i] == b[lst]) {
            ans.push_back(a[i]);
            lst++;
        }
        else {
            ans.push_back('#');
        }
    }

    for (auto i : ans) cout << i;
    cout << "\n";
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();


    return 0;

}