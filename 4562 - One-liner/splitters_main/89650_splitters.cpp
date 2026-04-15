// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <utility>
using namespace std;

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
 */

int lcm_list(initializer_list<int> list) {
    if (list.size() == 0) return 0;
    return accumulate(list.begin() + 1, list.end(), *list.begin(), [](int a, int b) {
        return lcm(a, b);
    });
}

vector<int> runUntilSplitter(int x, int y, vector<string> factory) {
    int j = x; int i = y;
    vector<vector<int>> nums;
    while (factory[i][j] != 'S') {
        if (factory[i][j] == 'X') {
            return {0, 1};
        }
        if (factory[i][j] == '^') {
            if (i == 0) {
                return {1, 1};
            }
            i--;
        }
        if (factory[i][j] == '>') {
            if (j == factory[0].size() - 1) {
                return {1, 1};
            }
            j++;
        }
        if (factory[i][j] == 'v') {
            if (i == factory.size() - 1) {
                return {1, 1};
            }
            i++;
        }
        if (factory[i][j] == '<') {
            if (j == 0) {
                return {1, 1};
            }
            j--;
        }
    }
    if (factory[i - 1][j] != '.' && factory[i - 1][j] != 'v') {
        nums.push_back(runUntilSplitter(j, i - 1, factory));
    }
    if (factory[i + 1][j] != '.' && factory[i + 1][j] != '^') {
        nums.push_back(runUntilSplitter(j, i + 1, factory));
    }
    if (factory[i][j - 1] != '.' && factory[i][j - 1] != '>') {
        nums.push_back(runUntilSplitter(j - 1, i, factory));
    }
    if (factory[i][j + 1] != '.' && factory[i][j + 1] != '<') {
        nums.push_back(runUntilSplitter(j + 1, i, factory));
    }
    int denom = 1;
    int numer = 0;
    for (int index = 0; index < nums.size(); index++) {
        denom *= nums[index][1];
    }
    for (int index = 0; index < nums.size(); index++) {
        numer += nums[index][0] * (denom / nums[index][1]);
    }
    denom *= nums.size();
    return {numer / gcd(numer, denom), denom / gcd(numer, denom)};
}

pair<long long, long long> solve(int N, int M, vector<string>& factory) {
    // YOUR CODE HERE
    if (factory[0][0] == 'X') {
        return {0, 1};
    }

    long long num = 1;
    long long denom = 1;

    auto ans = runUntilSplitter(0, 0, factory);

    return make_pair(ans[0] / gcd(ans[0], ans[1]), ans[1] / gcd(ans[0], ans[1]));
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
