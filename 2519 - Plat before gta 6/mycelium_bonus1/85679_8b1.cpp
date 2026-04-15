#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <iomanip>
#include <array>
#include <functional>
#include <bitset>
using namespace std;

void baseIO(string s = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (s.size()){
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

// #define int long long
#define all(x) (x).begin(), (x).end()

const int mull = 5000;

void solve(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // x1 += 500, y1 += 500, x2 += 500, y2 += 500;

    int ans = 0;

    unordered_map<int, int> tp;
    tp[mull * x1 + y1] = 1;
    tp[mull * x2 + y2] = 2;

    queue<pair<int, int>> q, Q;
    q.push({x1, y1});
    Q.push({x2, y2});

    while (!Q.empty()) {
        // grass
        for (int i = 0; i < 3; i++) {
            queue<pair<int, int>> q2;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (!tp[mull * (x - 1) + y]) tp[mull * (x - 1) + y] = 1, q2.push({x - 1, y});
                if (!tp[mull * x + y - 1]) tp[mull * x + y - 1] = 1, q2.push({x, y - 1});
                if (!tp[mull * (x + 1) + y]) tp[mull * (x + 1) + y] = 1, q2.push({x + 1, y});
                if (!tp[mull * x + y + 1]) tp[mull * x + y + 1] = 1, q2.push({x, y + 1});
            }

            q = q2;
        }
        // other
        queue<pair<int, int>> Q2;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();

            ans++;

            if (!tp[mull * (x - 1) + y]) tp[mull * (x - 1) + y] = 2, Q2.push({x - 1, y});
            if (!tp[mull * x + y - 1]) tp[mull * x + y - 1] = 2, Q2.push({x, y - 1});
            if (!tp[mull * (x + 1) + y]) tp[mull * (x + 1) + y] = 2, Q2.push({x + 1, y});
            if (!tp[mull * x + y + 1]) tp[mull * x + y + 1] = 2, Q2.push({x, y + 1});
        }

        Q = Q2;

        // grass
        for (int i =  0; i < 4; i++) {
            queue<pair<int, int>> q2;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (!tp[mull * (x - 1) + y]) tp[mull * (x - 1) + y] = 1, q2.push({x - 1, y});
                if (!tp[mull * x + y - 1]) tp[mull * x + y - 1] = 1, q2.push({x, y - 1});
                if (!tp[mull * (x + 1) + y]) tp[mull * (x + 1) + y] = 1, q2.push({x + 1, y});
                if (!tp[mull * x + y + 1]) tp[mull * x + y + 1] = 1, q2.push({x, y + 1});
            }

            q = q2;
        }
        // other
        queue<pair<int, int>> Q3;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();

            ans++;

            if (!tp[mull * (x - 1) + y]) tp[mull * (x - 1) + y] = 2, Q3.push({x - 1, y});
            if (!tp[mull * x + y - 1]) tp[mull * x + y - 1] = 2, Q3.push({x, y - 1});
            if (!tp[mull * (x + 1) + y]) tp[mull * (x + 1) + y] = 2, Q3.push({x + 1, y});
            if (!tp[mull * x + y + 1]) tp[mull * x + y + 1] = 2, Q3.push({x, y + 1});
        }

        Q = Q3;
    }

    cout << ans;
}

signed main() {
    baseIO();

    int t;
    cin >> t;
    while (t--){
        solve(), cout << '\n';
    }

    return 0;
}