#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, p, r, k; cin >> n >> p >> r >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    for (int i = 0; i < n; i++) {
        if (i != 0 && (i % k) == 0) p += r;
        p -= a[i];

        if (p < 0) {
            cout << "nah i'd lose" << endl;
            return;
        }
    }

    cout << "nan i'd win" << endl;
    return;
}

int main() {
	int t; cin >> t;
    while (t--) solve();
}
