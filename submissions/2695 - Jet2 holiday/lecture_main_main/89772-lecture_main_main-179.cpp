#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> g(N);
        for (int i = 0; i < N; i++) {
            cin >> g[i];
        }

        vector<pair<int, int>> res;
        for (int i = 0; i < N && res.size() < K; i++) {
            for (int j = 0; j < M && res.size() < K; j++) {
                if (g[i][j] == '-') {
                    res.emplace_back(i, j);
                }
            }
        }

        for (auto& p : res) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}