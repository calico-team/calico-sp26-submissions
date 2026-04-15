#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        // forward pass
        B[0] = A[0];
        for (int i = 1; i < N; i++) {
            if (A[i] > B[i-1]) B[i] = B[i-1] + 1;
            else if (A[i] < B[i-1]) B[i] = B[i-1] - 1;
            else B[i] = B[i-1];
        }
        // backward pass
        for (int i = N - 2; i >= 0; i--) {
            if (B[i] > B[i+1]) B[i] = B[i+1];
        }
        for (int i = 0; i < N; i++) {
            cout << B[i] << (i + 1 == N ? '\n' : ' ');
        }
    }
}