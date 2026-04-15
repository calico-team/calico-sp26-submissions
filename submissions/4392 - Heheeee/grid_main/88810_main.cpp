// PROBLEM 5:
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long

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
            total3 = 0;
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

        ll total4 = 0;
        for (int i = 0; i < n; ++i) {
            total4 = 0;
            for (int j = i; j < n; ++j) {
                total4 += abs(a[i] - a[j]);
                for (int k = 0; k < n; ++k) {
                    total4 += abs(a[0] - a[i]) + abs(a[1] - a[i]) + abs(a[2] - a[j]);
                }
                if (total4 < total2) {
                    total2 = total4;
                    for (int k = 0; k < n; ++k) {
                        b[0] = a[i];
                        b[1] = a[i];
                        b[2] = a[j];
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            total4 = 0;
            for (int j = i; j < n; ++j) {
                total4 += abs(a[i] - a[j]);
                for (int k = 0; k < n; ++k) {
                    total4 += abs(a[0] - a[i]) + abs(a[1] - a[j]) + abs(a[2] - a[i]);
                }
                if (total4 < total2) {
                    total2 = total4;
                    for (int k = 0; k < n; ++k) {
                        b[0] = a[i];
                        b[1] = a[j];
                        b[2] = a[i];
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            total4 = 0;
            for (int j = i; j < n; ++j) {
                total4 += abs(a[i] - a[j]);
                for (int k = 0; k < n; ++k) {
                    total4 += abs(a[0] - a[j]) + abs(a[1] - a[i]) + abs(a[2] - a[i]);
                }
                if (total4 < total2) {
                    total2 = total4;
                    for (int k = 0; k < n; ++k) {
                        b[0] = a[j];
                        b[1] = a[i];
                        b[2] = a[i];
                    }
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