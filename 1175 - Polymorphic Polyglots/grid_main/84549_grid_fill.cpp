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

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            cout << a[n / 2] << " ";
        }
        cout << "\n";
    }
}
