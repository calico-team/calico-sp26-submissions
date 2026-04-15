#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        if (N <= 3) {
            for (int i = 0; i < N; i++) {
                cout << A[i] << (i == N - 1 ? "" : " ");
            }
            cout << "\n";
        } else {
            vector<long long> sortedA = A;
            sort(sortedA.begin(), sortedA.end());
            long long median = sortedA[N / 2];
            for (int i = 0; i < N; i++) {
                cout << median << (i == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}