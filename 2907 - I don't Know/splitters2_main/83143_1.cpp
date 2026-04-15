#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, R, K, E, count = 0;
        long long P;
        cin >> N >> P >> R >> K;
        
        bool ok = true;
        while (N--) {
            cin >> E;
            if (ok) {
                P -= E;
                if (P < 0) {
                    ok = false;
                } else if (++count == K) {
                    P += R;
                    count = 0;
                }
            }
        }
        
        cout << (ok ? "nah i'd win" : "nah i'd lose") << endl;
    }
    return 0;
}