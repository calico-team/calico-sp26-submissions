#include <iostream>
#include <vector>
using namespace std;

string solve(int N, int P, int R, int K, vector<int> E) {
    int c = 0;
    for (int i = 0; i < N; i++){
        while (c && P < E[i]) P += R, c--;
        P -= E[i];
        if (P < 0) return "nah i’d lose";
        if (!((i + 1) % K)) c++;
    }
    return "nah i’d win";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
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