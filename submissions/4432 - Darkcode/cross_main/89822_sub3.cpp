#include <iostream>
using namespace std;

void build_grid(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << (i + j) % 5;
            if (j != M - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        build_grid(N, M);
    }

    return 0;
}