#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int T;
    if (!(cin >> T)) return;
    
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        if (N == 1) {
            cout << A[0] << "\n";
            continue;
        }
        
        vector<long long> L_arr(N), R_arr(N);
        long long L = A[0], R = A[0];
        L_arr[0] = R_arr[0] = A[0];
        
        // Forward pass
        for (int i = 1; i < N; i++) {
            long long a = A[i];
            if (a < L) {
                R = L;
                L = a;
            } else if (a > R) {
                L = R;
                R = a;
            } else {
                L = R = a;
            }
            L_arr[i] = L;
            R_arr[i] = R;
        }
        
        vector<long long> b(N);
        b[N - 1] = L_arr[N - 1]; 
        
        // Backwards pass
        for (int i = N - 2; i >= 0; i--) {
            if (b[i + 1] < L_arr[i]) {
                b[i] = L_arr[i];
            } else if (b[i + 1] > R_arr[i]) {
                b[i] = R_arr[i];
            } else {
                b[i] = b[i + 1];
            }
        }
        
        for (int i = 0; i < N; i++) {
            cout << b[i] << (i == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
