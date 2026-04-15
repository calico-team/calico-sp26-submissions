#include <bits/stdc++.h>
using namespace std;
pair<int, int> red(pair<int, int> a) {
  int x = __gcd(a.first, a.second);
  return {a.first / x, a.second / x};
}
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
  int num = a.first * b.second + b.first * a.second, den = a.second * b.second;
  return red({num, den});
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<string> vs(n);
    for (auto &a : vs)
      cin >> a;

    vector<vector<int>> deg(n, vector<int>(m));
    const string all = "v<^>", ok = "^>v<";
    const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k], nj = j + dy[k];

          if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
              (all[k] == vs[ni][nj] ||
               (vs[ni][nj] == 'S' && ok[k] != vs[i][j]))) {
            deg[i][j]++;
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // cout << deg[i][j] << " ";
      }
      // cout << '\n';
    }

    vector<vector<vector<pair<int, int>>>> st(
        n, vector<vector<pair<int, int>>>(m));
    st[0][0].push_back({1, 1});

    queue<pair<int, int>> qa4;
    qa4.push({0, 0});
    while (!qa4.empty()) {
      auto [x, y] = qa4.front();
      qa4.pop();

      pair<int, int> pii = st[x][y][0];
      for (int i = 1; i < st[x][y].size(); i++) {
        pii = add(pii, st[x][y][i]);
      }

      // cout << x << " " << y << " " << pii.first << " " << pii.second << "\n";

      if (vs[x][y] == 'S') {
        vector<pair<int, int>> vpii;
        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i], ny = y + dy[i];

          if (nx >= 0 && nx < n && ny >= 0 && ny < m && all[i] != vs[nx][ny] &&
              vs[nx][ny] != '.') {
            vpii.emplace_back(nx, ny);
          }
        }

        for (auto [x, y] : vpii) {
          // cout << "S " << x << " " << y << "\n";
          st[x][y].emplace_back(red({pii.first, pii.second * vpii.size()}));
          if (st[x][y].size() == deg[x][y]) {
            qa4.push({x, y});
          }
        }
      } else if (vs[x][y] != 'X') {
        int in = find(ok.begin(), ok.end(), vs[x][y]) - ok.begin();

        int nx = x + dx[in], ny = y + dy[in];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          st[nx][ny].emplace_back(pii);
          if (st[nx][ny].size() == deg[nx][ny]) {
            qa4.push({nx, ny});
          }
        } else {
          cout << pii.first << " " << pii.second << "\n";
          goto A;
        }
      }
    }
    cout << "0 1\n";
  A:;
  }
}
