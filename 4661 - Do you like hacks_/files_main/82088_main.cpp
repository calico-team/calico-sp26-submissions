/**
 * @author n685
 * @date Saturday, April 11, 2026 7:12:52 PM
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

void tc() {
  std::string a, b;
  std::cin >> a >> b;

  int ind = 0;
  for (char& c : a) {
    if (ind == (int)b.size() || b[ind] != c)
      c = '#';
    else
      ++ind;
  }
  std::cout << a << '\n';
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
