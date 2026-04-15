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

        vector<int> backup(n);
        for (int i = 0; i < n; i++) {
            backup[i] = a[i];
        }
        sort(a.begin(), a.end());

        if (n % 2 == 0) {
            // Even case
            double median = ((double) a[n / 2 - 1] + a[n / 2]) / 2.0;\
            for (int i = 0; i < n; i++) {
                if (backup[i] < median) {
                    cout << floor(median);
                } else {
                    cout << ceil(median);
                }
                cout << " ";
            }
        } else {
            for (int i = 0; i < n; i++) {
                cout << a[n / 2] << " ";
            }
        }

        cout << "\n";
    }
}
