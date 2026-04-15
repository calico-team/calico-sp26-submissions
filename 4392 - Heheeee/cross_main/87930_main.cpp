// PROBLEM 5:
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;
// #define ll long long
//
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//
//     int T;
//     cin >> T;
//     while (T--) {
//         int n;
//         cin >> n;
//
//         vector<ll> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }
//
//         vector<int> b(n);
//         ll total = 0;
//         for (int i = 0; i < n - 1; ++i) {
//             total += abs(a[i] - a[i + 1]);
//         }
//
//         ll total2 = INT64_MAX, total3 = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 total3 += abs(a[i] - a[j]);
//             }
//
//             if (total3 < total2) {
//                 total2 = total3;
//                 for (int j = 0; j < n; ++j) {
//                     b[j] = a[i];
//                 }
//             }
//         }
//
//         if (total * 2 < total2) {
//             for (int i = 0; i < n; ++i) {
//                 b[i] = a[i];
//             }
//         }
//
//         for (int i = 0; i < n; ++i) {
//             cout << b[i] << ' ';
//         }
//         cout << '\n';
//     }
//
//     return 0;
// }






// PROBLEM 7:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> v(1000, vector<int>(1000));
    for (int i = 0; i < 1000; ++i) {
        if (i % 5 == 0) {
            for (int j = 0; j < 1000; ++j) {
                v[i][j] = (j + 4) % 5;
            }
        }
        else if (i % 5 == 1) {
            for (int j = 0; j < 1000; ++j) {
                v[i][j] = (j + 1) % 5;
            }
        }
        else if (i % 5 == 2) {
            for (int j = 0; j < 1000; ++j) {
                v[i][j] = (j + 3) % 5;
            }
        }
        else if (i % 5 == 3) {
            for (int j = 0; j < 1000; ++j) {
                v[i][j] = j % 5;
            }
        }
        else if (i % 5 == 4) {
            for (int j = 0; j < 1000; ++j) {
                v[i][j] = (j + 2) % 5;
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}