#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    if (N > 1000 || N < 3)
    {
        cout << "N is not within the valid range.\n";
        return;
    }

    if (M > 1000 || M < 3)
    {
        cout << "M is not within the valid range.\n";
        return;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
 
            int val = (2 * i + j) % 5;
            cout << val << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {

    int T;
    bool sig = true;
    while (sig) {
        if (cin >> T) {
            if (T > 10 || T < 1)
            {
                cout << "T is not within the valid range.\n";
                continue;
            }
            sig = false;
            while (T--) {
                solve();
            }
        }
    }
    return 0;
}