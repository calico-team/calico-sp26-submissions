#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long A[3];
        for (int i = 0; i < N; i++) cin >> A[i];
        long long b[3];

        if (N == 1) {
            b[0] = 1;
        }
        else if (N == 2) {
            b[0] = A[0];
            b[1] = A[1];
        }
        else if (N == 3) {
            long long cand[5] = {A[0], A[1], A[2], (A[0]+A[1])/2, (A[1]+A[2])/2};
            long long best_cost = 1e18;
            long long best_b[3];
            for (int i0 = 0; i0 < 5; i0++){
                for (int i1 = 0; i1 < 5; i1++){
                    for (int i2 = 0; i2 < 5; i2++) {
                        long long b0 = cand[i0], b1 = cand[i1], b2 = cand[i2];
                        long long cost = abs(A[0]-A[1]) + abs(A[1]-A[2]) + abs(b0-b1) + abs(b1-b2) + abs(A[0]-b0) + abs(A[1]-b1) + abs(A[2]-b2);

                        if (cost < best_cost) {
                            best_cost = cost;
                            best_b[0] = b0; best_b[1] = b1; best_b[2] = b2;
                        }
                    }
                }
            }
            
            b[0] = best_b[0]; b[1] = best_b[1]; b[2] = best_b[2];
        }

        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << ' ';
            cout << b[i];
        }
        cout << '\n';
    }
    return 0;
}