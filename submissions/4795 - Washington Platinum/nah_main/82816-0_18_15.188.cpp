#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, score, r, k;
    cin >> n >> score >> r >> k;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    for (int i = 0; i < n; i++) {
        if (i % k == 0 && i != 0) {
            score += r;
        }
        score -= vals[i];
        if (score < 0) {
            cout << "nah i'd lose" << '\n';
            return;
        }
    }
    cout << "nah i'd win" << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}