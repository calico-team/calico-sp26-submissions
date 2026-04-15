#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> L(n), R(n);
    L[0] = R[0] = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < L[i - 1]) {
            L[i] = a[i];
            R[i] = L[i - 1];
        } else if (a[i] > R[i - 1]) {
            L[i] = R[i - 1];
            R[i] = a[i];
        } else {
            L[i] = a[i];
            R[i] = a[i];
        }
    }

    vector<long long> b(n);
    b[n - 1] = L[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        b[i] = max(L[i], min(b[i + 1], R[i]));
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}