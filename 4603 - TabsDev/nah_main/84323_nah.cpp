#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

string solve(int N, int P, int R, int K, vector<int>& E) {
    int hp = P;
    for (int i = 0; i < N; i++) {
        hp -= E[i];
        if (hp < 0) return "nah i'd lose";
        if ((i + 1) % K == 0) hp += R;
    }
    return "nah i'd win";
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> E(N);
        for (int i = 0; i < N; i++) cin >> E[i];
        cout << solve(N, P, R, K, E) << "\n";
    }
    return 0;
}