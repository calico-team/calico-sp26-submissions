#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<long long, long long> solve(int N, vector<string>& S1, vector<string>& S2) {
    vector<int> row(N, 0), col(N, 0);

    for (int y = 0; y < N; y++) {
        for (int z = 0; z < N; z++) {
            if (S1[y][z] == '#') row[y] = 1;
        }
    }

    for (int x = 0; x < N; x++) {
        for (int z = 0; z < N; z++) {
            if (S2[x][z] == '#') col[x] = 1;
        }
    }

    long long max_vol = 0;
    for (int x = 0; x < N; x++) {
        if (!col[x]) continue;
        for (int y = 0; y < N; y++) {
            if (!row[y]) continue;
            for (int z = 0; z < N; z++) {
                if (S1[y][z] == '#' && S2[x][z] == '#') {
                    max_vol++;
                }
            }
        }
    }

    long long min_vol = 0;
    vector<vector<int>> r1(N, vector<int>(N, 0));
    vector<vector<int>> r2(N, vector<int>(N, 0));

    for (int y = 0; y < N; y++)
        for (int z = 0; z < N; z++)
            if (S1[y][z] == '#') r1[y][z] = 1;

    for (int x = 0; x < N; x++)
        for (int z = 0; z < N; z++)
            if (S2[x][z] == '#') r2[x][z] = 1;

    for (int z = 0; z < N; z++) {
        vector<int> ys, xs;
        for (int y = 0; y < N; y++)
            if (r1[y][z]) ys.push_back(y);
        for (int x = 0; x < N; x++)
            if (r2[x][z]) xs.push_back(x);

        int k = max(ys.size(), xs.size());
        min_vol += k;
    }

    return {max_vol, min_vol};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<string> S1(N), S2(N);
        for (int i = 0; i < N; i++) cin >> S1[i];
        for (int i = 0; i < N; i++) cin >> S2[i];

        pair<long long, long long> ans = solve(N, S1, S2);
        cout << ans.first << " " << ans.second << "\n";
    }
}