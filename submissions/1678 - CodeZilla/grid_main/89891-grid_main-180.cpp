#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, p, r, k;
        cin >> n >> p >> r >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int power = p;
        int uses = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (power < a[i]) {
                while (uses > 0 && power < a[i]) {
                    power += r;
                    uses--;
                }
                if (power < a[i]) {
                    ok = false;
                    break;
                }
            }

            power -= a[i];

            if ((i + 1) % k == 0) {
                uses++;
            }
        }

        if (ok) cout << "nah i'd win\n";
        else cout << "nah i'd lose\n";
    }

    return 0;
}