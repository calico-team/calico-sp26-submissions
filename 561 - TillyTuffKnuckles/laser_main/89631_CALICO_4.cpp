#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            int K, N, M, P, Q;
            cin >> K >> N >> M >> P >> Q;
            M -= 1;
            N -= 1;
            int first_x, first_y;
            cin >> first_x >> first_y;
            pair<int, int> l = {first_x, first_y};
            set<pair<int, int>> asts;
            vector<pair<int, int>> asts_ord;
            asts.insert(l);
            asts_ord.push_back(l);
            int x = l.first;
            int y = l.second;
            l = {(((x + P) % M) + M) % M, (((y + Q) % N) + N) % N};
            for (int i = 0; i < K - 1; ++i) {
                int kx, ky;
                cin >> kx >> ky;
                pair<int, int> k = {kx, ky};
                asts_ord.push_back(k);
                asts.insert(k);
            }
            while (asts.find(l) == asts.end()) {
                x = l.first;
                y = l.second;
                if (x + P == M) {
                    x = -P;
                }
                if (y + Q == N) {
                    y = -Q;
                }
                l = {(((x + P) % M) + M) % M, (((y + Q) % N) + N) % N};
            }
            auto it = find(asts_ord.begin(), asts_ord.end(), l);
            cout << distance(asts_ord.begin(), it) << "\n";
        }
    }
    return 0;
}