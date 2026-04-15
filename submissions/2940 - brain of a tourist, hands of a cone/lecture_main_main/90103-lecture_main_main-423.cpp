/**
 *    author:  tourist
 *    created: 11.04.2026 23:05:30
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
      cin >> s[i];
    }
    vector g(h + w - 1, vector<int>(h + w - 1, -1));
    for (int i = 0; i < h; i++) {
      int cs = int(count(s[i].begin(), s[i].end(), '#'));
      int lft = 0;
      for (int j = 0; j < w; j++) {
        if (s[i][j] == '#') {
          lft += 1;
        } else {
          int val = min(lft, cs - lft);
          g[i + j][i + (w - 1) - j] = val;
        }
      }
    }
    vector f(h + w, vector<int>(h + w));
    for (int i = 0; i < h + w - 1; i++) {
      for (int j = 0; j < h + w - 1; j++) {
        f[i + 1][j + 1] = f[i + 1][j] + f[i][j + 1] - f[i][j] + int(g[i][j] >= 0);
      }
    }
    int low = 0, high = h + w - 1;
    while (low + 1 < high) {
      int mid = (low + high) >> 1;
      bool found = false;
      for (int i = 0; i <= h + w - 1 - mid; i++) {
        for (int j = 0; j <= h + w - 1 - mid; j++) {
          int sum = f[i + mid][j + mid] - f[i][j + mid] - f[i + mid][j] + f[i][j];
          found |= (sum >= k);
        }
      }
      if (found) {
        high = mid;
      } else {
        low = mid;
      }
    }
    int mid = high;
    vector<pair<int, int>> res;
    for (int i = 0; i <= h + w - 1 - mid; i++) {
      for (int j = 0; j <= h + w - 1 - mid; j++) {
        int sum = f[i + mid][j + mid] - f[i][j + mid] - f[i + mid][j] + f[i][j];
        if (res.empty() && sum >= k) {
          for (int ii = i; ii < i + mid; ii++) {
            for (int jj = j; jj < j + mid; jj++) {
              if (g[ii][jj] >= 0) {
                int x = (ii + jj - (w - 1)) / 2;
                int y = ii - x;
                if (int(res.size()) < k) {
                  res.emplace_back(x, y);
                }
              }
            }
          }
          assert(int(res.size()) == k);
        }
      }
    }
    assert(int(res.size()) == k);
    for (auto& [x, y] : res) {
      cout << x << " " << y << '\n';
    }
  }
  return 0;
}
