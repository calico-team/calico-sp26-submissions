/**
 * @author n685
 * @date Saturday, April 11, 2026 7:48:45 PM
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "dd/debug.h"
#else
#define dbg(...) 67
#define dbg_proj(...) 67
#define dbg_rproj(...) 67
void nline() {}
void bar() {}
void start_clock() {}
void end_clock() {}
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

#ifndef TEMPL_INF_H
#define TEMPL_INF_H


template <class T> constexpr T INF = T{};
template <> constexpr double INF<double> = std::numeric_limits<double>::infinity();
template <> constexpr long double INF<long double> = std::numeric_limits<long double>::infinity();
template <> constexpr int INF<int> = 0x3f3f3f3f; // 1061109567
template <> constexpr long long INF<long long> = 0x3f3f3f3f3f3f3f3fLL; // 4557430888798830399

#endif // TEMPL_INF_H

constexpr std::array<int, 4> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};

struct F {
  i64 a = 0, b = 1;
};
F operator+(F lhs, F rhs) {
  i64 l = std::lcm(lhs.b, rhs.b);
  lhs.a *= l / lhs.b;
  rhs.a *= l / rhs.b;
  F res{lhs.a + rhs.a, l};
  i64 g = std::gcd(res.a, res.b);
  res.a /= g;
  res.b /= g;
  return res;
}
F operator/(F lhs, i64 v) { return F{lhs.a, lhs.b * v}; }
std::map<char, int> dir{{'^', 0}, {'>', 1}, {'v', 2}, {'<', 3}};

void tc() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> gr(n);
  for (std::string& v : gr)
    std::cin >> v;

  std::vector<std::vector<int>> adj(n * m + 1);
  std::vector<int> indeg(n * m + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (gr[i][j] == '.' || gr[i][j] == 'X')
        continue;
      if (gr[i][j] == 'S') {
        for (int d = 0; d < 4; ++d) {
          int nx = i + dx[d];
          int ny = j + dy[d];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m || gr[nx][ny] == '.' || (gr[nx][ny] != 'X' && dir[gr[nx][ny]] == (d + 2) % 4))
            continue;
          adj[m * i + j].push_back(m * nx + ny);
          ++indeg[m * nx + ny];
        }
      } else {
        int d = dir[gr[i][j]];
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
          adj[m * i + j].push_back(n * m);
          ++indeg[n * m];
        } else {
          adj[m * i + j].push_back(m * nx + ny);
          ++indeg[m * nx + ny];
        }
      }
    }
  }

  std::vector<F> dp(n * m + 1);
  dp[0] = F{1, 1};
  std::queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    int sz = (int)adj[node].size();
    for (int i : adj[node]) {
      dp[i] = dp[i] + dp[node] / sz;
      if (--indeg[i] == 0)
        q.push(i);
    }
  }

  for (int i = 0; i < n * m; ++i) {
    std::cerr << i << ' ' << dp[i].a << ' ' << dp[i].b << '\n';
  }

  std::cout << dp[n * m].a << ' ' << dp[n * m].b << '\n';
}

int main() {
#ifndef LOCAL
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
#endif

  int t;
  std::cin >> t;
  for (int i = 1; i <= t; ++i) {
    dbg(i);
    tc();
    bar();
  }
}
