/*
ID: connorl3   
TASK: measurement
LANG: C++17
*/


#include <bits/stdc++.h>

#include <iostream>
#include <array>
#include <fstream>
#include <set>
#include <tuple>
#include <map>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <utility>
#include <random>
#include <cstdlib>
#include <sstream>

using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto& x : arr) cin >> x;

    vector<long long> v(arr.begin(), arr.end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int newN = v.size();

    long long INF = 2e18;
    vector<vector<long long>> dp(n, vector<long long>(newN, INF));
    vector<vector<int>> p(n, vector<int>(newN, -1));
    for (int i = 0; i < newN; i++)
        dp[0][i] = abs(arr[0] - v[i]);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < newN; j++)
            for (int k = 0; k < newN; k++) {
                long long c = dp[i-1][k] + abs(v[k] - v[j]) + abs(arr[i] - v[j]);
                if (c < dp[i][j]) { dp[i][j] = c; p[i][j] = k; }
            }

    int best = min_element(dp[n-1].begin(), dp[n-1].end()) - dp[n-1].begin();
    vector<int> path(n);
    path[n-1] = best;
    for (int i = n-1; i > 0; i--) path[i-1] = p[i][path[i]];

    for (int i = 0; i < n; i++) {
        cout << v[path[i]];
        if (i < n-1) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
