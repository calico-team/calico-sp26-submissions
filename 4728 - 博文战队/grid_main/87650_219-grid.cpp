#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> solve(int N, vector<ll>& A) {
    return A;
}

void read_your_input() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        vector<ll> B = solve(N, A);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << ' ';
            cout << B[i];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    read_your_input();
    return 0;
}
