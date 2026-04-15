#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<int> b(n);

        int L = A[0], R = A[0];
        int start = 0;

        for (int i = 1; i < n; i++) {
            int l = min(A[i-1], A[i]);
            int r = max(A[i-1], A[i]);

            if (max(L, l) <= min(R, r)) {
                L = max(L, l);
                R = min(R, r);
            } else {
                for (int j = start; j < i; j++) {
                    b[j] = L;
                }


                L = l;
                R = r;
                start = i;
            }
        }

        for (int j = start; j < n; j++) {
            b[j] = L;
        }

        for (int x : b) cout << x << " ";
        cout << "\n";
    }
}