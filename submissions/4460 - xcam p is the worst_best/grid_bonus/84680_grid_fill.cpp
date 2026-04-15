#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<long long> a;
        for (int i = 0; i < n; i++) {
            long long ai;
            cin >> ai;

            a.push_back(ai);
        }

        if (n == 1) {
            cout << a[0] << "\n";
            continue;
        }

        vector<long long> b = {a[0]};
        cout << b[0] << " ";
        for (int i = 1; i < n - 1; i++) {
            long long mi = min(b[i - 1], a[i]);
            long long ma = max(b[i - 1], a[i]);
            if (mi <= a[i + 1] && a[i + 1] <= ma) {
                b.push_back(a[i + 1]);
            }
            else if (a[i + 1] > ma) {
                b.push_back(ma);
            }
            else {
                b.push_back(mi);
            }
            cout << b[i] << " ";
        }
        b.push_back(a[n - 1]);
        cout << b[n - 1] << "\n";
    }
}