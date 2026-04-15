/*
ID: connorl3   
TASK: measurement
LANG: C++17
*/


// #include <bits/stdc++.h>

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

vector<vector<int>> makeGrid(int n, int m) {
    vector<vector<int>> grid(n, vector<int>(m));
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            grid[r][c] = (2*r + c) % 5;
    return grid;
}

void solve() {
    int n, m;
    cin >> n >> m;
    auto grid = makeGrid(n, m);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cout << grid[r][c] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
