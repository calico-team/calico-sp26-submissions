#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 0) return;

    vector<long long> L(n), R(n);
    L[0] = a[0];
    R[0] = a[0];

    for (int i = 1; i < n; i++) {
        long long vals[4] = {L[i - 1], R[i - 1], a[i], a[i]};
        sort(vals, vals + 4);
        L[i] = vals[1];
        R[i] = vals[2];
    }

    vector<long long> b(n);
    b[n - 1] = L[n - 1]; 
    for (int i = n - 2; i >= 0; i--) {
        b[i] = max(L[i], min(R[i], b[i+1]));
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