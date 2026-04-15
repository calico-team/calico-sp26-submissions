#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        vector<long long> b(N);
        if (N == 1) {
            b[0] = A[0];
        } else if (N == 2) {
            b[0] = A[0];
            b[1] = A[1];
        } else {
            b[0] = A[0];
            b[N-1] = A[N-1];
            for (int i = 1; i < N-1; ++i) {
                long long arr[3] = {A[i-1], A[i], A[i+1]};
                sort(arr, arr + 3);
                b[i] = arr[1];
            }
        }
        for (int i = 0; i < N; ++i) {
            cout << b[i] << (i + 1 == N ? '\n' : ' ');
        }
    }

    return 0;
}