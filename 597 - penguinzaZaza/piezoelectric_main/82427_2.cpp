#include<bits/stdc++.h>

using namespace std;

int t, n, p, r, k;

void solve() {
    cin >> n >> p >> r >> k;
    vector<int> a(n);
    int c = 0;
    for (auto &e: a) cin >> e;
    for (auto &e: a) {
        p -= e;
        c++;
        if (p < 0) return void(cout << "nah i'd lose\n");
        if (c == k) p += r, c = 0;
    }
    cout << "nah i'd win\n";
}

int main() {
    cin >> t;
    while (t--) solve();
}