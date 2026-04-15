#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
*/

void dfs(pair<ll, ll> prob, int r, int c, vector<string>& factory, vector<vector<pair<ll, ll>>>& grid, vector<vector<bool>>& visited) {
    if((r < 0 || r >= factory.size() || c < 0 || c >= factory[0].length())) return;
    visited[r][c] = true;
    grid[r][c].first = grid[r][c].first * prob.second + grid[r][c].second * prob.first;
    grid[r][c].second *= prob.second;
    ll div = __gcd(grid[r][c].first, grid[r][c].second);
    grid[r][c].first /= div;
    grid[r][c].second /= div;

    if(factory[r][c] == '^') dfs(prob, r - 1, c, factory, grid, visited);
    if(factory[r][c] == '>') dfs(prob, r, c + 1, factory, grid, visited);
    if(factory[r][c] == 'v') dfs(prob, r + 1, c, factory, grid, visited);
    if(factory[r][c] == '<') dfs(prob, r, c - 1, factory, grid, visited);
    if(factory[r][c] == 'S') {
        int paths = 0;
        if(r + 1 < factory.size() && factory[r + 1][c] != '^' && factory[r + 1][c] != '.') paths++;
        if(r - 1 >= 0 && factory[r - 1][c] != 'v' && factory[r - 1][c] != '.') paths++;
        if(c + 1 < factory[0].size() && factory[r][c + 1] != '<' && factory[r][c + 1] != '.') paths++;
        if(c - 1 >= 0 && factory[r][c - 1] != '>' && factory[r][c - 1] != '.') paths++;

        if(r + 1 < factory.size() && factory[r + 1][c] != '^' && factory[r + 1][c] != '.') dfs({prob.first, prob.second * paths}, r + 1, c, factory, grid, visited);
        if(r - 1 >= 0 && factory[r - 1][c] != 'v' && factory[r - 1][c] != '.') dfs({prob.first, prob.second * paths}, r - 1, c, factory, grid, visited);
        if(c + 1 < factory[0].size() && factory[r][c + 1] != '<' && factory[r][c + 1] != '.') dfs({prob.first, prob.second * paths}, r, c + 1, factory, grid, visited);
        if(c - 1 >= 0 && factory[r][c - 1] != '>' && factory[r][c - 1] != '.') dfs({prob.first, prob.second * paths}, r, c - 1, factory, grid, visited);
    }
}

pair<long long, long long> solve(int N, int M, vector<string>& factory) {
    // YOUR CODE HERE
    vector<vector<pair<ll, ll>>> grid(N, vector<pair<ll, ll>>(M, {0, 1}));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    dfs({1, 1}, 0, 0, factory, grid, visited);
    pair<ll, ll> ans = {0, 1};
    for(int i = 0; i < N; i++) {
        if(factory[i][0] == '<') {
            ans = grid[i][0];
            break;
        }
        if(factory[i][M - 1] == '>') {
            ans = grid[i][M - 1];
            break;
        }
    }
    for(int i = 0; i < M; i++) {
        if(factory[0][i] == '^') {
            ans = grid[0][i];
            break;
        }
        if(factory[N - 1][i] == 'v') {
            ans = grid[N - 1][i];
            break;
        }
    }
    ll div = __gcd(ans.first, ans.second);
    ans.first /= div;
    ans.second /= div;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> factory(N);
        for (int i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = solve(N, M, factory);
        cout << P << " " << Q << "\n";
    }
    return 0;
}
