#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& x : a) cin >> x;

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = a[i];
        }

        for (int i = 1; i < n - 1; i++) {
            if (ans[i - 1] > ans[i] && ans[i + 1] > ans[i]) {
                ans[i] = min(ans[i - 1], ans[i + 1]);
            } else if (ans[i - 1] < ans[i] && ans[i + 1] < ans[i]) {
                ans[i] = max(ans[i - 1], ans[i + 1]);
            }
        }

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}