#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
const long long INF = (long long)4e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int N;
        cin >> N;
        vector<int> v(N), v2;
        for (int i = 0; i < N; i++) {
            cin >> v[i];
            v2.push_back(v[i]);
        }
        sort(v2.begin(), v2.end());
        v2.erase(unique(v2.begin(), v2.end()), v2.end());
        int M = v2.size();
        vector<vector<pair<long long, int>>> dp(
            N, vector<pair<long long, int>>(M, {INF, -1})
        );
        for (int j = 0; j < M; j++) {
            dp[0][j] = {abs(v[0] - v2[j]), -1};
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    long long cost =
                        dp[i - 1][k].first +
                        abs(v2[j] - v2[k]) +
                        abs(v[i] - v2[j]);

                    if (cost < dp[i][j].first) {
                        dp[i][j] = {cost, k};
                    }
                }
            }
        }
        long long best = INF;
        int idx = 0;
        for (int j = 0; j < M; j++) {
            if (dp[N - 1][j].first < best) {
                best = dp[N - 1][j].first;
                idx = j;
            }
        }
        vector<int> ans(N);
        for (int i = N - 1; i >= 0; i--) {
            ans[i] = v2[idx];
            idx = dp[i][idx].second;
            if (idx == -1) idx = 0;
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << (i + 1 < N ? " " : "");
        }
        cout << endl;
    }
}
