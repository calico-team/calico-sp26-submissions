#include <bits/stdc++.h>
using namespace std;

/*
 * M: number of rows in the lecture hall
 * N: number of columns in the lecture hall
 * K: number of friends who need seats
 * GRID: vector of M strings of length N; '#' is a blocked seat, '-' is an empty seat
 *
 * Return a vector of K (row, col) pairs for the chosen seats.
 */
vector<pair<int, int>> solve(int M, int N, int K, vector<string>& GRID) {
    vector<pair<int,int>> seats;
    vector<int> aura;

    for (int r = 0; r < M; r++) {
        int totalOcc = 0;
        for (int c = 0; c < N; c++)
            if (GRID[r][c] == '#') totalOcc++;
        int leftOcc = 0;
        for (int c = 0; c < N; c++) {
            if (GRID[r][c] == '-') {
                aura.push_back(min(leftOcc, totalOcc - leftOcc));
                seats.push_back({r, c});
            } else {
                leftOcc++;
            }
        }
    }

    int S = seats.size();
    vector<pair<int,int>> transformed;
    for (auto& [r, c] : seats) transformed.push_back({r+c, r-c});

    auto feasible = [&](int D) -> vector<int> {
        vector<int> order(S);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return transformed[a].first < transformed[b].first;
        });

        int bestAura = INT_MAX;
        vector<int> best;

        int left = 0;
        for (int right = 0; right < S; right++) {
            while (transformed[order[right]].first - transformed[order[left]].first > D)
                left++;

            vector<pair<int,int>> vs;
            for (int i = left; i <= right; i++)
                vs.push_back({transformed[order[i]].second, order[i]});
            sort(vs.begin(), vs.end());

            int l2 = 0;
            for (int r2 = 0; r2 < (int)vs.size(); r2++) {
                while (vs[r2].first - vs[l2].first > D) l2++;
                if (r2 - l2 + 1 >= K) {
                    vector<pair<int,int>> cands;
                    for (int i = l2; i <= r2; i++)
                        cands.push_back({aura[vs[i].second], vs[i].second});
                    sort(cands.begin(), cands.end());
                    int total = 0;
                    for (int i = 0; i < K; i++) total += cands[i].first;
                    if (total < bestAura) {
                        bestAura = total;
                        best.clear();
                        for (int i = 0; i < K; i++) best.push_back(cands[i].second);
                    }
                }
            }
        }
        return best;
    };

    int lo = 0, hi = (M - 1) + (N - 1);
    vector<int> bestIdx;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        auto res = feasible(mid);
        if (!res.empty()) {
            bestIdx = res;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    vector<pair<int,int>> ans;
    for (int i : bestIdx) ans.push_back(seats[i]);
    return vector<pair<int, int>>(K, {0, 0});
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<string> GRID(M);
        for (int i = 0; i < M; i++) {
            cin >> GRID[i];
        }
        vector<pair<int, int>> result = solve(M, N, K, GRID);
        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
