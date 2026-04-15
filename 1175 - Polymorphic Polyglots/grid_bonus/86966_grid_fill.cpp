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
            vector<int> below(n, 0);
            vector<int> above(n, 0);
            below[0] = backup[0] < median;
            above[n - 1] = backup[n - 1] > median;
            for (int i = 1; i < n; i++) {
                below[i] = below[i - 1] + (backup[i] < median);
            }
            for (int i = n - 2; i >= 0; i--) {
                above[i] = above[i + 1] + (backup[i] > median);
            }

            int max_val_u = 0;
            int max_idx_u = 0;
            // Going up
            for (int i = 0; i < n; i++) {
                if (above[i] + below[i] > max_val_u) {
                    max_val_u = above[i] + below[i];
                    max_idx_u = i;
                }
            }

            int max_val_d = 0;
            int max_idx_d = 0;
            // Going down
            for (int i = 0; i < n; i++) {
                int val = n + 1 - above[i] - below[i];
                if (val > max_val_d) {
                    max_val_d = val;
                    max_idx_d = i;
                }
            }

            if (max_val_u > max_val_d) {
                for (int i = 0; i <= max_idx_u; i++) {
                    cout << floor(median) << " ";
                }
                for (int i = max_idx_u + 1; i < n; i++) {
                    cout << ceil(median) << " ";
                }
            } else {
                for (int i = 0; i <= max_idx_d; i++) {
                    cout << ceil(median) << " ";
                }
                for (int i = max_idx_d + 1; i < n; i++) {
                    cout << floor(median) << " ";
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                cout << a[n / 2] << " ";
            }
        }

        cout << "\n";
    }
}
