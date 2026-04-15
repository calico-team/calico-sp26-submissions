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
 
vector<pair<int, int>> solve(int N, int M, int K, vector<string>& GRID) {
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
 
    int S = (int)seats.size();
    if (S == 0) return {};
 
    vector<int> U(S), V(S);
    for (int i = 0; i < S; i++) {
        U[i] = seats[i].first + seats[i].second;
        V[i] = seats[i].first - seats[i].second;
    }
 
    vector<int> byU(S);
    iota(byU.begin(), byU.end(), 0);
    sort(byU.begin(), byU.end(), [&](int a, int b){ return U[a] < U[b]; });
 
    vector<int> byV(S);
    iota(byV.begin(), byV.end(), 0);
    sort(byV.begin(), byV.end(), [&](int a, int b){ return V[a] < V[b]; });
 
    int bestAura = INT_MAX;
    int bestD = INT_MAX;
    vector<int> bestIdx;
 
    for (int ul = 0; ul < S; ul++) {
        for (int ur = ul; ur < S; ur++) {
            int uMin = U[byU[ul]], uMax = U[byU[ur]];
            int uRange = uMax - uMin;
            vector<pair<int,int>> vWindow;
            for (int i = ul; i <= ur; i++)
                vWindow.push_back({V[byU[i]], byU[i]});
            sort(vWindow.begin(), vWindow.end());
 
            int sz = (int)vWindow.size();
            if (sz < K) continue;
 
            for (int r2 = K-1; r2 < sz; r2++) {
                while (r2 - l2 + 1 > K) l2++;
                int vRange = vWindow[r2].first - vWindow[l2].first;
                int D = max(uRange, vRange);
 
                if (D < bestD || (D == bestD)) {
                    // compute aura
                    vector<pair<int,int>> cands;
                    for (int i = l2; i <= r2; i++)
                        cands.push_back({aura[vWindow[i].second], vWindow[i].second});
                    sort(cands.begin(), cands.end());
                    int totalAura = 0;
                    for (int i = 0; i < K; i++) totalAura += cands[i].first;
 
                    if (D < bestD || (D == bestD && totalAura < bestAura)) {
                        bestD = D;
                        bestAura = totalAura;
                        bestIdx.clear();
                        for (int i = 0; i < K; i++) bestIdx.push_back(cands[i].second);
                    }
                }
                l2++;
            }
        }
    }
 
    vector<pair<int,int>> ans;
    for (int i : bestIdx) ans.push_back(seats[i]);
    return ans;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> GRID(N);
        for (int i = 0; i < N; i++) {
            cin >> GRID[i];
        }
        vector<pair<int, int>> result = solve(N, M, K, GRID);
        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
 