/**
 * @author n685
 * @date Saturday, April 11, 2026 8:26:11 PM
 */
#include <iterator>
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

void tc() {
  i64 p;
  int a, b;
  std::cin >> p >> a >> b;

  std::vector<int> mul, sp;
  int aa = a, bb = b;
  while (aa > 0 || bb > 0) {
    if (aa > 0) {
      mul.push_back(p % 2);
      sp.push_back(2);
      --aa;
      p /= 2;
    } else {
      mul.push_back(p % 3);
      sp.push_back(3);
      --bb;
      p /= 3;
    }
  }
  std::reverse(mul.begin(), mul.end());
  std::reverse(sp.begin(), sp.end());

  std::vector gr(2 * (a + b) + 1, std::string(5, '.'));
  gr[0] = ">>v.^";
  for (int i = 1; i < 2 * (a + b); ++i)
    gr[i][0] = 'v';
  for (int i = 0; i < 2 * (a + b); i += 2)
    gr[i][2] = 'v';
  for (int i = 1; i < 2 * (a + b); i += 2)
    gr[i][2] = 'S';
  for (int i = 1; i < 2 * (a + b); ++i)
    gr[i][4] = '^';
  gr[2 * (a + b)] = ">>>>^";

  for (int i = 0; i < a + b; ++i) {
    int r = 2 * i + 1;
    if (sp[i] == 2)
      gr[r][3] = mul[i] > 0 ? '>' : 'X';
    else {
      gr[r][3] = mul[i] > 0 ? '>' : 'X';
      gr[r][1] = mul[i] > 1 ? '<' : 'X';
    }
  }

  std::cout << 2 * (a + b) + 1 << ' ' << 5 << '\n';
  for (const std::string& v : gr)
    std::cout << v << '\n';
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
