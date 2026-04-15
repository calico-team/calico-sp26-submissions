#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(n);
        ll total = 0;
        for (int i = 0; i < n - 1; ++i) {
            total += abs(a[i] - a[i + 1]);
        }

        ll total2 = INT64_MAX, total3 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                total3 += abs(a[i] - a[j]);
            }
            if (total3 < total2) {
                total2 = total3;
                for (int j = 0; j < n; ++j) {
                    b[j] = a[i];
                }
            }
        }

        if (total * 2 < total2) {
            for (int i = 0; i < n; ++i) {
                b[i] = a[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}