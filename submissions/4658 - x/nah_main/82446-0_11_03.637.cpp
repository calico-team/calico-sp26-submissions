#include <iostream>

using namespace std;

int main() {
    int T, N, i;
    long long P, R, K, E;
    cin >> T;

    while (T--) {
        cin >> N >> P >> R >> K;

        for (i = 1; i <= N; i++) {
            cin >> E;
            if (P >= 0) {
                P -= E;
                if (P >= 0 && i % K == 0) P += R; 
            }
        }
        cout << (P >= 0 ? "nah i'd win" : "nah i'd lose") << endl;
    }
    return 0;
}