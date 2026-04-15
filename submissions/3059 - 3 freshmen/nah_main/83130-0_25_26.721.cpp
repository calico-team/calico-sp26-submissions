#include <iostream>
#include <vector>

using namespace std;


string solve(int N, int P, int R, int K, vector<int> E) {
	int def = 0;
    bool ok=1;
    for (int i = 0; i < N; i ++) {
        P -= E[i];
        if (P < 0) {
            ok=0;
            
        }
        def++;
        if (def >= K) {
            def -= K;
            P += R;
        }
    }
    if (ok) {
        return "nah i’d win";
    }
    return "nah i’d lose";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, P, R, K;
		cin >> N >> P >> R >> K;
		vector<int> E(N);
		for (int j = 0; j < N; j++) {
			cin >> E[j];
		}
        cout << solve(N, P, R, K, E) << '\n';
    }
}
