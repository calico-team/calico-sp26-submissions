#include <bits/stdc++.h>
using namespace std;

struct frac {
    long long num;
    long long den;
};

frac result;

void add_frac(frac prob) {
    long long resNum = (result.num * prob.den) + (prob.num * result.den);
    long long resDen = result.den * prob.den;

    long long common = gcd(resNum, resDen);
    result = {resNum / common, resDen / common};
}

frac multiply_frac(frac f1, frac f2) {
    long long resNum = f1.num * f2.num;
    long long resDen = f1.den * f2.den;

    long long common = gcd(resNum, resDen);
    return {resNum / common, resDen / common};
}

void bash(int i, int j, int n, int m, vector<string>& grid, frac prob) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        add_frac(prob);
        return;
    }

    char curr_tile = grid[i][j];
    if (curr_tile == '<') {
        bash(i, j - 1, n, m, grid, prob);
    }
    else if (curr_tile == '>') {
        bash(i, j + 1, n, m, grid, prob);
    }
    else if (curr_tile == '^') {
        bash(i - 1, j, n, m, grid, prob);
    }
    else if (curr_tile == 'v') {
        bash(i + 1, j, n, m, grid, prob);
    }
    else if (curr_tile == 'S') {
        // up, down, left, right
        bool up = i > 0 && (grid[i - 1][j] == 'X' || grid[i - 1][j] == '<' || grid[i - 1][j] == '>' || grid[i - 1][j] == '^');
        bool down = i < n - 1 && (grid[i + 1][j] == 'X' || grid[i + 1][j] == '<' || grid[i + 1][j] == '>' || grid[i + 1][j] == 'v');
        bool left = j > 0 && (grid[i][j - 1] == 'X' || grid[i][j - 1] == '<' || grid[i][j - 1] == 'v' || grid[i][j - 1] == '^');
        bool right = j < m - 1 && (grid[i][j + 1] == 'X' || grid[i][j + 1] == 'v' || grid[i][j + 1] == '>' || grid[i][j + 1] == '^');
        vector<bool> can_go = {up, down, left, right};
        int num_ways = 0;
        for (bool go : can_go) {
            if (go) {
                num_ways += 1;
            }
        }

        frac new_prob = multiply_frac(prob, frac{1, num_ways});
        if (can_go[0]) {
            bash(i - 1, j, n, m, grid, new_prob);
        }
        
        if (can_go[1]) {
            bash(i + 1, j, n, m, grid, new_prob);
        }
        
        if (can_go[2]) {
            bash(i, j - 1, n, m, grid, new_prob);
        }
        
        if (can_go[3]) {
            bash(i, j + 1, n, m, grid, new_prob);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m;
        cin >> n >> m;

        vector<string> grid;
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            grid.push_back(row);
        }

        result = {0, 1};
        bash(0, 0, n, m, grid, frac{1, 1});
        cout << result.num << " " << result.den << "\n";
    }
}