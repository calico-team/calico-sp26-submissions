#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<long long> b(N);
        b[0] = A[0];
        b[N-1] = A[N-1];
        for (int i = 1; i < N-1; i++) {
            vector<long long> triplet = {A[i-1], A[i], A[i+1]};
            sort(triplet.begin(), triplet.end());
            b[i] = triplet[1];
        }
        for (int i = 0; i < N; i++) {
            cout << b[i] << (i == N-1 ? "\n" : " ");
        }
    }

    return 0;
}