#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p, r, k;
        cin >> n >> p >> r >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int count = 0;
        int alive = true;
        for (int i = 0; i < n; i++) {
            p -= v[i];
            if (p < 0) {
                alive = false;
                break;
            }
            count++;
            if (count == k) {
                p += r;
                count = 0;
            }
        }
        if (alive) {
            cout << "nah i'd win\n";
        }
        else {
            cout << "nah i'd lose\n";
        }
    }
}