#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << A[0];
        for (int i = 1; i < N; i++) {
            cout << " " << A[i];
        }
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}