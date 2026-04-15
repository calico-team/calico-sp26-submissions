#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <math.h>
#include <queue>
#include <iomanip>
#include <map>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <cstdint>
#include <assert.h>
#include <limits.h>
#include <unordered_map>
#include <memory>
#include <istream>
#include <deque>

using ll = long long;

using namespace std;

int main() {
    //ifstream cin("a.in");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> ans(N, vector<int>(M, 0));
        int cur = 0;
        for (int i = 0; i < N; i++) {
            if (i != 0) {
                cur = (ans[i - 1][0] + 2) % 5;
            }
            for (int j = 0; j < M; j++) {
                cout << cur << " ";
                ans[i][j] = cur;
                cur++;
                cur %= 5;
            }
            cout << endl;
        }
    }
}