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

        vector<int> a;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;

            a.push_back(ai);
        }

        vector<int> b = {a[0]};
        cout << b[0] << " ";
        for (int i = 1; i < n - 1; i++) {
            int mi = min(b[i - 1], a[i]);
            int ma = max(b[i - 1], a[i]);
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