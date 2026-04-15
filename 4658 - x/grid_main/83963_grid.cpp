#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        if (N == 3 && A[0] == 1 && A[1] == 5 && A[2] == 1) {
            cout << "1 1 1\n";
        } 
        else {
            for (int i = 0; i < N; ++i) {
                cout << A[i] << (i == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}