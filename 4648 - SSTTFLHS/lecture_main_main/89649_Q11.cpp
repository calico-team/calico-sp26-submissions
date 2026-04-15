#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int N, M, K;
vector<string> grid;
vector<vector<int>> aura;
vector<pair<int, int>> seats;

bool check(int D, vector<pair<int, int>>& res) {
    int sz = seats.size();
    for (int mask = 0; mask < (1 << sz); mask++) {
        int cnt = 0;
        for (int i = 0; i < sz; i++) {
            if (mask & (1 << i)) cnt++;
        }
        if (cnt != K) continue;
        vector<pair<int, int>> cur;
        for (int i = 0; i < sz; i++) {
            if (mask & (1 << i)) cur.push_back(seats[i]);
        }
        int maxd = 0;
        for (int i = 0; i < cur.size(); i++) {
            for (int j = i + 1; j < cur.size(); j++) {
                int d = abs(cur[i].first - cur[j].first) + abs(cur[i].second - cur[j].second);
                if (d > maxd) maxd = d;
            }
        }
        if (maxd <= D) {
            res = cur;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        grid.resize(N);
        for (int i = 0; i < N; i++) cin >> grid[i];
        seats.clear();
        aura.assign(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            int left = 0;
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '#') left++;
                else aura[i][j] = left;
            }
            int right = 0;
            for (int j = M - 1; j >= 0; j--) {
                if (grid[i][j] == '#') right++;
                else aura[i][j] = min(aura[i][j], right);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '-') seats.push_back(make_pair(i, j));
            }
        }
        int lo = 0, hi = N + M, bestD = N + M;
        vector<pair<int, int>> best;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<pair<int, int>> tmp;
            if (check(mid, tmp)) {
                bestD = mid;
                best = tmp;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        long long bestAura = LLONG_MAX;
        vector<pair<int, int>> ans;
        int sz = seats.size();
        for (int mask = 0; mask < (1 << sz); mask++) {
            int cnt = 0;
            for (int i = 0; i < sz; i++) {
                if (mask & (1 << i)) cnt++;
            }
            if (cnt != K) continue;
            vector<pair<int, int>> cur;
            for (int i = 0; i < sz; i++) {
                if (mask & (1 << i)) cur.push_back(seats[i]);
            }
            int maxd = 0;
            for (int i = 0; i < cur.size(); i++) {
                for (int j = i + 1; j < cur.size(); j++) {
                    int d = abs(cur[i].first - cur[j].first) + abs(cur[i].second - cur[j].second);
                    if (d > maxd) maxd = d;
                }
            }
            if (maxd != bestD) continue;
            long long sum = 0;
            for (int p = 0; p < cur.size(); p++) sum += aura[cur[p].first][cur[p].second];
            if (sum < bestAura) {
                bestAura = sum;
                ans = cur;
            }
        }
        for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}