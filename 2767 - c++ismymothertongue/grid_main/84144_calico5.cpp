#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> topRow(n);
    for (int i = 0; i < n; i++) {
        cin >> topRow[i];
    }

    if (n == 0) {
        cout << "\n";
        return;
    }

    vector<long long> sortedRow = topRow;
    sort(sortedRow.begin(), sortedRow.end());

    long long median = sortedRow[n / 2];

    for (int i = 0; i < n; i++) {
        cout << median << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    if (cin >> testCases) {
        while (testCases--) {
            solve();
        }
    }
    return 0;
}